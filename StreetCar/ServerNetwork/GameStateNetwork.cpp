#include "GameStateNetwork.h"
#include "../Shared/PileTarget.h"
#include "../Shared/ResponsePlayerRefresh.h"

using namespace std;

GameStateNetwork::GameStateNetwork()
{
    start = false;
    won = false;
    travelStarted = false;
    // creation of the pile
    gameBoard = new Board();

    gameBoard->initEmpty();
    //ofstream fileOut(".txt", ios::out | ios::app);
    //fileOut << *gameBoard;
    //fileOut.close();
    nbrPlayer = 0;
    players.clear();
    prodConsCommon = new ProdCons<Pack*>();
}

GameStateNetwork::~GameStateNetwork()
{
    //dtor
}

int GameStateNetwork::getNbrPlayer(){
    return nbrPlayer;
}
int GameStateNetwork::getCurrentPlayer(){
    return currentPlayer;
}
int GameStateNetwork::getLastTravelLength(){
    return lastTravelLength;
}
bool GameStateNetwork::getStart(){
    return start;
}
bool GameStateNetwork::getWon(){
    return won;
}
bool GameStateNetwork::getPileWhenTravel(){
    return pileWhenTravel;
}
std::vector<PlayerServerNetwork*> GameStateNetwork::getPlayers(){
    return players;
}
PlayerServerNetwork *GameStateNetwork::getPlayer(int position){
    return players[position];
}
Pile<Tile*> GameStateNetwork::getPileTile(){
    return pileTile;
}
Pile<int> GameStateNetwork::getPileLine(){
    return pileLine;
}
Pile<Card> GameStateNetwork::getPileCardStation(){
    return pileCardStation;
}
bool GameStateNetwork::getTravelStarted(){
    return travelStarted;
}
vector<ProdCons<Pack*> *> GameStateNetwork::getCircularQueueClient(){
    return circularQueueClient;
}

void GameStateNetwork::setNbrPlayer(int nbr){
    nbrPlayer = nbr;
}
void GameStateNetwork::setCurrentPlayer(int currentP){
    currentPlayer = currentP;
}
void GameStateNetwork::setLastTravelLength(int travelLengh){
    lastTravelLength = travelLengh;
}
void GameStateNetwork::setStart(bool begin){
    start = begin;
}
void GameStateNetwork::setWon(bool win){
    won = win;
}
void GameStateNetwork::setPileWhenTravel(bool pileTravel){
    pileWhenTravel = pileTravel;
}
void GameStateNetwork::setPlayers(std::vector<PlayerServerNetwork*> p){
    players = p;
}
void GameStateNetwork::setPileTile(Pile<Tile*> p){
    pileTile = p;
}
void GameStateNetwork::setPileLine(Pile<int> p){
    pileLine = p;
}
void GameStateNetwork::setPileCardStation(Pile<Card> p){
    pileCardStation = p;
}
void GameStateNetwork::setTravelStarted(bool travel){
    travelStarted = travel;
}

void GameStateNetwork::setCircularQueueClient(vector<ProdCons<Pack*> *> prod){
    circularQueueClient = prod;
}


void GameStateNetwork::initThread(){
    delete prodConsCommon;
    prodConsCommon = new ProdCons<Pack*>();

    for (unsigned int i = 0; i<players.size(); i++){
	players[i]->circularQueue->produce(new Quit());
    }

    for (int i = 0; i<players.size(); i++){
	prodConsOutputClient[i] = new ProdCons<Pack*>();
	//players.push_back(prodConsOutputClient[i]);
	delete players[i]->circularQueue;
	players[i]->circularQueue = prodConsOutputClient[i];
	ParamThread paramThread = {prodConsOutputClient[i],prodConsCommon,players[i]->sockfd,&players[i]->serv_addr, &players[i]->cli_addr};
	if (pthread_create(&client[i], NULL, clientOutputHandlerNetwork,(void *)(&paramThread))==0){
	    cout << "SN: End of event thread client " << i << endl;
	}else
	    cout << "SN: ERROR, impossible to create client " << i << endl;
    }

    cout << "SN :end of initThread" << endl;

}

// initialisation of players and nbrplayers
void GameStateNetwork::initialization()
{    
    profiles.clear();
    Pack * pack;
    while (!start){
	pack = prodConsCommon->consume();
	cout << "SN: POC " << pack->toString() << " - " << *pack <<   endl;
	switch(pack->idPack){
	case IWANTPLAYNETWORK:
	    {
		IWantPlayNetwork *p = (IWantPlayNetwork*)pack;
		if (players.size() >= nbrPlayer){
		    //TODO MESSAGE ERROR
		    cout << "SN: to much players" << endl;
		    Validation *v = new Validation(GAME_FULL);
		    players.back()->circularQueue->produce(v);
		}else{
		    //players.push_back(p->prodConsClient);
		    //NewPlayerAdd *np = new NewPlayerAdd(p->profile, profiles.size());

		    PlayerServerNetwork *currentP = new PlayerServerNetwork(p->prodConsClient,p->sockfd, p->serv_addr, p->cli_addr);
		    players.push_back(currentP);

		    players.back()->circularQueue->produce(new ResponsePlayerRefresh(profiles));

		    profiles.push_back(p->profile);
		    
		    //cout << "SN: Nom du joueur entré : " << p->profile.name << endl;
		    //cout << "SN: nombre de joueur " << players.size()-1 << endl;

		    players.back()->setMyIdPlayer(players.size()-1);
		    //cout << "SN: numero du joueur : " << players.back()->getMyIdPlayer() << endl;
		    players.back()->getProfile() = p->profile;
		    //cout << "SN: nom du joueur : " << players.back()->getProfile().name << endl;
		    //cout << "SN: profile ajouté !! " << endl;

		    players.back()->circularQueue->produce(new YourIdPlayer(players.size()-1));
		    //		    players[nbrPlayer]->profile = p->profile;
		    //players[nbrPlayer]->isTravelling = false;
		    for (unsigned int i = 0; i<players.size(); i++){
			//cout << "prodCons player " << i << " - " << players[i]->circularQueue << endl;
			players[i]->circularQueue->produce(new NewPlayerAdd(p->profile, profiles.size()));
		    }
		}
	    }
	    break;
	case STARTGAME:
	    cout << "S:  STARTGAME " << endl;
	    start = true;
	    break;
	case REFRESHPLAYERGAME:
	    {
		ResponsePlayerRefresh *rpf = new ResponsePlayerRefresh(profiles);
		for (unsigned int i = 0; i<players.size(); i++)
		    players[i]->circularQueue->produce(rpf);
	    }
	    break;
	case QUIT:
	    {
		cout << "SN:  ---------------------- I WILL QUIT THE SOCKET " << endl;
		for (unsigned int i = 0; i<players.size(); i++){
		    Quit *q = new Quit();
		    cout << "SN: Envoi quit aux thread" << endl;
		    players[i]->circularQueue->produce(q);

		}
		sleep(3);
		exit(0);
		break;
	    }
	default:
	    break;
	}
	delete pack;
    }

}

// initialisation of the game to start playing
void GameStateNetwork::gameInit()
{
    initThread();

    int pTile[12] = {36,30,6,4,10,10,10,6,6,4,2,2};
    //initialization to pile of Tile & pile of Station
    for (int i=0; i<12; i++){
	for (int j = 0; j<pTile[i]; j++){
	    Tile *t = new Tile((idTile)i);
	    pileTile.push(t,1); //,pTile[i]);
	}
    } 

    for (int i=0; i<NBR_CARD_STATION; i++){
	Card c = Card(i);
	pileCardStation.push(c,1);
    }
    for (int i=0; i<NBR_LINE; i++){
	pileLine.push(i,1);
    }

    //randomisation of two pile
    pileTile.wrap();
    pileCardStation.wrap();
    pileLine.wrap();

    // this is the hands we will sand for the pack
    vector<vector<Tile> > hands(nbrPlayer, vector<Tile>(HAND_SIZE));
    vector <GoalPlayer> goals(nbrPlayer);
    hands.clear();
    goals.clear();

    /* choose line for Player
       + creation of hand's Player */
    for (int i=0; i<players.size(); i++){
	Card c = pileCardStation.take();
	int line = pileLine.take();

	cout << "SN: take line : " << line << endl;

	GoalPlayer gp = (GoalPlayer){c,line};
	goals.push_back(gp);
	players[i]->setLine(line);
	vector<Tile> h;
	h.clear();
	for (int j=0; j<HAND_SIZE; j++){
	    players[i]->setHand(pileTile.take(),j);
	    players[i]->getHand(j)->setPlayer(i);
	    h.push_back(*players[i]->getHand(j));
	}
	hands.push_back(h);
    }

    //	  PileTarget stopCards = PileTarget();
    lastTravelLength = 0;

    currentPlayer = rand() % nbrPlayer;
    for (int i = 0; i<players.size(); i++){
	players[i]->circularQueue->produce(new Goal(i,goals[i]));
    }
    for (int i = 0; i<players.size(); i++){
	players[i]->circularQueue->produce(new InitGame(hands, currentPlayer));
    }
    cout << "SN:	 * * * * * * GAME INITIALISE * * * * * * " << endl;

}

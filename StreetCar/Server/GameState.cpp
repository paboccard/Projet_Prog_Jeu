#include "GameState.h"
#include "../Shared/PileTarget.h"


using namespace std;

GameState::GameState()
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

GameState::~GameState()
{
    //dtor
}

void GameState::initThread(){
    connexion = new Connexion();

    for (int i = 0; i<PULLPLAYER; i++){
        prodConsOutputClient[i] = new ProdCons<Pack*>();
        ParamThread paramThread = {prodConsOutputClient[i],prodConsCommon,connexion->sockfd,&connexion->serv_addr, &connexion->cli_addr};
        if (pthread_create(&client[i], NULL, clientOutputHandler,(void *)(&paramThread))==0){
            cout << "End of event thread client " << i << endl;
        }else
            cout << "ERROR, impossible to create client " << i << endl;
	}
}

int GameState::getNbrPlayer(){
    return nbrPlayer;
}
int GameState::getCurrentPlayer(){
    return currentPlayer;
}
int GameState::getLastTravelLength(){
    return lastTravelLength;
}
bool GameState::getStart(){
    return start;
}
bool GameState::getWon(){
    return won;
}
bool GameState::getPileWhenTravel(){
    return pileWhenTravel;
}
std::vector<PlayerServer*> GameState::getPlayers(){
    return players;
}
PlayerServer *GameState::getPlayer(int position){
    return players[position];
}
Pile<Tile>* GameState::getPileTile(){
    return &pileTile;
}
Pile<int>* GameState::getPileLine(){
    return &pileLine;
}
Pile<Card>* GameState::getPileCardStation(){
    return &pileCardStation;
}
bool GameState::getTravelStarted(){
    return travelStarted;
}
vector<ProdCons<Pack*> *> GameState::getCircularQueueClient(){
    return circularQueueClient;
}

void GameState::setNbrPlayer(int nbr){
    nbrPlayer = nbr;
}
void GameState::setCurrentPlayer(int currentP){
    currentPlayer = currentP;
}
void GameState::setLastTravelLength(int travelLengh){
    lastTravelLength = travelLengh;
}
void GameState::setStart(bool begin){
    start = begin;
}
void GameState::setWon(bool win){
    won = win;
}
void GameState::setPileWhenTravel(bool pileTravel){
    pileWhenTravel = pileTravel;
}
void GameState::setPlayers(std::vector<PlayerServer*> p){
    players = p;
}
void GameState::setPileTile(Pile<Tile> p){
    pileTile = p;
}
void GameState::setPileLine(Pile<int> p){
    pileLine = p;
}
void GameState::setPileCardStation(Pile<Card> p){
    pileCardStation = p;
}
void GameState::setTravelStarted(bool travel){
    travelStarted = travel;
}

void GameState::setCircularQueueClient(vector<ProdCons<Pack*> *> prod){
    circularQueueClient = prod;
}

// initialisation of players and nbrplayers
void GameState::initialization()
{    
    Pack * pack;
    int nbThread = -1;
    int nbrMax = -1;
    NewPlayerAdd *np;
    while (!start){

	pack = prodConsCommon->consume();
        switch(pack->idPack){
        case IWANTPLAY:
	    {
		IWantPlay *p = (IWantPlay*)pack;
		if (nbrPlayer == nbrMax){
		    //TODO MESSAGE ERROR
		    cout << "to much players" << endl;
		    Validation *v = new Validation(GAME_FULL);
		    circularQueueClient.back()->produce(v);
		}else{
		    nbrPlayer++;
		    np = new NewPlayerAdd(p->profile, nbrPlayer-1);
		    PlayerServer *currentP = new PlayerServer(circularQueueClient.back());
		    players.push_back(currentP);

 		    cout << "Nom du joueur entré : " << p->profile.name << endl;
		    cout << "nombre de joueur " << players.size()-1 << endl;

		    players.back()->setMyIdPlayer(nbrPlayer-1);
		    cout << "numero du joueur : " << players.back()->getMyIdPlayer() << endl;
		    players.back()->getProfile() = p->profile;
		    cout << "nom du joueur : " << players.back()->getProfile().name << endl;
		    cout << "profile ajouté !! " << endl;

		    players.back()->circularQueue->produce(new YourIdPlayer(players.size()-1));
		    //		    players[nbrPlayer]->profile = p->profile;
		    //players[nbrPlayer]->isTravelling = false;
		    for (unsigned int i = 0; i<circularQueueClient.size(); i++)
			circularQueueClient[i]->produce(np);
		}
	    }
            break;
        case STARTGAME:
	    cout << " STARTGAME " << endl;
            start = true;
            break;
        case CIRCULARQUEUECLIENT:
	    {
		cout << "CircularQueueClient" << endl;
		CircularQueueClient *c = (CircularQueueClient*)pack;
		//PlayerServer *ps = new PlayerServer(c->prodConsClient);
		circularQueueClient.push_back(c->prodConsClient);
		nbThread++;
	    }
            break;
        case CREATEGAME:
	    {
		CreateGame *c = (CreateGame*)pack;
		nbrMax = c->nbrPlayer;
		cout << "nombre max de player : " << nbrMax << endl;
	    }
	    break;
	case DEBUG:
	    {
		Debug *d = new Debug("Message_bien_reçu");
		circularQueueClient[nbThread]->produce(d);
	    }
	    break;
	case QUIT:
	    {
		cout << " ---------------------- I WILL QUIT THE SOCKET " << endl;
		for (unsigned int i = 0; i<circularQueueClient.size(); i++){
		    Quit *q = new Quit();
		    cout << "Envoi quit aux thread" << endl;
		    circularQueueClient[i]->produce(q);

		}
		// for (unsigned int i = 0; i<circularQueueClient.size(); i++){
		//     pthread_join(client[i], NULL);
		// }

		// for (int i = 0; i<PULLPLAYER; i++){
		//     pthread_cancel(client[i]);
		//     pthread_join(client[i], NULL);
		// } 
		close(connexion->sockfd);
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
void GameState::gameInit()
{
    int pTile[12] = {36,30,6,4,10,10,10,6,6,4,2,2};
    //initialization to pile of Tile & pile of Station
    for (int i=0; i<12; i++){
	Tile t = Tile((idTile)i);
	pileTile.push(t,pTile[i]);
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
	Card* c = pileCardStation.take();
	int* line = pileLine.take();
	GoalPlayer gp = (GoalPlayer){*c,*line};
	goals.push_back(gp);
	players[i]->setLine(*line);
	vector<Tile> h;
	h.clear();
	for (int j=0; j<HAND_SIZE; j++){
	    players[i]->setHand(pileTile.take(),j);
	    h.push_back(*players[i]->getHand(j));
	}
	hands.push_back(h);
    }

    //    PileTarget stopCards = PileTarget();
    lastTravelLength = 0;

    // this will contain the stop cards of the players
    
    
    // we will pick the lines :
    // vector<int> lines;
    // for (int i = 0; i < NBR_LINES; i++)
    //     lines.push_back(i+1);

    // we scan all players registered for the game
    //for (int i = 0; i < nbrPlayer; i++){
        // we pick a stop card
	
        //cout << "+++ " << i << endl;
	//   goals[i].stop = stopCards.take();
        //cout << "take stop " << goals[i].stop << endl;
        // we pick a line for the player i
        //int indexLine = rand()%lines.size();
        //goals[i].line = lines[indexLine];
        //cout << "take line " << goals[i].line << endl;
        //lines.erase(lines.begin() + (indexLine));
        // then we set the players' tiles one by one
        //cout << "erease" << endl;
        // for (int j = 0; j < HAND_SIZE; j++){
        //     GameState::players[i]->hand[j] = Tile(GameState::pile.take(),i);
        //     hands[i][j] = players[i]->hand[j];
        // }
    //}
    // we chose the first player
    
    currentPlayer = rand() % nbrPlayer;
    for (int i = 0; i<players.size(); i++){
	players[i]->circularQueue->produce(new Goal(i,goals[i]));
    }
    for (int i = 0; i<circularQueueClient.size(); i++){
	InitGame *initGame = new InitGame(hands, currentPlayer);
        circularQueueClient[i]->produce(initGame);
    }
    cout << " * * * * * * GAME INITIALISE * * * * * * " << endl;

}

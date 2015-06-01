#include "GameState.h"
#include "../Shared/PileTarget.h"


using namespace std;

GameState::GameState()
{
    start = false;
    won = false;
    travelStarted = false;
    // creation of the pile
    gameBoard = Board();
    nbrPlayer = -1;
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

// initialisation of players and nbrplayers
void GameState::initialization()
{
    Pack * pack;
    int nbrMax = -2;
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
		}else{
		    nbrPlayer++;
		    np = new NewPlayerAdd(p->profile, nbrPlayer);
		    PlayerServer *currentP = new PlayerServer();

 		    cout << "Nom du joueur entré : " << p->profile.name << endl;
		    cout << "nombre de joueur " << players.size() << endl;

		    players[nbrPlayer]->myIdPlayer = nbrPlayer;
		    cout << "numero du joueur : " << players[nbrPlayer]->myIdPlayer << endl;
		    players[nbrPlayer]->profile = p->profile;
		    cout << "nom du joueur : " << players[nbrPlayer]->profile.name << endl;
		    cout << "profile ajouté !! " << endl;

		    players[nbrPlayer]->circularQueue->produce(new YourIdPlayer(nbrPlayer));
		    //		    players[nbrPlayer]->profile = p->profile;
		    //players[nbrPlayer]->isTravelling = false;
		    for (unsigned int i = 0; i<players.size(); i++)
			players[i]->circularQueue->produce(np);
		}
	    }
            break;
        case STARTGAME:
            start = true;
            break;
        case CIRCULARQUEUECLIENT:
	    {
		cout << "CircularQueueClient" << endl;
		CircularQueueClient *c = (CircularQueueClient*)pack;
		PlayerServer *ps = new PlayerServer(c->prodConsClient);
		players.push_back(ps);
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
		for (unsigned int i = 0; i<players.size(); i++)
		    players[i]->circularQueue->produce(d);
	    }
	case QUIT:
	    {
		Quit *q = new Quit();
		cout << " ---------------------- I WILL QUIT THE SOCKET " << endl;
		for (unsigned int i = 0; i<players.size(); i++)
		    players[i]->circularQueue->produce(q);
		for (int i = 0; i<PULLPLAYER; i++)
		    pthread_cancel(client[i]);
		close(connexion->sockfd);
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

    // this is the hands we will sand for the pack
    vector<vector<Tile> > hands(nbrPlayer, vector<Tile>(HAND_SIZE));
    vector <GoalPlayer> goals(nbrPlayer);
    hands.clear();
    goals.clear();

    /* choose line for Player
       + creation of hand's Player */
    for (int i=0; i<nbrPlayer; i++){
	Card c = pileCardStation.take();
	int line = pileLine.take();
	GoalPlayer gp = (GoalPlayer){c,line}
	goals.push_back(gp);
	players[i].line = line;
	vector<Tile> h;
	h.clear();
	for (int j=0; j<HAND_SIZE; j++){
	    players[i].hand[j] = pileTile.take();
	    h.push_back(players[i].hand[j]);
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
    cout << " * * * * * Je suis dans l'initialisation du game" << endl;
    for (int i = 0; i<nbrPlayer; i++){
        InitGame *initGame = new InitGame(hands, currentPlayer, goals[i]);
        players[i]->circularQueue->produce(initGame);
    }
}

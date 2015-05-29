#include "GameState.h"
#include "../Shared/PileTarget.h"


using namespace std;

GameState::GameState(Connexion co)
{
    connexion = co;
    start = false;
    won = false;
    travelStarted = false;
    // creation of the pile
    pile = Pile();
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
       for (int i = 0; i<PULLPLAYER; i++){
        prodConsOutputClient[i] = new ProdCons<Pack*>();
        ParamThread paramThread = {prodConsOutputClient[i],prodConsCommon,connexion.sockfd,&connexion.serv_addr, &connexion.cli_addr};
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
    int nbrMax;
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
		    for (int i = 0; i<PULLPLAYER; i++)
			pthread_cancel(client[i]);
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
    PileTarget stopCards = PileTarget();
    lastTravelLength = 0;

    // this is the hands we will sand for the pack
    vector<vector<Tile> > hands(nbrPlayer, vector<Tile>(HAND_SIZE));
    // this will contain the stop cards of the players
    vector <GoalPlayer> goals(nbrPlayer);

    // we will pick the lines :
    vector<int> lines;
    for (int i = 0; i < NBR_LINES; i++)
        lines.push_back(i+1);

    // we scan all players registered for the game
    for (int i = 0; i < nbrPlayer; i++){
        // we pick a stop card
        goals[i].stop = stopCards.take();
        // we pick a line for the player i
        goals[i].line = lines[rand()%lines.size()];
        lines.erase(lines.begin() + (goals[i].line - 1));
        // then we set the players' tiles one by one
        for (int j = 0; j < HAND_SIZE; j++){
            GameState::players[i]->hand[j] = Tile(GameState::pile.take(),i);
            hands[i][j] = players[i]->hand[j];
        }
    }
    // we chose the first player
    currentPlayer = rand() % nbrPlayer;

    for (int i = 0; i<nbrPlayer; i++){
        InitGame initGame = InitGame(hands, pile, currentPlayer, goals[i]);
        players[i]->circularQueue->produce(&initGame);
    }
}

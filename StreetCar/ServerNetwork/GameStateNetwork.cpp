#include "GameStateNetwork.h"
#include "../Shared/PileTarget.h"

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
Pile<Tile>* GameStateNetwork::getPileTile(){
  return &pileTile;
}
Pile<int>* GameStateNetwork::getPileLine(){
  return &pileLine;
}
Pile<Card>* GameStateNetwork::getPileCardStation(){
  return &pileCardStation;
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
void GameStateNetwork::setPileTile(Pile<Tile> p){
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

  for (int i = 0; i<nbrPlayer; i++){
    circularQueueClient.clear();
    prodConsOutputClient[i] = new ProdCons<Pack*>();
    circularQueueClient.push_back(prodConsOutputClient[i]);
    ParamThread paramThread = {prodConsOutputClient[i],prodConsCommon,players[i]->sockfd,&players[i]->serv_addr, &players[i]->cli_addr};
    if (pthread_create(&client[i], NULL, clientOutputHandlerNetwork,(void *)(&paramThread))==0){
      cout << "S: End of event thread client " << i << endl;
    }else
      cout << "S: ERROR, impossible to create client " << i << endl;
  }

}

// initialisation of players and nbrplayers
void GameStateNetwork::initialization()
{    
  Pack * pack;
  NewPlayerAdd *np;
  while (!start){
    pack = prodConsCommon->consume();
    cout << "S: POC " << pack->toString() << " - " << *pack <<   endl;
    switch(pack->idPack){
    case IWANTPLAYNETWORK:
      {
	IWantPlayNetwork *p = (IWantPlayNetwork*)pack;
	if (circularQueueClient.size() >= nbrPlayer){
	  //TODO MESSAGE ERROR
	  cout << "S: to much players" << endl;
	  Validation *v = new Validation(GAME_FULL);
	  circularQueueClient.back()->produce(v);
	}else{
	  circularQueueClient.push_back(p->prodConsClient);
	  np = new NewPlayerAdd(p->profile, nbrPlayer-1);
	  PlayerServerNetwork *currentP = new PlayerServerNetwork(circularQueueClient.back(),p->sockfd, p->serv_addr, p->cli_addr);
	  players.push_back(currentP);

	  cout << "S: Nom du joueur entré : " << p->profile.name << endl;
	  cout << "S: nombre de joueur " << players.size()-1 << endl;

	  players.back()->setMyIdPlayer(players.size()-1);
	  cout << "S: numero du joueur : " << players.back()->getMyIdPlayer() << endl;
	  players.back()->getProfile() = p->profile;
	  cout << "S: nom du joueur : " << players.back()->getProfile().name << endl;
	  cout << "S: profile ajouté !! " << endl;

	  players.back()->circularQueue->produce(new YourIdPlayer(players.size()-1));
	  //		    players[nbrPlayer]->profile = p->profile;
	  //players[nbrPlayer]->isTravelling = false;
	  for (unsigned int i = 0; i<circularQueueClient.size(); i++)
	    circularQueueClient[i]->produce(np);
	}
      }
      break;
    case STARTGAME:
      cout << "S:  STARTGAME " << endl;
      start = true;
      break;
    case QUIT:
      {
	cout << "S:  ---------------------- I WILL QUIT THE SOCKET " << endl;
	for (unsigned int i = 0; i<circularQueueClient.size(); i++){
	  Quit *q = new Quit();
	  cout << "S: Envoi quit aux thread" << endl;
	  circularQueueClient[i]->produce(q);

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

    cout << "S: take line : " << *line << endl;

    GoalPlayer gp = (GoalPlayer){*c,*line};
    goals.push_back(gp);
    players[i]->setLine(*line);
    vector<Tile> h;
    h.clear();
    for (int j=0; j<HAND_SIZE; j++){
      players[i]->setHand(pileTile.take(),j);
      players[i]->getHand(j)->setPlayer(i);
      h.push_back(*players[i]->getHand(j));
    }
    hands.push_back(h);
  }

  //    PileTarget stopCards = PileTarget();
  lastTravelLength = 0;

  currentPlayer = rand() % nbrPlayer;
  for (int i = 0; i<players.size(); i++){
    players[i]->circularQueue->produce(new Goal(i,goals[i]));
  }
  for (int i = 0; i<circularQueueClient.size(); i++){
    InitGame *initGame = new InitGame(hands, currentPlayer);
    circularQueueClient[i]->produce(initGame);
  }
  cout << "S:  * * * * * * GAME INITIALISE * * * * * * " << endl;

}

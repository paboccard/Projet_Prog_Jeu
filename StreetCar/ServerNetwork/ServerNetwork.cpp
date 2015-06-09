#include "../Shared/Connexion.h"
#include "../Shared/ParamThreadClient.h"
#include "../Shared/CreateGameNetwork.h"
#include "../Shared/IWantPlayNetwork.h"
#include "../Shared/RefreshGamesNetwork.h"
#include "../Shared/ResponseRefresh.h"
#include "clientConnexionHandler.h"
#include "ServerHandler.h"

#include <vector>

#define NBR_PLAYER_POSSIBLE 50

using namespace std;

int main(int argc, char *argv[]){
  bool isFinish = false;
  
  Connexion *connexion = new Connexion();
  
  vector<ProdCons<Pack*> *> game;
  vector<ProdCons<Pack*> *> playersConnected;
  vector<GameNetwork> gameNetwork;

  ProdCons<Pack*> *prodConsOutputConnexion[NBR_PLAYER_POSSIBLE];
  ProdCons<Pack*> *prodConsCommon = new ProdCons<Pack*>();
  pthread_t client[NBR_PLAYER_POSSIBLE];

  for (int i = 0; i<NBR_PLAYER_POSSIBLE; i++){
    prodConsOutputConnexion[i] = new ProdCons<Pack*>();
    ParamThread param = {prodConsOutputConnexion[i],prodConsCommon,connexion->sockfd,&connexion->serv_addr, &connexion->cli_addr};
    if (pthread_create(&client[i], NULL, clientOutputConnexionHandler,(void *)(&param))==0){
      cout << "SN: Start of event thread client " << i << endl;
    }else
      cout << "SN: ERROR, impossible to create client " << i << endl;
  }


  while(!isFinish){
    Pack* readPack = prodConsCommon->consume();
  
    switch(readPack->idPack){
    	    case CREATEGAMENETWORK:
		{
		  ProdCons<Pack*> *prodConsServer = new ProdCons<Pack*>(); 
		  game.push_back(prodConsServer);
		  
		  CreateGameNetwork *c = (CreateGameNetwork*)readPack;
		  
		  gameNetwork.push_back((GameNetwork){c->gameNetwork.name, c->gameNetwork.nbrPlayers});
		  playersConnected.push_back(c->prodConsClient);
		  for (unsigned int i = 0; i< playersConnected.size() ; i++)
		      playersConnected[i]->produce(new ResponseRefresh(gameNetwork));

		  pthread_t client;
		  ParamThreadCreateGame param = {prodConsServer,c,game.size()-1};
	  
		  if (pthread_create(&client, NULL, serverHandler,(void *)(&param))==0){
		  }else
		    cout << "SN: ERROR, impossible to create clientInput " << endl;
		}
		break;
	    case IWANTPLAYNETWORK:
		{
		  IWantPlayNetwork* p = (IWantPlayNetwork*)readPack;
		  game[p->numGame]->produce(p);
		}
		break;
	    case REFRESHGAMESNETWORK:
		{
		  RefreshGamesNetwork *r = (RefreshGamesNetwork*)readPack;
		  r->prodConsClient->produce((new ResponseRefresh(gameNetwork)));
		}
		break;
	    default:
		cout << "SN: package unknown" << endl;
		break;
	    }

  }

}

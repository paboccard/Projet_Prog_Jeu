#include "GameState.h"
#include "../Shared/Board.h"
#include "../Shared/Card.h"
#include "../Shared/InitGame.h"
#include "PlayerServer.h"
#include "../Shared/PileTarget.h"
#include "../Shared/Pile.h"
#include "../Shared/Board.h"

using namespace std;

GameState::GameState()
{
    start = false;
    won = false;
    travelStarted = false;
    // creation of the pile
    pile = Pile();
    gameBoard = Board();
}

GameState::~GameState()
{
    //dtor
}

// initialisation of players and nbrplayers
void GameState::Initialization()
{

}

// initialisation of the game to start playing
void GameState::GameInit()
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
            GameState::players[i].hand[j] = Tile(GameState::pile.take(),i);
            hands[i][j] = players[i].hand[j];
        }
    }
    // we chose the first player
    currentPlayer = rand() % nbrPlayer;

    for (int i = 0; i<nbrPlayer; i++){
        InitGame initGame = InitGame(hands, pile, currentPlayer, goals[i]);
        players[i].circularQueue->produce(&initGame);
    }
}

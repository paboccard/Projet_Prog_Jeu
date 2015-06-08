#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H 

#include "../Shared/Pack.h"
#include "../Shared/StartTravel.h"
#include "../Shared/PlayTravel.h"
#include "../Shared/StopTravel.h"
#include "../Shared/PlayTile.h"
#include "../Shared/PileWhenTravel.h"
#include "../Shared/CreateGameNetwork.h"
#include "GameStateNetwork.h"

void sendError(int player, error_pack error, GameStateNetwork *gameState);
void travelStarted(StartTravel *readPack, GameStateNetwork *gameState);
void travelPlayed(PlayTravel *readPack, GameStateNetwork *gameState);
void travelStopped(StopTravel *readPack, GameStateNetwork *gameState);
void tilePlayed(PlayTile *readPack, GameStateNetwork *gameState);
void pilewhentravel(PileWhenTravel *readPack, GameStateNetwork *gameState);
void regularPile(GameStateNetwork* gameState);
void *serverHandler(void* argv);
 

#endif

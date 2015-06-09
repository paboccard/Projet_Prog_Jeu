#ifndef PACKS_H
#define PACKS_H


// enum of the differet types of packs in the protocol

enum packs {
    // CLIENT TO SERVER PACKS
    STARTTRAVEL = 0, PLAYTRAVEL, STOPTRAVEL, PLAYTILE, PILEWHENTRAVEL, IWANTPLAY, STARTGAME, CREATEGAME,DEBUG,QUIT, CREATEGAMENETWORK, IWANTPLAYNETWORK, REFRESHGAMESNETWORK, STARTGAMENETWORK,
    // SERVER TO CLIENT PACKS
  INITGAME, PLAYEDTILE, PLAYEDTRAVEL, STARTEDTRAVEL, STOPPEDTRAVEL, VALIDATION, WON, PILEPLAYER, NEWPLAYERADD,YOURIDPLAYER, GOAL,LAUNCH, RESPONSEREFRESH, GAMECREATENETWORK,REFRESHPLAYERGAME,RESPONSEPLAYERREFRESH,
    // ONLY SERVER
    CIRCULARQUEUECLIENT
};

enum error_pack {
	IMPOSSIBLE_PLAY = 0, TOO_MANY_TILES, WRONG_WAY, TILE_NOT_IN_HAND, DISCONNECTED, GAME_FULL, WRONG_PLAYER, TIME_FOR_REGULAR_PILE, TRAVEL_NOT_STARTED
};

#endif

#ifndef PACKS_H
#define PACKS_H


// enum of the differet types of packs in the protocol

enum packs {
    // CLIENT TO SERVER PACKS
    STARTTRAVEL = 0, PLAYTRAVEL, STOPTRAVEL, PLAYTILE,
    // SERVER TO CLIENT PACKS
    PLAYEDTILE, PLAYEDTRAVEL, STARTEDTRAVEL, STOPPEDTRAVEL, VALIDATION, WON;
};

enum error_pack {
    IMPOSSIBLE_PLAY = 0, TOO_MANY_TILES, WRONG_WAY;
};

#endif

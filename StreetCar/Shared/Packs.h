#ifndef PACKS_H
#define PACKS_H


// enum of the differet types of packs in the protocol

enum packs {
    // CLIENT TO SERVER PACKS
    STARTTRAVEL = 0, PLAYTRAVEL, STOPTRAVEL, PLAYTILE, PILEWHENTRAVEL,
    // SERVER TO CLIENT PACKS
    INITGAME, PLAYEDTILE, PLAYEDTRAVEL, STARTEDTRAVEL, STOPPEDTRAVEL, VALIDATION, WON, PILEPLAYER
};

#endif

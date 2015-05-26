#ifndef PARAMTHREADCLIENT_H
#define PARAMTHREADCLIENT_H

#include "../Shared/Pack.h"
#include "../Shared/ProdCons.h"

typedef struct {
    ProdCons<Pack*> *prodConsClient;
    ProdCons<Pack*> *prodConsCommon;
    int sockfd;
    struct sockaddr_in *serv_addr, *cli_addr;
} ParamThread;

typedef struct {
    ProdCons<Pack*> *prodConsCommon;
    int sockfd;
    struct sockaddr_in *serv_addr, *cli_addr;
} ParamThreadInput;


#endif

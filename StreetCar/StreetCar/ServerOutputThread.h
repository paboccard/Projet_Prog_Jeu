#ifndef SERVEROUTPUTTHREAD_H
#define SERVEROUTPUTTHREAD_H

#include <QThread>
#include "../Shared/ProdCons.h"
#include "../Shared/Pack.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ServerOutputThread : public QThread
{
		Q_OBJECT
	public:
		explicit ServerOutputThread(QObject *parent = 0);
		ServerOutputThread(ProdCons<Pack*> *p);
		void setSocket(int s) {sockfd = s;};


	signals:

	public slots:

	private:
		void run();
		ProdCons<Pack*> *prodCons;
		int sockfd;
};

#endif // SERVEROUTPUTTHREAD_H

#ifndef SERVEROUTPUTTHREAD_H
#define SERVEROUTPUTTHREAD_H

#include <QThread>
#include "ServerInputThread.h"
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
		ServerOutputThread(int socket);
		void sendSocket(Pack*);

	signals:

	public slots:


	private:
		void run();

		int sockfd;
		ServerInputThread *inputThread;
};

#endif // SERVEROUTPUTTHREAD_H

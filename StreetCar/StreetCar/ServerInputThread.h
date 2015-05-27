#ifndef SERVERINPUTTHREAD_H
#define SERVERINPUTTHREAD_H

#include <QThread>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../Shared/Pack.h"

class ServerInputThread : public QThread
{
		Q_OBJECT
	public:
		explicit ServerInputThread(QObject *parent = 0);
		ServerInputThread(int socket);

	signals:
		void receive(Pack*);

	public slots:

	private:
		void run();

		int sockfd;

};

#endif // SERVERINPUTTHREAD_H

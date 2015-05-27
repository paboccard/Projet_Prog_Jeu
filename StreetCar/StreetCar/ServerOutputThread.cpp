#include "ServerOutputThread.h"

using namespace std;

ServerOutputThread::ServerOutputThread(QObject *parent) :
	QThread(parent)
{
	sockfd = 0;
}

ServerOutputThread::ServerOutputThread(int socket)
{
	sockfd = socket;
}

void ServerOutputThread::sendSocket(Pack *p)
{

}



void ServerOutputThread::run()
{
	cout << "Output thread start" << endl;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	stringstream bufferStream;
	char buffer[256];
	int portno = 8080;


	server = gethostbyname("localhost");
	if (server == NULL) {
		cout << "ERROR, no such host " << endl;
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));	//reset addr

	serv_addr.sin_family = AF_INET;

	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(portno);

	serv_addr.sin_addr.s_addr = inet_addr("152.77.82.244");
	//bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));


	cout << "start to connect to the server" << endl;
	if (::connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		cout << "ERROR connecting " << endl;
		return;
	}

	cout << "Connected to the server" << endl;

	inputThread = new ServerInputThread(sockfd);
	inputThread->start();


}

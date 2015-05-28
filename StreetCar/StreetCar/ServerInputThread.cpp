#include "ServerInputThread.h"
#include "../Shared/Pack.h"

using namespace std;

ServerInputThread::ServerInputThread(QObject *parent) :
	QThread(parent)
{
	sockfd = 0;
}

void ServerInputThread::run()
{
	cout << "Input thread start" << endl;
	stringstream ss;
	char buffer[256];
	int n;
	Pack *pack = NULL;

	bool end = false;
	while (!end) {
		int packetSize;
		recv(sockfd, (char*)&packetSize, sizeof(int), MSG_WAITALL);
		packetSize = ntohl(packetSize);
		n = recv(sockfd,buffer,packetSize,MSG_WAITALL);


		if (n > 0) {

			cout << "reading on socket " << n << " " << buffer << endl;
			buffer[n] = '\0';
			ss.str(string()); //to clear the stringstream
			ss.clear();

			ss << buffer;
			ss >> *pack;

			receive(pack);
		}
		else {
			cout << "ERROR reading from socket" << endl;
			end = true;
		}
	}

}

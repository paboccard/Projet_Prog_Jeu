#include "ServerOutputThread.h"

using namespace std;

ServerOutputThread::ServerOutputThread(QObject *parent) :
	QThread(parent)
{
	sockfd = 0;
}

ServerOutputThread::ServerOutputThread(ProdCons<Pack*> *p)
{
	sockfd = 0;
	prodCons = p;
}

void ServerOutputThread::run()
{
	cout << "Output thread start" << endl;
	bool end = false;

	while (!end) {
		Pack *p = prodCons->consume();
		stringstream ss;
		ss << *p;


		ss.seekg(0, ios::end);
		int size = ss.tellg(); //size contain the size (in bytes) of the string
		int g = htonl(size);
		write(sockfd, (const char*)&g, sizeof(int));

        write(sockfd, ss.str().c_str(), size);
		cout << "Packet send" << endl;
		delete p;
	}
}

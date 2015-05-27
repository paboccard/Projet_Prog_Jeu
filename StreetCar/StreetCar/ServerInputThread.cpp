#include "ServerInputThread.h"

using namespace std;

ServerInputThread::ServerInputThread(QObject *parent) :
	QThread(parent)
{
	sockfd = 0;
}
ServerInputThread::ServerInputThread(int socket) : QThread(NULL) {
	sockfd = socket;
}

void ServerInputThread::run()
{
	cout << "Input thread start" << endl;

}

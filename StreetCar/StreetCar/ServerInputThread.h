#ifndef SERVERINPUTTHREAD_H
#define SERVERINPUTTHREAD_H

#include <QThread>

class ServerInputThread : public QThread
{
		Q_OBJECT
	public:
		explicit ServerInputThread(QObject *parent = 0);

	signals:

	public slots:

};

#endif // SERVERINPUTTHREAD_H

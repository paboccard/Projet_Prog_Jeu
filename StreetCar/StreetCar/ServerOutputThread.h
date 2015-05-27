#ifndef SERVEROUTPUTTHREAD_H
#define SERVEROUTPUTTHREAD_H

#include <QThread>

class ServerOutputThread : public QThread
{
		Q_OBJECT
	public:
		explicit ServerOutputThread(QObject *parent = 0);

	signals:

	public slots:

};

#endif // SERVEROUTPUTTHREAD_H

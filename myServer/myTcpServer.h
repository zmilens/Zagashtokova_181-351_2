#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class myTcpServer : public QObject
{
	Q_OBJECT

public:
	myTcpServer(QObject *parent=nullptr);
	~myTcpServer();

public slots:
	void slotNewConnection();
	void slotClientDisconnected();
	void slotServerRead();

private:
	QTcpServer *mTcpServer;
	QTcpSocket *mTcpSocket;
	int server_status; 
};

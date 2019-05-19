#pragma once

#include <QObject>
#include <QDateTime>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QObject>
#include <QVariant>

class myTcpServer : public QObject
{
	Q_OBJECT

public:
	myTcpServer(QObject *parent = nullptr);
	~myTcpServer();

public slots:
	void slotNewConnection();
	void slotClientDisconnected();
	//void slotServerRead();
	void slotReadClient();
	void slotSendClient(QString com);

private:
	QTcpServer *mTcpServer;
	QTcpSocket *mTcpSocket;
	int server_status;
	QMap<int, QTcpSocket *> SClients; //контейнер, хранит ключ-значение
};

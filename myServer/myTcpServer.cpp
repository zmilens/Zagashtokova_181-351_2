
#include "myTcpServer.h"
#include <QDebug>

myTcpServer::myTcpServer(QObject *parent)
	: QObject(parent)
{
	mTcpServer = new QTcpServer(this);

	connect(mTcpServer, &QTcpServer::newConnection, this, &myTcpServer::slotNewConnection);
	
	if (!mTcpServer->listen(QHostAddress::Any, 33333) && server_status == 0) {
		qDebug() << "server isn't work";
	}
	else {
		server_status = 1;
		qDebug() << "server is work";
	}
}

myTcpServer::~myTcpServer()
{
	server_status = 0;
}

void myTcpServer::slotNewConnection()
{
	if (server_status == 1) 
	{
		//QTcpSocket * clientSocket = mTcpServer->nextPendingConnection();
		//mTcpSocket->write("hello!\r\n");
		QTcpSocket* clientSocket = mTcpServer->nextPendingConnection(); //подтверждение соединения, возвращает сокет
		int idclien = clientSocket->socketDescriptor();
		SClients[idclien] = clientSocket;
		connect(SClients[idclien], SIGNAL(readyRead()), this, SLOT(slotReadClient()));
		connect(SClients[idclien], SIGNAL(disconected()), this, SLOT(slotClientDisconnected()));
	}
}

void myTcpServer::slotSendClient(QString com) {
	QObject *obj = QObject::sender();
	QTcpSocket *sock = static_cast<QTcpSocket *>(obj);
	QByteArray array;
	array.append(com);

	sock->write(array);
}

void myTcpServer::slotReadClient()
{
	QTcpSocket* clientSocket = (QTcpSocket*)sender();
	int idclien = clientSocket->socketDescriptor();
	QTextStream os(clientSocket);
	qDebug() << os.readAll();	
}

void myTcpServer::slotClientDisconnected() {

	QTcpSocket* clientSocket = (QTcpSocket*)sender();
	int idclien = clientSocket->socketDescriptor();
	SClients[idclien]->close();
	qDebug() << QString::fromUtf8("сервер остановлен");
}


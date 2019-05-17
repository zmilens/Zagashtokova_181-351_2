
#include "myTcpServer.h"
#include "DataBase.h"
#include <QDebug>


myTcpServer::myTcpServer(QObject *parent)
	: QObject(parent)
{
	mTcpServer = new QTcpServer(this);

	connect(mTcpServer, &QTcpServer::newConnection, this, &myTcpServer::slotNewConnection); //������ newConnection ������������ ������ ���, ����� ������ ������������ � �������
	//��������� ���������� ������� ���� �� ������� � 
	//�������-����������� � ������� � �������- ���������� . ���������� ���������� ����������, 
	//������� ����� ������������ ��� ��� ���������� �����.
	if (!mTcpServer->listen(QHostAddress::Any, 33333) && server_status == 0) { //������������ �������� ����������
		qDebug() << "server isn't work";
	}
	else {
		server_status = 1;
		qDebug() << "server is work";
	}
}

myTcpServer::~myTcpServer()
{
	if (server_status == 1) {
		foreach(int i, SClients.keys()) { //foreach ���������� ��� �������� ���������� 
			QTextStream qts(SClients[i]); //��� ������ � ������
			qts.setAutoDetectUnicode(true); //���� ��������� Unicode, ������������ ������ ������, ���� ���� UTF ������� ������� ����� �� ����� UTF.
			qts << QDateTime::currentDateTime().toString(); //��������� ����-����� 
			SClients[i]->close();
			SClients.remove(i); //�������
		}
		mTcpServer->close();
		qDebug() << QString::fromUtf8("server is stop");
		server_status = 0;
	}
}

void myTcpServer::slotNewConnection()
{
	if (server_status == 1) 
	{
		QTcpSocket* clientSocket = mTcpServer->nextPendingConnection(); //������������� ����������, ���������� �����
		int idclien = clientSocket->socketDescriptor();
		SClients[idclien] = clientSocket;
		connect(SClients[idclien], SIGNAL(readyRead()), this, SLOT(slotReadClient()));
		connect(SClients[idclien], &QTcpSocket::disconnected, this, &myTcpServer::slotClientDisconnected);
	}
}

void myTcpServer::slotSendClient(QString com) {
	QObject *obj = QObject::sender(); //���������� ��������� �� ������
	QTcpSocket *socket = static_cast<QTcpSocket *>(obj); //����������� obj ?
	QByteArray array;
	array.append(com); //��������� ������ � ��������� ������� 

	socket->write(array); 
}

void myTcpServer::slotReadClient()
{
	QTcpSocket* clientSocket = (QTcpSocket*)sender();
	int idclien = (int)clientSocket->socketDescriptor();

	QByteArray array = clientSocket->readAll();
	std::string login, password, mess, action;
	mess = array.toStdString();
	qDebug() << QString::fromStdString(mess);
	int p = mess.find(" ");
	action = mess.substr(0, p);
	mess.erase(0, p + 1);
	if (action == "autorize") {
		p = mess.find(" ");
		login = mess.substr(0, p);
		mess.erase(0, p + 1);
		p = mess.find(" ");
		password= mess.substr(0, p);
		mess.erase(0, p + 1);
		qDebug() << "login:" << QString::fromStdString(login)
			<< "password:" << QString::fromStdString(password)
			<< "access" << autorize(QString::fromStdString(login), QString::fromStdString(password));
		slotSendClient(autorize(QString::fromStdString(login), QString::fromStdString(password)));
	}
	else if (action =="Managerwin") {
		std::string mess;
		DataBase base;
		base.download();
		slotSendClient(QString::fromStdString(mess));
	}

}


void myTcpServer::slotClientDisconnected() {

	QObject * object = QObject::sender();
	QTcpSocket * socket = static_cast<QTcpSocket *>(object);
	socket->close();
	qDebug() << QString::fromUtf8("server is stop");
}


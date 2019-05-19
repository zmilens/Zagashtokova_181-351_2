
#include "myTcpServer.h"
#include "DataBase.h"
#include <QDebug>


myTcpServer::myTcpServer(QObject *parent)
	: QObject(parent)
{
	mTcpServer = new QTcpServer(this);

	connect(mTcpServer, &QTcpServer::newConnection, this, &myTcpServer::slotNewConnection); //сигнал newConnection отправляется каждый раз, когда клиент подключается к серверу
	//создается соединение данного типа из сигнала в 
	//объекте-отправителе с методом в объекте- получателе . Возвращает дескриптор соединения, 
	//который можно использовать для его отключения позже.
	if (!mTcpServer->listen(QHostAddress::Any, 33333) && server_status == 0) { //прослушивает входящие соединения
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
		foreach(int i, SClients.keys()) { //foreach перебирает все элементы контейнера 
			QTextStream qts(SClients[i]); //для чтения и записи
			qts.setAutoDetectUnicode(true); //ищет кодировку Unicode, просматривая данные потока, если есть UTF заменит текущий кодек на кодек UTF.
			qts << QDateTime::currentDateTime().toString(); //считывает дату-время 
			SClients[i]->close();
			SClients.remove(i); //удаляет
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
		QTcpSocket* clientSocket = mTcpServer->nextPendingConnection(); //подтверждение соединения, возвращает сокет
		int idclien = clientSocket->socketDescriptor();
		SClients[idclien] = clientSocket;
		connect(SClients[idclien], SIGNAL(readyRead()), this, SLOT(slotReadClient()));
		connect(SClients[idclien], &QTcpSocket::disconnected, this, &myTcpServer::slotClientDisconnected);
	}
}

void myTcpServer::slotSendClient(QString com) {
	QObject *obj = QObject::sender(); //возвращает указатель на объект
	QTcpSocket *socket = static_cast<QTcpSocket *>(obj); //преобразует obj ?
	QByteArray array;
	array.append(com); //добавляет строку к байтовому массиву 

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
		password = mess.substr(0, p);
		mess.erase(0, p + 1);
		qDebug() << "login:" << QString::fromStdString(login)
			<< "password:" << QString::fromStdString(password)
			<< "access" << autorize(QString::fromStdString(login), QString::fromStdString(password));
		slotSendClient(autorize(QString::fromStdString(login), QString::fromStdString(password)));
	}
	else if (action == "Adminwin") {
		std::string mess;
		DataBase base;
		base.downloadlogpas(mess);
		slotSendClient(QString::fromStdString(mess));
	}
	else if (action == "Managerwin") {
		std::string mess;
		DataBase base;
		base.download(mess);
		slotSendClient(QString::fromStdString(mess));
	}
	else if (action == "Clientwin") {
		std::string mess;
		DataBase base;
		base.download(mess);
		slotSendClient(QString::fromStdString(mess));
	}
	else if (action == "Add_record") {
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Test");
			if(!db.open())
				qDebug() << db.lastError().text();
		p = mess.find(" ");
		QString top = QString::fromStdString(mess.substr(0, p));
		mess.erase(0, p + 1);
		p = mess.find(" ");
		QString name = QString::fromStdString(mess.substr(0, p));
		mess.erase(0, p + 1);
		p = mess.find(" ");
		QString arc = QString::fromStdString(mess.substr(0, p));
		mess.erase(0, p + 1);
		p = mess.find(" ");
		QString mag = QString::fromStdString(mess);
		QSqlQuery query(db);
		query.prepare("INSERT INTO Database(topic, author, article, magazine)"
			"VALUES (:topic, :author, :article, :magazine");
		query.bindValue(":topic", top);
		query.bindValue(":author", name);
		query.bindValue(":article", arc);
		query.bindValue(":magazine", mag);
		query.exec();
		//ms.setText("The record added to the database");
		db.close();
	}
}


void myTcpServer::slotClientDisconnected() {

	QObject * object = QObject::sender();
	QTcpSocket * socket = static_cast<QTcpSocket *>(object);
	socket->close();
	qDebug() << QString::fromUtf8("server is stop");
}


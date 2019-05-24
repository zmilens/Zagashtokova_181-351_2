
#include "myTcpServer.h"
#include <qcryptographichash.h>
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
	
	crypto cryp;
	QByteArray array2 = cryp.encrypt(array);

	socket->write(array2);
}

void myTcpServer::slotReadClient()
{
	QTcpSocket* clientSocket = (QTcpSocket*)sender();
	int idclien = (int)clientSocket->socketDescriptor();

	QByteArray array = clientSocket->readAll();
	crypto cryp;
	QByteArray array2 = cryp.decrypt(array);

	std::string login, password, mess, action;
	mess = array2.toStdString();
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
	else if (action == "Add_record:") {
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Test");
		if (!db.open())
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
		query.prepare("INSERT INTO Database(topic, author, article, magazine) VALUES (:topic, :author, :article, :magazine)");
		query.bindValue(":topic", top);
		query.bindValue(":author", name);
		query.bindValue(":article", arc);
		query.bindValue(":magazine", mag);
		query.exec();
		db.close();
	}
	else if (action == "Add_user:") {
		crypto cryp;
		QByteArray array, array2, ar;
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Logpas");
		if (!db.open())
			qDebug() << db.lastError().text();
		p = mess.find(" ");
		QString login = QString::fromStdString(mess.substr(0, p));
		mess.erase(0, p + 1);
		p = mess.find(" ");
		QString password = QString::fromStdString(mess.substr(0, p));
		array = password.toUtf8();
		array2= QCryptographicHash::hash(array, QCryptographicHash::Md5);

		//array2 = cryp.decrypt(array);
		QString pass=QString::fromStdString(array2.toStdString());
		mess.erase(0, p + 1);
		p = mess.find(" ");
		QString access = QString::fromStdString(mess);
		QSqlQuery query(db);
		query.prepare("INSERT INTO User(login, password, access) VALUES (:login, :password, :access)");
		query.bindValue(":login", login);
		query.bindValue(":password", pass);
		query.bindValue(":access", access);
		query.exec();

		//array = cryp.encrypt(arr);
		db.close();
	}
	else if (action == "Delete_record:") {
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Test");
		if (!db.open())
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
		query.prepare("DELETE FROM Database WHERE topic=:topic");
		query.bindValue(":topic", top);
		query.exec();
		query.prepare("DELETE FROM Database WHERE author=:author");
		query.bindValue(":author", name);
		query.exec();
		query.prepare("DELETE FROM Database WHERE article=:article");
		query.bindValue(":article", arc);
		query.exec();
		query.prepare("DELETE FROM Database WHERE magazine=:mag");
		query.bindValue(":magazine", mag);
		query.exec();
		db.close();
	}
	else if (action == "Delete_user:") {
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Logpas");
		if (!db.open())
			qDebug() << db.lastError().text();
		p = mess.find(" ");
		QString login = QString::fromStdString(mess);
		QSqlQuery query(db);
		query.prepare("DELETE FROM User WHERE login=:login");
		query.bindValue(":login", login);
		query.exec();
		db.close();
	}
	else if (action == "Adminwin") {
		std::string mess;
		DataBase base;
		base.downloadlogpas(mess);
		slotSendClient(QString::fromStdString(mess));
	}
	else if (action == "Database_loaded") {
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("Test");
		std::string mess;
		DataBase base;
		base.download(mess);
		slotSendClient(QString::fromStdString(mess));
		db.close();

	}
}


void myTcpServer::slotClientDisconnected() {

	QObject * object = QObject::sender();
	QTcpSocket * socket = static_cast<QTcpSocket *>(object);
	socket->close();
	qDebug() << QString::fromUtf8("server is stop");
}


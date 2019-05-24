#include "Adminwin.h"
#include <QMessageBox>
#include <QIODevice>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Adminwin::Adminwin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//ui.labn
	socket = new QTcpSocket;
	//socket->connectToHost("127.0.0.1", 33333);
	//connect(socket, SIGNAL(readyRead()), SLOT(ready_read()));
	//connect(socket, SIGNAL(connected()), SLOT(connected()));
	//send_server("Adminwin ");

}

void Adminwin::take_socket(QTcpSocket *sock) {
	//socket->connectToHost("127.0.0.1", 33333);
	socket = sock;
	connect(socket, &QTcpSocket::readyRead, this, &Adminwin::ready_read);
	//connect(socket, SIGNAL(connected()), SLOT(connected()));
}


void Adminwin::disconnected() {
	disconnect(socket, &QTcpSocket::readyRead, this, &Adminwin::ready_read);

}
void Adminwin::send_server(QString message) {
	QByteArray array;
	array.append(message);
	crypto cryp;
	QByteArray array2 = cryp.encrypt(array);
	socket->write(array2);
}
void Adminwin::on_pushButton_find_clicked() {
	QStandardItem *item;
	crypto cryp;
	QString t = ui.lineEdit_find->text();
	model1 = new QStandardItemModel(0, 3, this);
	ui.tableView->setModel(model1);
	model1->setHeaderData(0, Qt::Horizontal, "Login");
	model1->setHeaderData(1, Qt::Horizontal, "Password");
	model1->setHeaderData(2, Qt::Horizontal, "Access");
	base.findinglogpas(t.toStdString());
	for (int i = 0; i < base.db1.size(); i++)
	{
		item = new QStandardItem(QString::fromStdString(base.db1[i].log));
		model1->setItem(i, 0, item);

		item = new QStandardItem(QString::fromStdString(base.db1[i].pass));
		model1->setItem(i, 1, item);

		item = new QStandardItem(QString::fromStdString(base.db1[i].access));
		model1->setItem(i, 2, item);
	}

}

void Adminwin::on_pushButton_add_clicked() {
	QString access = ui.lineEdit_4->text();
	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	/*QByteArray arr, password;
	password.append(ui.lineEdit_password->text());
	arr.append(password);
	password = QCryptographicHash::hash(arr, QCryptographicHash::Md5);
	crypto cryp;
	QByteArray array2 = cryp.encrypt(arr);*/
	QMessageBox ms;
	//array2.toStdString();
	ms.setText("The user added to the database");
	//QString pass = QString::fromStdString(arr.toStdString());
	if (login.toStdString()!="admin" && checkAccess(access.toStdString()) != "0" && access.toStdString() != "admin" && (access.toStdString() == "User" || access.toStdString() == "Manager")) {
		
		access = QString::fromStdString(checkAccess(access.toStdString()));
		send_server("Add_user: " + login + " " + password + " " + access);
		ms.exec();
	}
	
}

void Adminwin::on_pushButton_delete_clicked() {

	QString login = ui.lineEdit_login->text();
	if (login.toStdString() != "admin") {
		QMessageBox ms;
		ms.setText("The user deleted from the database");
		send_server("Delete_user: " + login);
		ms.exec();
	}
}

void Adminwin::on_pushButton_2_clicked() {

	model1 = new QStandardItemModel(0, 3, this);
	ui.tableView->setModel(model1);
	model1->clear();
}

void Adminwin::on_pushButton_clicked() {

	QStandardItem *item;
	QString t = ui.lineEdit_find->text();
	model1 = new QStandardItemModel(0, 3, this);
	ui.tableView->setModel(model1);
	model1->setHeaderData(0, Qt::Horizontal, "Login");
	model1->setHeaderData(1, Qt::Horizontal, "Password");
	model1->setHeaderData(2, Qt::Horizontal, "Access");
	base.findinglogpas("clear");
	for (int i = 0; i < base.db1.size(); i++)
	{
		item = new QStandardItem(QString::fromStdString(base.db1[i].log));
		model1->setItem(i, 0, item);

		item = new QStandardItem(QString::fromStdString(base.db1[i].pass));
		model1->setItem(i, 1, item);

		item = new QStandardItem(QString::fromStdString(base.db1[i].access));
		model1->setItem(i, 2, item);
	}

	send_server("Adminwin ");
}

void Adminwin::ready_read() {
	QByteArray array;
	std::string message;
	while (socket->bytesAvailable() > 0) {
		array = socket->readAll();
	}
	crypto cryp;
	QByteArray array2 = cryp.decrypt(array);
	message = array2.toStdString();

	base.transformStr2BDlogpas(message);
	QStandardItem *item;

	model1 = new QStandardItemModel(0, 3, this);
	ui.tableView->setModel(model1);
	model1->setHeaderData(0, Qt::Horizontal, "Login");
	model1->setHeaderData(1, Qt::Horizontal, "Password");
	model1->setHeaderData(2, Qt::Horizontal, "Access");

	for (int i = 0; i < base.db1.size(); i++)
	{
		item = new QStandardItem(QString::fromStdString(base.db1[i].log));
		model1->setItem(i, 0, item);

		item = new QStandardItem(QString::fromStdString(base.db1[i].pass));
		model1->setItem(i, 1, item);

		item = new QStandardItem(QString::fromStdString(base.db1[i].access));
		model1->setItem(i, 2, item);

	}

}



Adminwin::~Adminwin()
{
	//socket->close();
}

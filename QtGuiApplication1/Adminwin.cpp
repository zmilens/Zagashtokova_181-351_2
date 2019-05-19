#include "Adminwin.h"
#include "DataBase.h"
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

	socket = new QTcpSocket(this);
	socket->connectToHost("127.0.0.1", 33333);
	connect(socket, SIGNAL(readyRead()), SLOT(ready_read()));
	connect(socket, SIGNAL(connected()), SLOT(connected()));
	send_server("Adminwin ");

}

void Adminwin::send_server(QString message) {
	QByteArray array;
	array.append(message);
	socket->write(array);
}
void Adminwin::on_pushButton_find_clicked() {
	QStandardItem *item;
	QString t = ui.lineEdit_find->text();
	model1 = new QStandardItemModel(0, 4, this);
	ui.tableView->setModel(model1);
	model1->setHeaderData(0, Qt::Horizontal, "Login");
	model1->setHeaderData(1, Qt::Horizontal, "Password");
	model1->setHeaderData(2, Qt::Horizontal, "Access");
	DataBase base;
	base.downloadlogpas();
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
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Logpas");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL, access VARCHAR(10) NOT NULL)");
	
	query.exec("SELECT *FROM User");
	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	QString access = ui.lineEdit_4->text();
	send_server("Add_user: "+ login + " " + password +" "+ access);
	db.close();
}

void Adminwin::on_pushButton_delete_clicked() {
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Logpas");
	if (!db.open())
		qDebug() << db.lastError().text();

	QSqlQuery query(db);
	query.exec("CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL, access VARCHAR(10) NOT NULL)");

	query.exec("SELECT *FROM User");
	QString login = ui.lineEdit_login->text();
	send_server("Delete_user: "+login);
	db.close();
}

void Adminwin::on_pushButton_clicked() {
	/*QStandardItem *item;
	DataBase base;
	base.downloadlogpas();
	for (int i = 0; i < base.db1.size(); i++)
	{
		item = new QStandardItem(QString::fromStdString(base.db1[i].log));
		model1->setItem(i, 0, item);

		item = new QStandardItem(QString::fromStdString(base.db1[i].pass));
		model1->setItem(i, 1, item);

		item = new QStandardItem(QString::fromStdString(base.db1[i].access));
		model1->setItem(i, 2, item);
	}
	*/
	send_server("Adminwin ");
}

void Adminwin::ready_read() {
	QByteArray array;
	std::string message;
	while (socket->bytesAvailable() > 0) {
		array = socket->readAll();
		message = array.toStdString();
	}
	DataBase base;
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

void Adminwin::connected() {
	QMessageBox msgBox;
	msgBox.setText("Connected to the server");
	msgBox.exec();
}
Adminwin::~Adminwin()
{
}

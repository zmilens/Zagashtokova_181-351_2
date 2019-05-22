#include "Clientwin.h"
#include <QMessageBox>
#include <QIODevice>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>

Clientwin::Clientwin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	socket = new QTcpSocket(this);
	socket->connectToHost("127.0.0.1", 33333);
	connect(socket, SIGNAL(readyRead()), SLOT(ready_read()));

	send_server("Database_loaded ");
}

void Clientwin::on_pushButton_find_clicked() {
	QStandardItem *item;
	QString t = ui.lineEdit_find->text();
	model = new QStandardItemModel(0, 4, this);
	ui.tableView->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, "Topic");
	model->setHeaderData(1, Qt::Horizontal, "Author");
	model->setHeaderData(2, Qt::Horizontal, "Article");
	model->setHeaderData(3, Qt::Horizontal, "Magazine");
	DataBase base;
	base.download();
	base.finding(t.toStdString());
	for (int i = 0; i < base.db.size(); i++)
	{

		item = new QStandardItem(QString::fromStdString(base.db[i].topic));
		model->setItem(i, 0, item);

		item = new QStandardItem(QString::fromStdString(base.db[i].author));
		model->setItem(i, 1, item);

		item = new QStandardItem(QString::fromStdString(base.db[i].article));
		model->setItem(i, 2, item);

		item = new QStandardItem(QString::fromStdString(base.db[i].magazine));
		model->setItem(i, 3, item);
	}
}
void Clientwin::on_pushButton_clicked() {
	send_server("Database_loaded ");
}
void Clientwin::send_server(QString message) {
	QByteArray array;
	array.append(message);
	crypto cryp;
	QByteArray array2 = cryp.encrypt(array);
	socket->write(array2);
}
void Clientwin::ready_read() {
	QByteArray array;
	std::string message;
	while (socket->bytesAvailable() > 0) {
		array = socket->readAll();
	}
	crypto cryp;
	QByteArray array2 = cryp.decrypt(array);
	message = array2.toStdString();
	DataBase base;
	base.transformStr2BD(message);
	QStandardItem *item;

	model = new QStandardItemModel(0, 4, this);
	ui.tableView->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, "Topic");
	model->setHeaderData(1, Qt::Horizontal, "Author");
	model->setHeaderData(2, Qt::Horizontal, "Article");
	model->setHeaderData(3, Qt::Horizontal, "Magazine");
	for (int i = 0; i < base.db.size(); i++)
	{
		item = new QStandardItem(QString::fromStdString(base.db[i].topic));
		model->setItem(i, 0, item);

		item = new QStandardItem(QString::fromStdString(base.db[i].author));
		model->setItem(i, 1, item);

		item = new QStandardItem(QString::fromStdString(base.db[i].article));
		model->setItem(i, 2, item);

		item = new QStandardItem(QString::fromStdString(base.db[i].magazine));
		model->setItem(i, 3, item);
	}
}
Clientwin::~Clientwin()
{
}

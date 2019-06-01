#include "Managerwin.h"
#include "DataBase.h"
#include <QMessageBox>
#include <QIODevice>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>


Managerwin::Managerwin(QWidget *parent)
	: QDialog(parent)

{
	ui.setupUi(this);

	socket = new QTcpSocket;

}

void Managerwin::on_pushButton_2_clicked() {

	model = new QStandardItemModel(0, 4, this);
	ui.tableView->setModel(model);
	model->clear();
}

void Managerwin::take_socket(QTcpSocket *sock) {
	socket = sock;
	connect(socket, &QTcpSocket::readyRead, this, &Managerwin::ready_read);
}

void Managerwin::disconnected() {
	disconnect(socket, &QTcpSocket::readyRead, this, &Managerwin::ready_read);

}

void Managerwin::send_server(QString message) {
	QByteArray array;
	array.append(message);
	crypto cryp;
	QByteArray array2 = cryp.encrypt(array);
	socket->write(array2);
}

void Managerwin::on_pushButton_delete_clicked() {
	QString top = ui.lineEdit_topic->text();
	QString name = ui.lineEdit_author->text();
	QString arc = ui.lineEdit_article->text();
	QString mag = ui.lineEdit_magazine->text();
	QMessageBox ms;
	ms.setText("The record is deleted from database");
	send_server("Delete_record: " + top + " " + name + " " + arc + " " + mag);
	ms.exec();
}

void Managerwin::on_pushButton_add_clicked() {

	QString top = ui.lineEdit_topic->text();
	QString name = ui.lineEdit_author->text();
	QString arc = ui.lineEdit_article->text();
	QString mag = ui.lineEdit_magazine->text();
	if (checkTopic(top.toStdString()) != "0" && checkAuthor(name.toStdString()) != "0"
		&& checkArticle(arc.toStdString()) != "0" &&checkMag(mag.toStdString()) != "0") {
		top = QString::fromStdString(checkTopic(top.toStdString()));
		name = QString::fromStdString(checkAuthor(name.toStdString()));
		arc = QString::fromStdString(checkArticle(arc.toStdString()));
		mag = QString::fromStdString(checkMag(mag.toStdString()));
	}
	QMessageBox ms;
	ms.setText("The record added to the database");
	send_server("Add_record: " + top + " " + name + " " + arc + " " + mag);
	ms.exec();
}

void Managerwin::on_pushButton_find_clicked() {
	QStandardItem *item;
	QString t = ui.lineEdit_find->text();
	model = new QStandardItemModel(0, 4, this);
	ui.tableView->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, "Topic");
	model->setHeaderData(1, Qt::Horizontal, "Author");
	model->setHeaderData(2, Qt::Horizontal, "Article");
	model->setHeaderData(3, Qt::Horizontal, "Magazine");
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

void Managerwin::on_pushButton_clicked() {
	QStandardItem *item;
	QString t = ui.lineEdit_find->text();
	model = new QStandardItemModel(0, 3, this);
	ui.tableView->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, "Topic");
	model->setHeaderData(1, Qt::Horizontal, "Author");
	model->setHeaderData(2, Qt::Horizontal, "Article");
	model->setHeaderData(3, Qt::Horizontal, "Magazine");
	base.finding("clear");
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
	send_server("Database_loaded ");
}

void Managerwin::ready_read() {
	QByteArray array;
	std::string message;
	while (socket->bytesAvailable() > 0) {
		array = socket->readAll();
	}
	crypto cryp;
	QByteArray array2 = cryp.decrypt(array);
	message = array2.toStdString();

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

Managerwin::~Managerwin()
{
}

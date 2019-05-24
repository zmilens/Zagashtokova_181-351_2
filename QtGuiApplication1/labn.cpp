#include <iostream>
#include "labn.h"
#include <QMessageBox>
#include <QIODevice>
#include <QFile>
#include <QtCore/QCoreApplication>
#include<QSQlDatabase> 
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QVariant>
labn::labn(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//manwin = new Managerwin();
	//cliwin = new Clientwin();
	//admwin = new Adminwin();

	socket= new QTcpSocket;
	socket->connectToHost("127.0.0.1", 33333);
	connect(socket, &QTcpSocket::disconnected, this, &labn::connected);
	connect(socket, &QTcpSocket::readyRead, this, &labn::ready_read);

	connect(socket, SIGNAL(connected()), SLOT(connect()));
	//connect(socket, SIGNAL(readyRead()), SLOT(ready_read()));
	//connect(socket, SIGNAL(disconnected()), SLOT(disconnect()));


}

void labn::on_pushButton_autorize_clicked()
{
	//disconnect(socket, &QTcpSocket::readyRead, this, &labn::ready_read);

	manwin = new Managerwin();
	cliwin = new Clientwin();
	admwin = new Adminwin();
	//—читываем lineEdits
	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	QMessageBox msgBox;
	
	QString message;
	message = "autorize " + login + " " + password;

	send_server(message);
}

void labn::connected() {
	QMessageBox msgBox;
	msgBox.setText("Connected to the server");
	msgBox.exec();
}

void labn::disconnected()
{
	socket->close();
}

void labn::ready_read() {
	
	disconnect(socket, &QTcpSocket::readyRead, this, &labn::ready_read);

	QByteArray array;
	std::string message;
	while (socket->bytesAvailable() > 0) {
		array = socket->readAll();
	}
	crypto cryp;
	QByteArray array2 = cryp.decrypt(array);
	message = array2.toStdString();

	QMessageBox msgBox;

	if (message == "Admin") {
		admwin->take_socket(socket);
		msgBox.setText("Admin access");
		admwin->show();
		this->close();
		msgBox.exec();
	}
	else {
		if (message == "Manager") {
			manwin->take_socket(socket);
			msgBox.setText("Manager access");
			manwin->show();
			this->close();
			msgBox.exec();
		}
		else {
			if (message == "User") {
				cliwin->take_socket(socket);
				msgBox.setText("User access");
				cliwin->show();
				this->close();
				msgBox.exec();
			}
			else {
				msgBox.setText("Login is incorrect.");
				msgBox.setInformativeText("Do you want to try again?");
				msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
				msgBox.setDefaultButton(QMessageBox::Retry);
				int res = msgBox.exec();
				if (res == QMessageBox::Close)
					close();
			}
		}
	}
} 

void labn::send_server(QString message) {
	QByteArray array;
	array.append(message);
	crypto cryp;
	QByteArray array2 = cryp.encrypt(array);
	socket->write(array2);
}
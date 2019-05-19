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
	manwin = new Managerwin();
	cliwin = new Clientwin();
	admwin = new Adminwin();

	socket= new QTcpSocket(this);
	socket->connectToHost("127.0.0.1", 33333);
	connect(socket, SIGNAL(connected()), SLOT(connected()));
	connect(socket, SIGNAL(readyRead()), SLOT(ready_read()));

}


void labn::on_pushButton_autorize_clicked()
{
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

void labn::disconnected() {
	QMessageBox msgBox;
	msgBox.setText("Disconnected from server");
	msgBox.exec();
}

void labn::ready_read() {
	QByteArray array;
	std::string message;
	QMessageBox msgBox;
	while (socket->bytesAvailable() > 0) {
		array = socket->readAll();
		message = array.toStdString();
	}
	if (message == "Admin") {
		msgBox.setText("Admin access");
		admwin->show();
		this->close();
		msgBox.exec();
	}
	else {
		if (message == "Manager") {
			msgBox.setText("Manager access");
			manwin->show();
			this->close();
			msgBox.exec();
		}
		else {
			if (message == "User") {
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
	socket->write(array);
}
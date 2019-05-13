#include <iostream>
#include "labn.h"
#include "Adminwin.h"
#include "Managerwin.h"
#include "Clientwin.h"
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
}
int autorize(QString login, QString password)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Logpas");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "open";
	QSqlQuery query(db);
	
	if (query.exec("SELECT * FROM User")) {
		while (query.next()) {
			if ((login == query.value(0).toString()) && (password == query.value(1).toString())) {
				if (query.value(2) == "Admin") {
					db.close();
					return 1;
				}
				else if (query.value(2) == "Manager") {
					db.close();
					return 2;
				}
				else if (query.value(2) == "User") {
					db.close();
					return 3;
				}
			}
		}
	}
	return 0;
}
void labn::on_pushButton_autorize_clicked()
{
	//—читываем lineEdits
	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	QMessageBox msgBox;

	if (autorize(login, password) == 1) {
		msgBox.setText("Admin access");
		admwin->show();

	}
	else if (autorize(login, password) == 2) {
		msgBox.setText("Manager access");
		manwin->show();
	}
	else if (autorize(login, password) == 3) {
		msgBox.setText("User access");
		cliwin->show();
	}
	else
	{
		msgBox.setText("Login is incorrect.");
		msgBox.setInformativeText("Do you want to try again?");
		msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
		msgBox.setDefaultButton(QMessageBox::Retry);
		int res = msgBox.exec();
		if (res == QMessageBox::Close)
		{
			close();
		}
	}

}

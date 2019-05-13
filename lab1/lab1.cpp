#include <iostream>
#include "lab1.h"
#include "managerwin.h"
#include "prosmotr.h"
#include <QMessageBox>
#include <QIODevice>

using namespace std;

lab1::lab1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	manwin = new managerwin();
	cliwin = new clientwin();
	proscli= new prosmotr;
}
int autorize(QString login, QString password)
{	
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "open";
	QFile info("info.txt"); //объект, содержащий файл, в котором хранятся логины и пароли
	QString str; //строчка в файле
	if (info.open(QIODevice::ReadOnly)) {
		while (!info.atEnd()) {
			str = info.readLine(); //считывает строку с файла и записывает в str
			if (str.contains(login) && str.contains(password)) { //contains проверяет наличие в этой строчки логина и пароля
				if (login == "admin") {
					info.close();
					return 1;
				}
				else if (str.contains("permission2")) {
					info.close();
					return 2;
				}
				else if (str.contains("permission3")) {
					info.close();
					return 3;
				}
			}
		}
	}
	return 0;
}
void lab1::on_pushButton_autorize_clicked()
{
	//Считываем lineEdits
	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	QMessageBox msgBox;

	if (autorize(login, password) == 1) {

		msgBox.setText("admin access");
		msgBox.exec();
		int res = msgBox.exec();
		if (res == QMessageBox::Close)
		{
			close();
		}
	
	}
	else if (autorize(login, password) == 2) {
		
		manwin->show();
	}
	else if (autorize(login, password) == 3) {

		proscli->show();
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


	

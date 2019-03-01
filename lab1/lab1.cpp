#include "lab1.h"
#include <QMessageBox>
bool autorize(QString login, QString password)
{
	return login == "admin" && password == "123";
}
lab1::lab1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
void lab1::On_pushButton_autorize_clicked() 
{
	//—читываем lineEdits
	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	QMessageBox msgBox;
	if (autorize(login, password)) 
	{
		QMessageBox msgBox;
		msgBox.setText("login is correct.");
		msgBox.exec();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("login isn't correct.");
		msgBox.setInformativeText("Do you want to try again?");
		msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
		msgBox.setDefaultButton(QMessageBox::Save);
	}
	int res = msgBox.exec();
	if (res == QMessageBox::Close)
	{
		close();
	}
};
	

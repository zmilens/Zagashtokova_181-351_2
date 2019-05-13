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
	model1 = new QStandardItemModel(0, 3, this);
	ui.tableView->setModel(model1);
	model1->setHeaderData(0, Qt::Horizontal, "Login");
	model1->setHeaderData(1, Qt::Horizontal, "Password");
	model1->setHeaderData(2, Qt::Horizontal, "Access");
	QStandardItem *item;
	
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
}

Adminwin::~Adminwin()
{
}

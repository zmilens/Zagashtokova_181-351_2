
#include "prosmotr.h"
#include <QMessageBox>
#include "DataBase.h"
#include <QMessageBox>
#include <QIODevice>
#include <QFile>

prosmotr::prosmotr(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QStandardItem *item;

	model = new QStandardItemModel(0, 4, this);
	ui.tableView->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, "Topic");
	model->setHeaderData(1, Qt::Horizontal, "Author");
	model->setHeaderData(2, Qt::Horizontal, "Article");
	model->setHeaderData(3, Qt::Horizontal, "Magazine");
	DataBase base;
	base.download();
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

prosmotr::~prosmotr()
{
}

void prosmotr::on_prosm_triggered(){	
	
}


#include "Managerwin.h"
#include "DataBase.h"
#include <QMessageBox>
#include <QIODevice>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


Managerwin::Managerwin(QWidget *parent)
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

void Managerwin::sendServer(QString com) {
	QByteArray array;
	array.append(com);
	s->write(array);
}

/*void Managerwin:: pushButton_delete_clicked() {
	QString d = ui.lineEdit_fd->text();
	if (d != "") {
		int id = d.toInt();
	}
}*/

void Managerwin:: pushButton_add_clicked() {
	data s;
	QString t = ui.lineEdit_topic->text();
	QString n = ui.lineEdit_author->text();
	QString a = ui.lineEdit_article->text();
	QString m = ui.lineEdit_magazine->text();
	s.topic = t.toStdString();
	s.author = n.toStdString();
	s.article = a.toStdString();
	s.magazine = m.toStdString();
	if (checkTopic(s.topic) && checkAuthor(s.author) && checkArticle(s.article) && checkMag(s.magazine)) {
		sendServer(t + '\t' + n + '\t' + a + '\t' + m + '\n');
		QMessageBox msgBox;
		msgBox.setText("record is added to database");
	}

}
Managerwin::~Managerwin()
{
}

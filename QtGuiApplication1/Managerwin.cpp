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

/*void Managerwin::sendServer(QString com) {
	QByteArray array;
	array.append(com);
	s->write(array);
}
*/
/*void Managerwin:: pushButton_delete_clicked() {
	QString d = ui.lineEdit_fd->text();
	if (d != "") {
		int id = d.toInt();
	}
}*/

void Managerwin:: on_pushButton_add_clicked() {
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");
	if (!db.open())
		qDebug() << db.lastError().text();

	QString t = ui.lineEdit_topic->text();
	QString n = ui.lineEdit_author->text();
	QString a = ui.lineEdit_article->text();
	QString m = ui.lineEdit_magazine->text();
	QSqlQuery query(db);
	query.exec("CREATE TABLE Database (topic VARCHAR(20) NOT NULL,"
		"author VARCHAR(20) NOT NULL, article VARCHAR(15) NOT NULL,"
		"magazine VARCHAR(15) NOT NULL)");
	query.exec("SELECT * FROM Database");
	QMessageBox ms;
	while (query.next())
		if ((query.value(0).toString() == t.toLocal8Bit().constData()) && (query.value(1).toString() == n.toLocal8Bit().constData())
			&& (query.value(2).toString() == a.toLocal8Bit().constData()) && (query.value(3).toString() == m.toLocal8Bit().constData()))
			ms.setText("This record is already in the database");
				query.prepare("INSERT INTO Database(topic, author, article, magazine)"
					"VALUES (:topic, :author, :article, :magazine");
		query.bindValue(":topic", t);
		query.bindValue(":author", n);
		query.bindValue(":article", a);
		query.bindValue(":magazine", m);
		
		ms.setText("The record added to the database");
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
	qDebug() << t;


}

void Managerwin::on_pushButton_clicked() {
	QStandardItem *item;
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


Managerwin::~Managerwin()
{
}

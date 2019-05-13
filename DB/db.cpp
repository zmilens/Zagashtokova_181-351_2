#include <QtCore/QCoreApplication>
#include<QSQlDatabase> 
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QVariant>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	//создаём базу данных SQLite
	//SQLite - встроенный драйвер в QT
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "open";

	QSqlQuery query(db);
	query.exec("DROP TABLE Database");

	//создаём таблицу
	query.exec("CREATE TABLE Database (topic VARCHAR(20) NOT NULL, author VARCHAR(20) NOT NULL, article VARCHAR(15) NOT NULL, magazine VARCHAR(15) NOT NULL)");

	//добавляем запись в таблицу
	//query.prepare("INSERT INTO User(login, password) VALUES(\"admin\", \"123\")");

	query.prepare("INSERT INTO Database(topic, author, article, magazine) VALUES(:topic, :author, :article, :magazine)");
	query.bindValue(":topic", "Fasion");
	query.bindValue(":author", "Milena");
	query.bindValue(":article", "Karl Lagerfeld");
	query.bindValue(":magazine", "Vogue");
	query.exec();

	query.prepare("INSERT INTO Database(topic, author, article, magazine) VALUES(:topic, :author, :article, :magazine)");
	query.bindValue(":topic", "Politic");
	query.bindValue(":author", "Sema");
	query.bindValue(":article", "Kremlin");
	query.bindValue(":magazine", "Tass");
	query.exec();

	query.prepare("INSERT INTO Database(topic, author, article, magazine) VALUES(:topic, :author, :article, :magazine)");
	query.bindValue(":topic", "Sport");
	query.bindValue(":author", "Julia");
	query.bindValue(":article", "Football");
	query.bindValue(":magazine", "MatchTv");
	query.exec();

	query.prepare("INSERT INTO Database(topic, author, article, magazine) VALUES(:topic, :author, :article, :magazine)");
	query.bindValue(":topic", "IT");
	query.bindValue(":author", "Anastasia");
	query.bindValue(":article", "Apple");
	query.bindValue(":magazine", "Habr");
	query.exec();
	//отправляем запрос



	/*
	INSERT INTO User(login, password) VALUES ("admin","123")

	ВЫБРАТЬ ВСЕ ЗАПИСИ БД:
	SELECT * FROM User

	ВЫБРАТЬ ЧАСТЬ ЗАПИСЕЙ БД С УСЛОВИЕМ:
	SELECT * FROM User WHERE .... (ЗДЕСЬ ПИШУТСЯ ЗАПРОСЫ)

	*/
	query.exec("SELECT * FROM Database");

	//вывести на экран

	QSqlRecord rec = query.record();
	const int topicIndex = rec.indexOf("topic"); //номер столбца
	const int authorIndex = rec.indexOf("author");
	const int articleIndex = rec.indexOf("article");
	const int magazineIndex = rec.indexOf("magazine");


	while (query.next()) {
		qDebug() << query.value(topicIndex) << '\t' << query.value(authorIndex) << '\t' << query.value(articleIndex) << '\t' << query.value(magazineIndex);;

	}
	//удалить таблицу
	//query.exec("DROP TABLE User");
	//закрыть базу данных
	db.close();
	return a.exec();

}

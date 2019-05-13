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

	//добавить запись путем SQL запроса 

	//создать запрос к БД
	/*
	СОЗДАНИЕ ТАБЛИЦЫ
	Название User 
	Поля: login, password - хранятся значения типа char[20] (массив символов длины 20) 
	CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL)

	зачем нужны типы данных?
		пример: в поле age типа integer у разных пользователей в разных записях БД (строках таблицы) записаны:
				"123"
				34
				"a"
		Вопрос: как сравнивать? 
		ПРЕОБРАЗУЕМ К ТИПУ INTEGER: 
			"123"->123(тип int)
			34->34
			"a"->65 (код символа)
	добавить запись путем SQL запроса
	Название таблицы: User
	login: "admin"
	password: "123"
	*/

	QSqlQuery query(db);
	query.exec("DROP TABLE User");

	//создаём таблицу
	query.exec("CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL, access VARCHAR(10) NOT NULL)");
	
	//добавляем запись в таблицу
	//query.prepare("INSERT INTO User(login, password) VALUES(\"admin\", \"123\")");
	
	query.prepare("INSERT INTO User(login, password, access) VALUES(:login, :password, :access)");
	query.bindValue(":login", "admin");
	query.bindValue(":password", "123");
	query.bindValue(":access", "Admin");
	query.exec();

	QString status_values[2] = { "Manager", "User" };
	QString status_login[2] = { "Manager", "User" };
	for (int i = 1; i < 21; i++)
	{
		query.prepare("INSERT INTO User(login, password, access) VALUES(:login, :password, :access)");
		query.bindValue(":login", status_login[i%2] + QString::number(i));
		query.bindValue(":password", "123"+ QString::number(i));
		query.bindValue(":access", status_values[i%2]);
		query.exec();
	}
	//отправляем запрос



	/*
	INSERT INTO User(login, password) VALUES ("admin","123")
	
	ВЫБРАТЬ ВСЕ ЗАПИСИ БД:
	SELECT * FROM User

	ВЫБРАТЬ ЧАСТЬ ЗАПИСЕЙ БД С УСЛОВИЕМ:
	SELECT * FROM User WHERE .... (ЗДЕСЬ ПИШУТСЯ ЗАПРОСЫ)

	*/
	query.exec("SELECT * FROM User");
	
	//вывести на экран

	QSqlRecord rec = query.record();
	const int loginIndex = rec.indexOf("login"); //номер столбца
	const int passwordIndex = rec.indexOf("password");
	const int accessIndex = rec.indexOf("access");

	while (query.next()) {
		qDebug ()<< query.value(loginIndex) << '\t' << query.value(passwordIndex )<<'\t' << query.value(accessIndex);;

	}
	//удалить таблицу
	//query.exec("DROP TABLE User");
	//закрыть базу данных
	db.close();
	return a.exec();

}

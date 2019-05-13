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
	//������ ���� ������ SQLite
	//SQLite - ���������� ������� � QT
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "open";

	//�������� ������ ����� SQL ������� 

	//������� ������ � ��
	/*
	�������� �������
	�������� User 
	����: login, password - �������� �������� ���� char[20] (������ �������� ����� 20) 
	CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL)

	����� ����� ���� ������?
		������: � ���� age ���� integer � ������ ������������� � ������ ������� �� (������� �������) ��������:
				"123"
				34
				"a"
		������: ��� ����������? 
		����������� � ���� INTEGER: 
			"123"->123(��� int)
			34->34
			"a"->65 (��� �������)
	�������� ������ ����� SQL �������
	�������� �������: User
	login: "admin"
	password: "123"
	*/

	QSqlQuery query(db);
	query.exec("DROP TABLE User");

	//������ �������
	query.exec("CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL, access VARCHAR(10) NOT NULL)");
	
	//��������� ������ � �������
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
	//���������� ������



	/*
	INSERT INTO User(login, password) VALUES ("admin","123")
	
	������� ��� ������ ��:
	SELECT * FROM User

	������� ����� ������� �� � ��������:
	SELECT * FROM User WHERE .... (����� ������� �������)

	*/
	query.exec("SELECT * FROM User");
	
	//������� �� �����

	QSqlRecord rec = query.record();
	const int loginIndex = rec.indexOf("login"); //����� �������
	const int passwordIndex = rec.indexOf("password");
	const int accessIndex = rec.indexOf("access");

	while (query.next()) {
		qDebug ()<< query.value(loginIndex) << '\t' << query.value(passwordIndex )<<'\t' << query.value(accessIndex);;

	}
	//������� �������
	//query.exec("DROP TABLE User");
	//������� ���� ������
	db.close();
	return a.exec();

}

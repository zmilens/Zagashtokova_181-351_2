#include "DataBase.h"
#include <vector>
#include <QtCore/QCoreApplication>
#include<QSQlDatabase> 
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QVariant>



DataBase::DataBase()
{

}


bool checkTopic(std::string topic) {
	QString uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	QString lowercase = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < topic.length(); i++) {
		if (!(uppercase.contains(topic[i]))) {
			if (lowercase.contains(topic[i]))
				topic[i] = toupper(topic[i]);
			else return false;
		}
	}
	return true;
}
bool checkAuthor(std::string author) {
	QString uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	QString lowercase = "abcdefghijklmnopqrstuvwxyz";
	if (!(uppercase.contains(author[0]))) {
		if (lowercase.contains(author[0]))
			author[0] = toupper(author[0]);
		else return false;
	}
	for (int i = 1; i < author.length(); i++) {
		if (!(lowercase.contains(author[i]))) {
			if (uppercase.contains(author[i]))
				author[i] = tolower(author[i]);
			else return false;
		}
	}
	return true;
}
bool checkArticle(std::string article) {
	QString uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	QString lowercase = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < article.length(); i++) {
		if (!(lowercase.contains(article[i]))) {
			if (uppercase.contains(article[i]))
				article[i] = tolower(article[i]);
			else return false;
		}
	}
	return true;

}
bool checkMag(std::string magazine) {
	QString uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	QString lowercase = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < magazine.length(); i++) {
		if (!(uppercase.contains(magazine[i]))) {
			if (lowercase.contains(magazine[i]))
				magazine[i] = toupper(magazine[i]);
			else return false;
		}
	}
	return true;
}

void DataBase::download() {
	std::string res;
	download(res);
	transformStr2BD(res);
}

void DataBase::downloadlogpas() {
	std::string res;
	downloadlogpas(res);
	transformStr2BDlogpas(res);
}

void DataBase::download(std::string & res)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Test");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "open";

	QSqlQuery query(db);
	query.exec("CREATE TABLE Database (topic VARCHAR(20) NOT NULL,"
		"author VARCHAR(20) NOT NULL, article VARCHAR(15) NOT NULL,"
		"magazine VARCHAR(15) NOT NULL)");

	query.exec("SELECT * FROM Database");
	while (query.next()) {
		res += query.value(0).toString().toStdString() + '\t' + query.value(1).toString().toStdString() + '\t' + query.value(2).toString().toStdString() + '\t' + query.value(3).toString().toStdString() + '\n';
	}
}

void DataBase::downloadlogpas(std::string & res) {
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Logpas");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "open";
	QSqlQuery query(db);
	//query.exec("DROP TABLE User");
	query.exec("CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL,"
		"access VARCHAR(10) NOT NULL)");

	query.exec("SELECT * FROM User");
	while (query.next()) {
		res += query.value(0).toString().toStdString() + '\t' + query.value(1).toString().toStdString() + '\t' + query.value(2).toString().toStdString() + '\n';
	}

}
bool DataBase::add_data(data tempData)
{
	db.push_back(tempData);
	return true;
}
bool DataBase::add_datalogpas(data tempData)
{
	db1.push_back(tempData);
	return true;
}
void DataBase::transformStr2BDlogpas(std::string bd)
{
	int i = 0;
	data data;
	std::string temp;
	for (;;) {
		if (i >= bd.size())
			break;
		while (bd[i] != '\t') {
			temp += bd[i];
			i++;
		}
		data.log = temp;
		temp.clear();
		i++;
		if (i >= bd.size())
			break;
		while (bd[i] != '\t') {
			temp += bd[i];
			i++;
		}
		data.pass = temp;
		temp.clear();
		i++;
		if (i >= bd.size())
			break;
		while (bd[i] != '\n') {
			temp += bd[i];
			i++;
			if (i >= bd.size())
				break;
		}
		data.access = temp;
		temp.clear();
		i++;
		add_datalogpas(data);
	}
}

bool DataBase::del_data(int id)
{
	QSqlQuery query;

	// �������� ���������� �� id ������, ������� ���������� � �������� ��������� �������
	query.prepare("DELETE FROM Test WHERE id= :ID ;");
	query.bindValue(":ID", id);
	// ��������� ��������
	if (!query.exec()) {
		//qDebug() << "error delete row " << Test;
		qDebug() << query.lastError().text();
		return false;
	}
	else {
		return true;
	}

}

void DataBase::transformStr2BD(std::string bd)
{
	int i = 0;
	data data;
	std::string temp;
	for (;;) {
		if (i >= bd.size())
			break;
		while (bd[i] != '\t') {
			temp += bd[i];
			i++;
		}
		data.topic = temp;
		temp.clear();
		i++;
		if (i >= bd.size())
			break;
		while (bd[i] != '\t') {
			temp += bd[i];
			i++;
		}
		data.author = temp;
		temp.clear();
		i++;
		if (i >= bd.size())
			break;
		while (bd[i] != '\t') {
			temp += bd[i];
			i++;
		}
		data.article = temp;
		temp.clear();
		i++;
		if (i >= bd.size())
			break;
		while (bd[i] != '\n') {
			temp += bd[i];
			i++;
			if (i >= bd.size())
				break;
		}
		data.magazine = temp;
		temp.clear();
		i++;
		add_data(data);
	}
}

void DataBase::finding(std::string finder)
{
	std::string f;
	for (int i = 0; i < db.size(); i++) {
		if ((db[i].topic == finder || db[i].author == finder || db[i].article == finder || db[i].magazine == finder)) {
			f += db[i].topic + '\t' + db[i].author + '\t' + db[i].article + '\t' + db[i].magazine + '\n';
		}
	}

	db.clear();
	transformStr2BD(f);
}

void DataBase::findinglogpas(std::string finder)
{
	std::string f;
	for (int i = 0; i < db1.size(); i++) {
		if ((db1[i].log == finder || db1[i].pass == finder || db1[i].access == finder)) {
			f += db1[i].log + '\t' + db1[i].pass + '\t' + db1[i].access + '\n';
		}
	}

	db1.clear();
	transformStr2BDlogpas(f);
}
/*bool DataBase::write2file()
{

	QFile file("DataBase.txt");
	if ((file.exists()) && (file.open(QIODevice::WriteOnly | QIODevice::Text))) {
		QTextStream writeStream(&file);
		db_string.clear();
		for (int i = 0; i < db.size(); i++)
		{
			db_string += db[i].topic + "\t" + db[i].author + "\t" + db[i].article + "\t" + db[i].magazine + "\n";
		}
		QString str = str.fromStdString(db_string);
		writeStream << str;
		file.close();
		return true;
	}
	else return false;
}*/

QString autorize(QString login, QString password)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("Logpas");
	if (!db.open())
		qDebug() << db.lastError().text();
	else
		qDebug() << "open";
	QSqlQuery query(db);

	query.exec("CREATE TABLE User(login VARCHAR(20) NOT NULL, password VARCHAR(20) NOT NULL, access VARCHAR(10) NOT NULL)");
	query.prepare("INSERT INTO User(login, password, access) VALUES (:login, :password, :access)");
	query.clear();
	if (query.exec("SELECT * FROM User")) {
		while (query.next()) {
			if ((login == query.value(0).toString()) && (password == query.value(1).toString())) {
				if (query.value(2) == "Admin") {
					db.close();
					return "Admin";
				}
				else if (query.value(2) == "Manager") {
					db.close();
					return "Manager";
				}
				else if (query.value(2) == "User") {
					db.close();
					return "User";
				}
			}
		}
	}
	db.close();
	return "False";
}
DataBase::~DataBase() {}
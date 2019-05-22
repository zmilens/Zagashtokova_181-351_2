#pragma once

#include <string> 
#include <vector> 
#include <QTextStream> 
#include <sstream>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
struct data {
	std::string topic; //����
	std::string author; //�����
	std::string article; //������
	std::string magazine; //������
	std::string log;
	std::string pass;
	std::string access;
};


std::string checkTopic(std::string topic);
std::string checkAuthor(std::string author);
std::string checkArticle(std::string article);
std::string checkMag(std::string magazine);
std::string checkAccess(std::string access);


class DataBase {

public:
	std::vector<data> db;
	std::vector<data> db1;
	DataBase();//����������� 
	DataBase(std::string* tempDB); //����������� �� ������: �.�. �� ������, � ������� �������� ��, ��������� �� 
	~DataBase();//����������* 
	bool add_data(data tempData);// �������� ������ ������ � �� 
	bool add_datalogpas(data tempData);
	void download(std::string & res); //��������� ������ �� ����� � ������
	void download();
	data parsing(std::string line);
	void transformStr2BD(std::string bd);// ����������� ������ � �� 
	bool del_data(int id);//������� ������ � �������� id 
	void finding(std::string find);
	void downloadlogpas(std::string & res);
	void downloadlogpas();
	void transformStr2BDlogpas(std::string bd);
	void findinglogpas(std::string finder);


private:
	std::string bd;
};

QString autorize(QString login, QString password);



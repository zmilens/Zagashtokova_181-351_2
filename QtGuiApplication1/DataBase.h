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


bool checkTopic(std::string topic);
bool checkAuthor(std::string author);
bool checkArticle(std::string article);
bool checkMag(std::string magazine);

class DataBase {

public:
	std::vector<data> db;
	std::vector<data> db1;
	DataBase();//����������� 
	DataBase(std::string* tempDB); //����������� �� ������: �.�. �� ������, � ������� �������� ��, ��������� �� 
	~DataBase();//����������* 
	bool add_data(data tempData);// �������� ������ ������ � �� 
	bool add_datalogpas(data tempData);
	//bool open(QFile file);//��������� ���� 
	//bool download(std::string & res);//��������� ������ �� ����� � ������ 
	//bool close();// �������� ����� 
	void download(std::string & res); //��������� ������ �� ����� � ������
	void download();
	data parsing(std::string line);
	void transformStr2BD(std::string bd);// ����������� ������ � �� 
	bool del_data(int id);//������� ������ � �������� id 
	void finding(std::string find);
	//template<typename T>
	//std::vector<data> find(int criterior, T data2find);//������� ������ � �������� id 
	void downloadlogpas(std::string & res);
	void downloadlogpas();
	void transformStr2BDlogpas(std::string bd);
	void findinglogpas(std::string finder);
	bool write2file();

private:
	std::string bd;
};



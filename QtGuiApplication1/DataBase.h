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
	std::string topic; //тема
	std::string author; //автор
	std::string article; //статья
	std::string magazine; //журнал
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
	DataBase();//конструктор 
	DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД 
	~DataBase();//деструктор* 
	bool add_data(data tempData);// добавить строку данных в БД 
	bool add_datalogpas(data tempData);
	//bool open(QFile file);//открываем файл 
	//bool download(std::string & res);//загружаем данные из файла в строку 
	//bool close();// закрытие файла 
	void download(std::string & res); //загружаем данные из файла в строку
	void download();
	data parsing(std::string line);
	void transformStr2BD(std::string bd);// преобразует строку в БД 
	bool del_data(int id);//удалить запись с заданным id 
	void finding(std::string find);
	//template<typename T>
	//std::vector<data> find(int criterior, T data2find);//удалить запись с заданным id 
	void downloadlogpas(std::string & res);
	void downloadlogpas();
	void transformStr2BDlogpas(std::string bd);
	void findinglogpas(std::string finder);
	bool write2file();

private:
	std::string bd;
};



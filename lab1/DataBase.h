#ifndef DATABASE_H 
#define DATABASE_H 
#include <string> 
#include <vector> 
#include <QFile> 




struct data {
	std::string topic; //тема
	std::string author; //автор
	std::string article; //статья
	std::string magazine; //журнал
};

bool check(std::string topic);
bool check(std::string author);
bool check(std::string article);
bool check(std::string magazine);

class DataBase {

public:
	std::vector<data> db;
	DataBase();//конструктор 
	DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД 
	~DataBase();//деструктор* 
	bool add_data(data tempData);// добавить строку данных в БД 
	bool open(QFile file);//открываем файл 
	bool download(std::string & res);//загружаем данные из файла в строку 
	bool close();// закрытие файла 
	void download();
	data parsing(std::string line);
	void transformStr2BD(std::string bd);// преобразует строку в БД 

	bool del_data(int id);//удалить запись с заданным id 

	template<typename T>
	std::vector<data> find(int criterior, T data2find);//удалить запись с заданным id 


	bool write2file();

private:
	std::string db_string;
};

#endif 

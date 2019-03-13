#pragma once
#include <string>
#include <vector>

std::string FileName = "DataBase.txt";

struct data {
	std::string topic; //тема
	std::string author; //автор
	std::string aricle; //статья 
	std::string magazine; //журнал
};

bool check(std::string topic)//Используемые символы - только буквы;
{	
	for (int i = 0; i <strlen(topic) ; i++) //проверка на буквы
	{
		if (isalpha(topic[i]) == 0)
			correct false;
	}
}

class DataBase {
public:
	DataBase();//конструктор
	DataBase(std::string* tempDB); //конструктор по строке: т.е. по строке, в которой записана БД, формируем БД
	~DataBase();//деструктор
	bool add_data(data tempData);// добавить строку данных в БД
	bool open(std::string filename);//открываем файл
	bool download(std::string & res);//загружаем данные из файла в строку
	bool close();// закрытие файла

	data parsing(std::string line);
	bool transformStr2BD(std::string strFromFile)// преобразует строку в БД
	{
		//Цикл по входной строке
		std::string line;//взять первую запись из файла
		//line = ...
		data tempData;
		tempData = parsing(line);
		add_data(tempData);
	}


	bool download()//загружаем данные из файла в строку
	{
		std::string strFromFile;
		open(FileName);
		download(strFromFile);
		close();
		transformStr2BD(strFromFile);
	}

	bool del_data(std::string id);//удалить запись с заданным id

	template<typename T>
	vector<data> find(int criterior, T data2find);//удалить запись с заданным id

	bool change(std::string id, data tempData)
	{
		//db[id] = tempData;
	}

	bool write2file();

private:
	vector<data> *db;
	FILE* fin;

protected:


}
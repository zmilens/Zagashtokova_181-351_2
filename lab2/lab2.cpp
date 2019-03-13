#include "lab2.h"

lab2::lab2(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
#include <string>
#include <vector>
using namespace std;
string DataBase;
struct data
{
	string fio;
	string tel;
	string date;
};
bool checkFio(string fio); //Используем буквы только, если регистр не тот, то меняем на правильный
bool checkTel(string tel); //десять символов все цифры
bool checkData(string fio); //тип данных DATE

class DataBase
{
public:
	DataBase(); 
	DataBase(string *tempDB); //конструктор по строке, т.е. по строке, где записана БД формируем БД 
	~DataBase();
	bool add_data(data tempData);
	bool open(string filename); // открытваем файл 
	bool download(FILE* fin, string & res); //загружаем данные из файла в строку
	bool close(FILE * fin); //закрытие файла 
	bool transformStr2BD()
	{	//взять первую строку 
		parsing()
	};
	bool parsing();

	bool download(FILE* fin) ////загружаем данные из файла в строку
	{	
		string strFromFile;
		open(FileName);
		download(strFromFile);
		close();

	}
private:
vector<data> *db;
FILE *fin;
};
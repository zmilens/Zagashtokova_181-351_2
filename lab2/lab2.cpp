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
bool checkFio(string fio); //���������� ����� ������, ���� ������� �� ���, �� ������ �� ����������
bool checkTel(string tel); //������ �������� ��� �����
bool checkData(string fio); //��� ������ DATE

class DataBase
{
public:
	DataBase(); 
	DataBase(string *tempDB); //����������� �� ������, �.�. �� ������, ��� �������� �� ��������� �� 
	~DataBase();
	bool add_data(data tempData);
	bool open(string filename); // ���������� ���� 
	bool download(FILE* fin, string & res); //��������� ������ �� ����� � ������
	bool close(FILE * fin); //�������� ����� 
	bool transformStr2BD()
	{	//����� ������ ������ 
		parsing()
	};
	bool parsing();

	bool download(FILE* fin) ////��������� ������ �� ����� � ������
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
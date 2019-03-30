#ifndef DATABASE_H 
#define DATABASE_H 
#include <string> 
#include <vector> 
#include <QFile> 




struct data {
	std::string topic; //����
	std::string author; //�����
	std::string article; //������
	std::string magazine; //������
};

bool check(std::string topic);
bool check(std::string author);
bool check(std::string article);
bool check(std::string magazine);

class DataBase {

public:
	std::vector<data> db;
	DataBase();//����������� 
	DataBase(std::string* tempDB); //����������� �� ������: �.�. �� ������, � ������� �������� ��, ��������� �� 
	~DataBase();//����������* 
	bool add_data(data tempData);// �������� ������ ������ � �� 
	bool open(QFile file);//��������� ���� 
	bool download(std::string & res);//��������� ������ �� ����� � ������ 
	bool close();// �������� ����� 
	void download();
	data parsing(std::string line);
	void transformStr2BD(std::string bd);// ����������� ������ � �� 

	bool del_data(int id);//������� ������ � �������� id 

	template<typename T>
	std::vector<data> find(int criterior, T data2find);//������� ������ � �������� id 


	bool write2file();

private:
	std::string db_string;
};

#endif 

/*#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::string FileName = "DataBase.txt";

struct data {
	std::string fio;
	std::string tel;
	std::string date;
};

bool checkFio(std::string fio) {};//������������ ������� - ������ �����; ���� ������� �� ���, ������ �� ����������.
bool checkTel(std::string tel) {};//����� ������ 10 ��������, ��� �� ������� �����;
bool checkDate(std::string date) {};//��� ������ Date

class DataBase {

public:
	DataBase();//�����������
	DataBase(std::string* tempDB); //����������� �� ������: �.�. �� ������, � ������� �������� ��, ��������� ��
	~DataBase();//����������
	bool add_data(data tempData) {};// �������� ������ ������ � ��
	bool open(std::string filename) {};//��������� ����
	bool download(std::string & res) {};//��������� ������ �� ����� � ������
	bool close() {};// �������� �����

	data parsing(std::string line) {};
	bool transformStr2BD(std::string strFromFile)// ����������� ������ � ��
	{
		//���� �� ������� ������
		std::string line;//����� ������ ������ �� �����
		//line = ...
		data tempData;
		tempData = parsing(line);
		add_data(tempData);
	}


	bool download()//��������� ������ �� ����� � ������
	{
		std::string strFromFile;
		open(FileName);
		download(strFromFile);
		close();
		transformStr2BD(strFromFile);
	}

	bool del_data(std::string id) {};//������� ������ � �������� id

	template<typename T>
	vector<data> find(int criterior, T data2find);//������� ������ � �������� id

	bool change(std::string id, data tempData)
	{
		//db[id] = tempData;
	}

	bool write2file();

private:
	vector<data> *db;
	FILE* fin;
};

*/
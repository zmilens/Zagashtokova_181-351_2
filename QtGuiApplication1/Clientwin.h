#pragma once
#include "crypto.h"
#include <QDialog>
#include "ui_Clientwin.h"
#include <QStandardItemModel>
#include <QSqlTableModel>
#include "DataBase.h"
#include <QTcpSocket>


class Clientwin : public QDialog
{
	Q_OBJECT

public:
	Clientwin(QWidget *parent = Q_NULLPTR);
	~Clientwin();
	void take_socket(QTcpSocket *sock);
private slots:
	void on_pushButton_find_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_clicked();
	void ready_read();
	void send_server(QString com);
	//void take_socket();
	void disconnected();
private:
	Ui::Clientwin ui;
	QStandardItemModel *model;
	QSqlTableModel *mod;
	QTcpSocket *socket;
	DataBase base;

};

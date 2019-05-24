#pragma once
#include "crypto.h"
#include <QDialog>
#include "ui_Managerwin.h"
#include <QTcpSocket>
#include <QStandardItemModel>
#include <QSqlTableModel>
#include "DataBase.h"


class Managerwin : public QDialog
{
	Q_OBJECT

public:
	Managerwin(QWidget *parent = Q_NULLPTR);
	~Managerwin();
	void take_socket(QTcpSocket *sock);
private slots:
	void on_pushButton_add_clicked();
	void on_pushButton_delete_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_find_clicked();
	void on_pushButton_clicked();
	void ready_read();
	void send_server(QString com);
	void disconnected();
private:
	Ui::Managerwin ui;
	QStandardItemModel *model;
	QTcpSocket *socket;
	QSqlTableModel *mod;
	DataBase base;
};


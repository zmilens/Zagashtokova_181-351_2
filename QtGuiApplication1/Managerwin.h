#pragma once

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
	//void sendServer(QString com);
private slots:
	void on_pushButton_add_clicked();
	//void on_pushButton_delete_clicked();
	void on_pushButton_find_clicked();
	void on_pushButton_clicked();
private:
	Ui::Managerwin ui;
	QTcpSocket * s;
	QStandardItemModel *model;
	QSqlTableModel *mod;
};


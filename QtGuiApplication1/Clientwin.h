#pragma once

#include <QDialog>
#include "ui_Clientwin.h"
#include <QStandardItemModel>
#include <QSqlTableModel>
#include "DataBase.h"

class Clientwin : public QDialog
{
	Q_OBJECT

public:
	Clientwin(QWidget *parent = Q_NULLPTR);
	~Clientwin();
private slots:
	void on_pushButton_find_clicked();
	void on_pushButton_clicked();
private:
	Ui::Clientwin ui;
	QStandardItemModel *model;
	QSqlTableModel *mod;
};

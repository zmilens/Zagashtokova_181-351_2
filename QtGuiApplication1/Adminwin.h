#pragma once

#include <QDialog>
#include "ui_Adminwin.h"
#include <QStandardItemModel>
#include <QSqlTableModel>

class Adminwin : public QDialog
{
	Q_OBJECT

public:
	Adminwin(QWidget *parent = Q_NULLPTR);
	~Adminwin();
private slots:
	void on_pushButton_find_clicked();
	void on_pushButton_clicked();
private:
	Ui::Adminwin ui;
	QStandardItemModel *model1;
	QSqlTableModel *mod1;
};

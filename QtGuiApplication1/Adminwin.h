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

private:
	Ui::Adminwin ui;
	QStandardItemModel *model1;
	QSqlTableModel *mod1;
};

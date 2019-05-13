#pragma once

#include <QDialog>
#include "ui_prosmotr.h"
#include <QStandardItemModel>

class prosmotr : public QDialog
{
	Q_OBJECT

public:
	prosmotr(QWidget *parent = Q_NULLPTR);
	~prosmotr();

private:
	Ui::prosmotr ui;
	QStandardItemModel *model;
private slots:
	void on_prosm_triggered();

};

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab1.h"

class lab1 : public QMainWindow
{
	Q_OBJECT

public:
	lab1(QWidget *parent = Q_NULLPTR);

private:
	Ui::lab1Class ui;
private slots: 
	void On_pushButton_autorize_clicked();

};

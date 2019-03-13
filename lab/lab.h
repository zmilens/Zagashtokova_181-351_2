#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab.h"

class lab : public QMainWindow
{
	Q_OBJECT

public:
	lab(QWidget *parent = Q_NULLPTR);

private:
	Ui::labClass ui;
private slots:
	void On_pushButton_autorize_clicked();
};
class lab1 : public QMainWindow


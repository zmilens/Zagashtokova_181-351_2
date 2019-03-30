#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab1.h"
#include "managerwin.h"
#include "clientwin.h"

class lab1 : public QMainWindow
{
	Q_OBJECT

public:
	lab1(QWidget *parent = Q_NULLPTR);

private:
	Ui::lab1Class ui;
	managerwin *manwin;
	clientwin *cliwin;
	prosmotr *proscli;
private slots: 
	void on_pushButton_autorize_clicked();
};

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab2.h"

class lab2 : public QMainWindow
{
	Q_OBJECT

public:
	lab2(QWidget *parent = Q_NULLPTR);

private:
	Ui::lab2Class ui;
};

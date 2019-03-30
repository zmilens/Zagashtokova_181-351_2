#pragma once

#include <QDialog>
#include "ui_clientwin.h"

class clientwin : public QDialog
{
	Q_OBJECT

public:
	clientwin(QWidget *parent = Q_NULLPTR);
	~clientwin();

private:
	Ui::clientwin ui;

};

#pragma once

#include <QDialog>
#include "ui_Clientwin.h"

class Clientwin : public QDialog
{
	Q_OBJECT

public:
	Clientwin(QWidget *parent = Q_NULLPTR);
	~Clientwin();

private:
	Ui::Clientwin ui;
};

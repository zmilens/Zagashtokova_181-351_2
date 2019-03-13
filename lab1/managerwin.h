#pragma once

#include <QDialog>
#include "ui_managerwin.h"

class managerwin : public QDialog
{
	Q_OBJECT

public:
	managerwin(QWidget *parent = Q_NULLPTR);
	~managerwin();

private:
	Ui::managerwin ui;
};

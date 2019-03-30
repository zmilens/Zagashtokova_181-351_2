#pragma once

#include <QDialog>
#include "ui_prosmotr.h"

class prosmotr : public QDialog
{
	Q_OBJECT

public:
	prosmotr(QWidget *parent = Q_NULLPTR);
	~prosmotr();

private:
	Ui::prosmotr ui;
};

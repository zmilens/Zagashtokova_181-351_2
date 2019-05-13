#pragma once

#include <QDialog>
#include "ui_find.h"

class finder : public QDialog
{
	Q_OBJECT

public:
	finder(QWidget *parent = Q_NULLPTR);
	~finder();
private:
	Ui::find ui;
};


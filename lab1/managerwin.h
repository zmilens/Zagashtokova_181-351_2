#pragma once

#include <QDialog>
#include "ui_managerwin.h"
#include "redact.h"
#include "prosmotr.h"

class managerwin : public QDialog
{
	Q_OBJECT

public:
	managerwin(QWidget *parent = Q_NULLPTR);
	~managerwin();
	

private:
	Ui::managerwin ui;
	redact *red;
	prosmotr *pros;
	
private slots: 
	void on_pushprosmotr_clicked();
	void on_pushredact_clicked();
};

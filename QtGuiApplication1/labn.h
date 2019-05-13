#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_labn.h"
#include "Adminwin.h"
#include "Managerwin.h"
#include "Clientwin.h"

class labn : public QMainWindow
{
	Q_OBJECT

public:
	labn(QWidget *parent = Q_NULLPTR);

private:
	Ui::labnClass ui;
	Managerwin *manwin;
	Clientwin *cliwin;
	Adminwin *admwin;
private slots:
	void on_pushButton_autorize_clicked();
};

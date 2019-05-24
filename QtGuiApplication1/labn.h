#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_labn.h"
#include "Adminwin.h"
#include "Managerwin.h"
#include "Clientwin.h"
#include <sstream>
#include <QTcpSocket>
#include "DataBase.h"

class labn : public QMainWindow
{
	Q_OBJECT

public:
	labn(QWidget *parent = Q_NULLPTR);

private:
	Ui::labnClass ui;
	QTcpSocket *socket;
	Managerwin *manwin;
	Clientwin *cliwin;
	Adminwin *admwin;
private slots:
	void on_pushButton_autorize_clicked();
	void connected();
	void disconnected();
	void ready_read();
	void send_server(QString com);
	//void take_socket();

};

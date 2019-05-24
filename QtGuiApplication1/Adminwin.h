#pragma once

#include "crypto.h"
#include "DataBase.h"
#include <QDialog>
#include "ui_Adminwin.h"
#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QTcpSocket>
#include <qcryptographichash.h>

class Adminwin : public QDialog
{
	Q_OBJECT

public:
	Adminwin(QWidget *parent = Q_NULLPTR);
	~Adminwin();
	void take_socket(QTcpSocket *sock);

private slots:
	void on_pushButton_find_clicked();
	void on_pushButton_add_clicked();
	void on_pushButton_delete_clicked();
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void ready_read();
	void send_server(QString message);
	void disconnected();

private:
	Ui::Adminwin ui;
	QStandardItemModel *model1;
	QSqlTableModel *mod1;
	QTcpSocket *socket;
	DataBase base;


};

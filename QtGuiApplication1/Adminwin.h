#pragma once

#include <QDialog>
#include "ui_Adminwin.h"
#include <QStandardItemModel>
#include <QSqlTableModel>
#include <QTcpSocket>


class Adminwin : public QDialog
{
	Q_OBJECT

public:
	Adminwin(QWidget *parent = Q_NULLPTR);
	~Adminwin();
private slots:
	void on_pushButton_find_clicked();
	void on_pushButton_add_clicked();
	void on_pushButton_delete_clicked();
	void on_pushButton_clicked();
	void connected();
	void ready_read();
	void send_server(QString message);

private:
	Ui::Adminwin ui;
	QStandardItemModel *model1;
	QSqlTableModel *mod1;
	QTcpSocket *socket;

};

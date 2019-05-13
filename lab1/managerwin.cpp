#include "managerwin.h"
#include "redact.h"
#include "prosmotr.h"


managerwin::managerwin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
}

managerwin::~managerwin()
{
}

void managerwin::on_pushredact_clicked()
{
	this->close();
	red = new redact();
	red->show();
}

void managerwin:: on_pushprosmotr_clicked() {
	this->close();
	pros = new prosmotr();
	pros->show();

}

void managerwin:: on_pushfind_cliked() {
	this->close();
	fin = new finder();
	fin->show();
	
}



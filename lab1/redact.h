#pragma once

#include <QDialog>
#include "ui_redact.h"

class redact : public QDialog
{
	Q_OBJECT

public:
	redact(QWidget *parent = Q_NULLPTR);
	~redact();

private:
	Ui::redact ui;

};

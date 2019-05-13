#include "redact.h"
#include "DataBase.h"

redact::redact(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

redact::~redact()
{
}

/*
void redact::addrecord()
{
	struct text;
	QString a = ui.lineTopic->text();
	if (a != NULL) 
	{
		text.topic = a.toStdString();
		QString b = ui.lineAuthor->text();
		text.author= b.toStdString();
		if (checkAuthor(text.author) == true)
		{
			QString c = ui.lineArticle->text();
			text.article = c.toStdString();
		}


	}


}*/

#include "labn.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	labn w;
	w.show();
	return a.exec();
}

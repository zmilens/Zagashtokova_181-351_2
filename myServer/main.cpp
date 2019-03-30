#include <QtCore/QCoreApplication>
#include "myTcpServer.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	myTcpServer server;
	return a.exec();
}

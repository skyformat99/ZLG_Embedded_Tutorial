/*-----------------------------------------
 * main.cpp -- show the Snake Game.
 *             by Codebreaker, 2015, 1,7
 *----------------------------------------*/

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow main;
	main.show();
	return app.exec();
}

/* main.cpp */

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow main;						/* 创建自定义的MainWindow对象 */
	main.show();							/* 使对象显示 */
	return app.exec();
}


/* main.cpp */

#include <QApplication>
#include "coordinate_label.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	CoordinateLabel *myLabel = new CoordinateLabel;
	myLabel->setWindowTitle("Mouse Event Demo");			/* 设置窗口标题 */
	myLabel->resize(300,200);							/* 设置自定义的窗口部件尺寸*/
	myLabel->show();
	return app.exec();
}


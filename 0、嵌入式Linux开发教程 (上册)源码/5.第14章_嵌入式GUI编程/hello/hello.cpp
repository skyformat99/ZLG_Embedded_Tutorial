	#include <QtGui>					/*包含Qt Gui类的定义，省去分别包含不同类的麻烦 */
	int main(int argc, char *argv[])
	{
		QApplication app(argc, argv);
		QLabel label("hello, world");		/*创建一个显示“hello, world”的QLabel窗口部件*/
		label.show();					/* 显示标签 */
		return app.exec();
	}


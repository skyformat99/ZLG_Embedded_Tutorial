/* account.cpp */
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *window = new QWidget;					/* 创建Qwidget对象，作为主窗口*/
	window->setWindowTitle("Enter Your account");			/*设置显示在窗口标题栏上的文字*/

	QLabel *accountLabel = new QLabel("Account: ",  window); /*创建标签对象，并显示为Accoutn */
	QLineEdit *accountEdit = new QLineEdit(window);			/* 创建文本框对象 */

	QHBoxLayout *layout = new QHBoxLayout;				/* 创建水平布局管理器 */
	layout->addWidget(accountLabel);
	layout->addWidget(accountEdit);

	window->setLayout(layout);							/* window窗口上安装该布局管理*/
	window->show();
	return app.exec();
}


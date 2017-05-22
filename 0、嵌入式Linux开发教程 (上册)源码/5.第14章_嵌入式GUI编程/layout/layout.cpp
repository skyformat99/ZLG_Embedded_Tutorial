/* layout.cpp */
#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *window = new QWidget;
	window->setWindowTitle("Layout");

	QLabel *accountLabel    = new QLabel("Account: ");
	QLabel *pwLabel         = new QLabel("Password: ");
	QLineEdit *accountEdit  = new QLineEdit;
	QLineEdit *pwEdit       = new QLineEdit;
	QPushButton *quitButton = new QPushButton("Quit");
	QPushButton *nextButton = new QPushButton("Next");

	QHBoxLayout *topLayout  = new QHBoxLayout;			/* 创建一个水平布局管理器 */
	topLayout->addWidget(accountLabel);					/* 从左到右放置窗口部件 */
	topLayout->addWidget(accountEdit);

	QHBoxLayout *downLayout = new QHBoxLayout;
	downLayout->addWidget(pwLabel);
	downLayout->addWidget(pwEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;			/* 创建一个垂直布局管理器 */
	leftLayout->addLayout(topLayout);					/* 内嵌布局管理器 */
	leftLayout->addLayout(downLayout);
	leftLayout->addStretch();							/* 添加分隔符 */

	QVBoxLayout *rightLayout = new QVBoxLayout;			/* 创建一个垂直布局管理器 */
	rightLayout->addWidget(quitButton);					/* 从上到下放置窗口部件 */
	rightLayout->addWidget(nextButton);
	rightLayout->addStretch();

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);

	QObject::connect(quitButton, SIGNAL(clicked()), &app, SLOT(quit()));
	window->setLayout(mainLayout);
	window->show();
	return app.exec();
}


/* number.cpp */
#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *window = new QWidget;
	window->setWindowTitle("Enter Number");

	QSpinBox *spinBox = new QSpinBox;						/* 创建微调框 */
	QSlider *slider = new QSlider(Qt::Horizontal);				/* 创建滑块 */
	spinBox->setRange(0, 100);								/* 设置微调框有效范围 */
	slider->setRange(0, 100);								/* 设置滑块有效范围 */

	QObject::connect(spinBox, SIGNAL(valueChanged(int)),slider, SLOT(setValue(int)));
	QObject::connect(slider, SIGNAL(valueChanged(int)),spinBox, SLOT(setValue(int)));
	spinBox->setValue(25);								/* 设置微调框的值为25 */

	QHBoxLayout *layout = new QHBoxLayout;					/* 创建水平布局管理器 */
	layout->addWidget(spinBox);							/* 从左到右放置部件 */
	layout->addWidget(slider);
	window->setLayout(layout);

	window->show();

	return app.exec();
}


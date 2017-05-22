#include <QtGui>
int main(int argc,char *argv[])
{
	QApplication	app(argc,argv);

	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
	QLabel	label(QString("hellow qt"));
	label.show();
	app.exec();
}

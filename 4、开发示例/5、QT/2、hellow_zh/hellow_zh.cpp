#include <QtGui>
int main(int argc,char *argv[])
{
	QApplication	app(argc,argv);

	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	char *info = "you should see some chinese words: 你好，世界";
	QString infoString = info;
	QLabel	label(infoString);
	label.show();
	app.exec();
}

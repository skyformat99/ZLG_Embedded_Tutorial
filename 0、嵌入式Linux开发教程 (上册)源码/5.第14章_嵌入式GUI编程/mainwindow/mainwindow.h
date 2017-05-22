/* mainwindow.h */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>					/* 包含对QMainWindow的定义 */

class QAction;
class QMenu;
class QToolBar;
class QLabel;

class MainWindow : public QMainWindow		/* 声明MainWindow为QMainWindow的子类*/
{
	Q_OBJECT;
public:
	MainWindow(void);
	~MainWindow(void);

private:
	QMenu   *fileMenu;					/* 文件菜单 */
	QMenu   *helpMenu;				/* 帮助菜单 */

	QToolBar *fileToolBar;				/* 工具栏 */

	QAction *openAction;					/* 打开动作 */
	QAction *closeAction;					/* 关闭动作 */
	QAction *aboutAction;				/* 关于动作 */

	QLabel  *statusLabel;
};

#endif


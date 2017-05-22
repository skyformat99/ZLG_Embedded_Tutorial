/*mainwindow.h */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screen.h"

class Screen;
class QPushButton;
class QLabel;

class MainWindow : public QMainWindow			/*  QMainWindow的子类MainWindow */
{
	Q_OBJECT;

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow(void);

private slots:
	void showHelp(void);								/* 显示帮助信息*/
	void showAbout(void);							/* 显示关于信息*/

private:
	void createMenu(void);							/* 创建菜单栏*/

	QMenu *gameMenu;								/* 游戏菜单 */
	QMenu *helpMenu;								/* 帮助菜单 */
	QToolBar *toolBar;								/* 工具栏*/

	QAction *startAction;								/* 开始动作 */
	QAction *pauseAction;							/* 暂停动作 */
	QAction *continueAction;							/* 继续动作 */
	QAction *speedupAction;							/* 加速动作 */
	QAction *speeddownAction;						/* 减速动作 */
	QAction *helpGameAction;							/* 游戏帮助动作 */
	QAction *aboutGameAction;						/* 游戏关于动作 */

	QLabel *scoreLabel;								/* 显示分数的标签 */
	QPushButton *upButton;		
	QPushButton *downButton;
	QPushButton *leftButton;
	QPushButton *rightButton;

	Screen *screen;									/* 游戏界面 */
};

#endif


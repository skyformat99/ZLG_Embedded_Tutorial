/* mainwindow.cpp */
#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
		: QMainWindow(parent)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));  /* 设置字体，以显示中文*/
	setWindowTitle(tr("贪食蛇游戏"));						/* 设置标题 */

	screen = new Screen(this);
	setCentralWidget(screen);								/* 设置中央窗口为screen */
	createMenu();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenu(void)
{
	startAction = new QAction(tr("开始"), this);					/* 创建开始动作 */
	startAction->setShortcut(tr("Ctrl+S"));						/* 设置开始快捷键 */
	connect(startAction, SIGNAL(triggered()), screen, SLOT(startGame()));

	pauseAction = new QAction(tr("暂停"), this);					/* 创建暂停动作 */
	pauseAction->setShortcut(tr("Alt+P"));						/* 设置暂停快捷键 */
	connect(pauseAction, SIGNAL(triggered()), screen, SLOT(pauseGame()));

	continueAction = new QAction(tr("继续"), this);				/* 创建继续动作 */
	continueAction->setShortcut(tr("Alt+C"));					/* 设置继续快捷键 */
	connect(continueAction, SIGNAL(triggered()), screen,SLOT(continueGame()));

	speedupAction = new QAction(tr("加速"), this);				/* 创建加速动作 */
	speedupAction->setShortcut(tr("Ctrl+U"));					/* 加速快捷键 */
	connect(speedupAction, SIGNAL(triggered()), screen, SLOT(speedUp()));

	speeddownAction = new QAction(tr("减速"), this);				/* 创建减速动作 */
	speeddownAction->setShortcut(tr("Ctrl+D"));					/* 减速快捷键 */
	connect(speeddownAction, SIGNAL(triggered()), screen, SLOT(speedDown()));

	helpGameAction = new QAction(tr("帮助"), this);				/* 创建帮助动作 */
	connect(helpGameAction, SIGNAL(triggered()), this, SLOT(showHelp()));

	aboutGameAction = new QAction(tr("关于"), this);				/* 创建关于动作 */
	connect(aboutGameAction, SIGNAL(triggered()), this, SLOT(showAbout()));

	gameMenu = menuBar()->addMenu(tr("游戏"));				/* 创建游戏菜单 */
	gameMenu->addAction(startAction);						/* 添加开始动作 */
	gameMenu->addAction(continueAction);					/* 添加继续动作 */
	gameMenu->addAction(pauseAction);						/* 添加暂停动作 */
	gameMenu->addAction(speedupAction);					/* 添加加速动作 */
	gameMenu->addAction(speeddownAction);					/* 添加减速动作 */

	helpMenu = menuBar()->addMenu(tr("&Help"));				/* 创建帮助菜单 */
	helpMenu->addAction(helpGameAction);					/* 添加游戏帮助动作 */
	helpMenu->addAction(aboutGameAction);					/* 添加游戏关于动作 */

	toolBar = addToolBar(tr("tool"));							/* 创建工具栏 */
	toolBar->addAction(startAction);
	toolBar->addAction(continueAction);
	toolBar->addAction(pauseAction);
	toolBar->addAction(speedupAction);
	toolBar->addAction(speeddownAction);
}

void MainWindow::showAbout(void)
{
	QMessageBox::information(this, tr("关于贪食蛇游戏"),tr("Qt Demo for snake!"));
}

void MainWindow::showHelp(void)
{
	QMessageBox::information(this, tr("游戏帮助"), tr("贪食蛇帮助!"));
}


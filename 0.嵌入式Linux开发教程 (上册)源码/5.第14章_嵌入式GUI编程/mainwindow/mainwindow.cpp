 /* mainwindow.cpp */

 #include <QtGui>
 #include "mainwindow.h"

 MainWindow::MainWindow(void)
{
	openAction = new QAction(tr("&Open"), this);				/* 创建打开动作 */
	openAction->setStatusTip(tr("Open the file"));				/* 设置状态提示 */

	closeAction = new QAction(tr("&Close"), this);				/* 创建关闭动作 */
        closeAction->setStatusTip(tr("Close the file"));			/* 设置状态提示 */

        aboutAction = new QAction(tr("&About"), this);				/* 创建关于动作 */
        aboutAction->setStatusTip(tr("About"));					/* 设置状态提示 */

	fileMenu = menuBar()->addMenu(tr("&File"));				/* 创建file菜单 */
	fileMenu->addAction(openAction);
	fileMenu->addAction(closeAction);

	helpMenu = menuBar()->addMenu(tr("&Help"));				/* 创建help菜单 */
	helpMenu->addAction(aboutAction);

	fileToolBar = addToolBar(tr("&File"));
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(closeAction);
	fileToolBar->addAction(aboutAction);

	statusLabel = new QLabel;
        statusLabel->setMinimumSize(statusLabel->sizeHint());
	statusLabel->setAlignment(Qt::AlignHCenter);

	statusBar()->addWidget(statusLabel);
}

MainWindow::~MainWindow(void)
{
}


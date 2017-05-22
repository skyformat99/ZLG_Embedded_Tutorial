/* screen.h */
#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include "snake.h"

class Snake;
class QTimer;
class QLabel;
class QPushButton;

class Screen :public QWidget
{
	Q_OBJECT;

public:
	Screen(QWidget *parent = 0);
	~Screen(void);

private slots:
	void my_timeout(void);
	void startGame(void);
	void pauseGame(void);
	void continueGame(void);
	void speedUp(void);
	void speedDown(void);
	void upClicked(void);								/* 处理按钮Up点击的槽 */
	void downClicked(void);							/* 处理按钮Down点击的槽 */
	void rightClicked(void);							/* 处理按钮Right点击的槽 */
	void leftClicked(void);								/* 处理按钮Left点击的槽 */

private:
	void paintEvent(QPaintEvent *event);					/* 更新游戏界面 */
	void init_var(void);								/* 初始化变量 */
	void keyPressEvent(QKeyEvent *event);				/* 处理键盘事件的函数*/

	QLabel *scoreLabel;								/* 显示得分的标签 */
	QPushButton *upButton;							/* 向上按钮 */
	QPushButton *downButton;							/* 向下按钮 */
	QPushButton *leftButton;							/* 向左按钮 */
	QPushButton *rightButton;							/* 向右按钮 */

	Snake snake;
	bool IsDie;
	bool IsWin;
	bool IsRun;
	bool IsPause;
	QTimer *timer;									/* 定时器，用于设置更新时间 */
	int times;
	int score;
};

#endif


/* snake.h */
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

using namespace std;

class Node
{
public:
	int x;
	int y;
};

class Snake
{
public:
	Snake(int w = 40, int h = 34);
	~Snake(void);

	void ChangeDirection(const int &NewDirection);		/* 改变移动方向 */
	void Move(void);							/* 移动函数 */
	void init_var();								/* 初始化函数 */
	bool IsDie(void);								/* 返回是否死了 */
	bool IsWin(void);							/* 返回是否赢了 */
	void getCoordinate(vector<Node>&node, Node &food);	/* 输出Snake的坐标和果实的坐标*/
	int getScore(void);							/* 返回得分 */
	void Clear();								/* 清理函数 */

private:
	void Judge(void);							/* 判断是否死了 */
	void AddNode(const int &w, const int &n);			/* 增加Snake的节点即身体变长 */
	void PutFood(void);							/* 随机放置果实的坐标 */

	vector<Node> SnakeNode;						/* 保存Snake身体的每个节点坐标 */
	Node Food;								/* 果实的坐标 */
	int direction;      							/* 1: up 2: right 3: down 4: left */
	int length;         							/* Snake身体的长度 */
	int maxlength;      						/*Snake的最大长度，等于这个长度就胜利 */
	bool die;
	bool win;
	/* Snake移动的范围 */
	int height;
	int width;
};

#endif


/* snake.cpp */
#include <cstdlib>
#include <ctime>
#include "snake.h"

Snake::Snake(int w, int h)
{
	if(w > 0 && h > 0) {
		width  = w;
		height = h;
	}
	else {
		width  = 50;
		height = 50;
	}
	init_var();
}

Snake::~Snake(void)
{
	SnakeNode.clear();
}

void Snake::init_var(void)
{
	length = 0;
	AddNode(width / 2, height / 2);					/* 一开始Snake的位置在界面中间 */
	PutFood();
	maxlength = (width -1) * (height -1);				/*计算胜利的时候，Snake的最大长度 */
	die = false;
	win = false;
	direction = 1;								/* 方向初始化为向上移动 */
}

void Snake::AddNode(const int &x, const int &y)
{
	Node newNode;
	newNode.x = x;
	newNode.y = y;
	SnakeNode.push_back(newNode);					/* 保存Snake的结点 */
	length++;
	if(length == maxlength)
		win = true;
}

void Snake::Judge(void)
{
	/* 判断是否碰到边界 */
	if(SnakeNode[0].x == 0 || SnakeNode[0].x == width ||
	  SnakeNode[0].y == 0 || SnakeNode[0].y == height) {
		die = true;
		return;
	}

	/* 判断是否撞到自己*/
	for(int i = 1; i < length; i++) {
		if(SnakeNode[0].x == SnakeNode[i].x &&SnakeNode[0].y == SnakeNode[i].y) {
			die = true;
			return;
		}
	}
	die = false;
}

bool Snake::IsDie(void)
{
	return die;
}

bool Snake::IsWin(void)
{
	return win;
}

void Snake::Move(void)
{
	int lastx = SnakeNode[length - 1].x;						/* 保留最后一个结点的坐标*/
	int lasty = SnakeNode[length - 1].y;

	for(int i = length -1; i > 0; i--)
	SnakeNode[i] = SnakeNode[i -1];							/* 更新Snake结点的坐标*/

	switch(direction)
	{
	case 1:
		SnakeNode[0].y--;   //up
		break;
	case 2:
		SnakeNode[0].x++;   //right
		break;
	case 3:
		SnakeNode[0].y++;   //down
		break;
	case 4:
		SnakeNode[0].x--;   //left
		break;
	default:
		break;
	}

	/* 判断是否吃到果实，如果吃到就增长身体*/
	if((SnakeNode[0].x == Food.x) &&(SnakeNode[0].y == Food.y))
	{
		AddNode(lastx, lasty);
		PutFood();
	}
	Judge();
}

void Snake::ChangeDirection(const int &NewDirection)
{
	if((direction - NewDirection == 2) ||(direction - NewDirection == -2))
		return;
	direction = NewDirection;
}

void Snake::PutFood(void)
{
	if(win == true)
		return;
	int x, y;
	bool empty = false;
	srand(time(NULL));
	do
	{
		empty = true;
		x = rand() % (width - 2) + 1;						/* 随机获得坐标 */
		y = rand() % (height - 2) + 1;
		for(int i = 0; i < length; i++) {
			if(SnakeNode[i].x == x &&SnakeNode[i].y == y) {	/* 如果坐标在蛇身上，重新获取*/
				empty = false;
				break;
			}
		}
	} while(empty == false);

	Food.x = x;
	Food.y = y;
}

void Snake::getCoordinate(vector<Node>&node, Node &food)
{
	node.resize(SnakeNode.size());
	node = SnakeNode;
	food = Food;
}

 int Snake::getScore(void)
{
	return length;
}
void Snake::Clear()
{
	SnakeNode.clear();
	length = 0;
	direction = 1;
}


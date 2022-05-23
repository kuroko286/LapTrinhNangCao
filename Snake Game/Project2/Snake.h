#pragma once
#include<vector>
#include"Point.h"
#include"Constants.h"
#include"Food.h"
#include<string>
using namespace std;
class Snake
{
public:
	vector<Point> snake;
	int dir;
	bool isMove;
	Point head;

	Snake();
	Snake(vector<Point> snake);
	void move(bool classic);
	void init();
	
	
};


#pragma once
#include"Point.h"
#include"Constants.h"
#include<time.h>
#include <cstdlib>

class Food
{
public:
	Point* food;
	Food();
	Food(Point* point);
	
	void init();
};


#include "Point.h"
Point::Point() {};
Point::Point(int x, int y) {
	this->curr_x = x;
	this->curr_y = y;
	this->pre_x = x;
	this->pre_y = y;
}
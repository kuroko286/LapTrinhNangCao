#include "Food.h"

Food::Food() {};
Food::Food(Point* food) {
	this->food = food;
}

void Food::init() {
	food->curr_x = (CELL_SIZE + rand() % (CELL_SIZE*25 + 1 - CELL_SIZE)) / CELL_SIZE * CELL_SIZE + CELL_SIZE / 2;
	food->curr_y = (CELL_SIZE + rand() % (CELL_SIZE*20 + 1 - CELL_SIZE)) / CELL_SIZE * CELL_SIZE + CELL_SIZE / 2;
	
}

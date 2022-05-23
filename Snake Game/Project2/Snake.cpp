#include "Snake.h"

Snake::Snake() {};
Snake::Snake(vector<Point> snake) {
	this->snake = snake;
	head = *snake.begin();
}
void Snake::move(bool classic) {
	
	

	for (auto it = snake.begin(); it != snake.end(); ++it) {
		if (it == snake.begin()) {
			it->pre_x = it->curr_x;
			it->pre_y = it->curr_y;
			switch (dir)
			{
			case LEFT:

				it->curr_x -= CELL_SIZE;
				
				if (it->curr_x <= CELL_SIZE && classic) {
					it->curr_x += CELL_SIZE*24;
				}
				break;
			case RIGHT:
				it->curr_x += CELL_SIZE;
				if (it->curr_x >= CELL_SIZE*25 && classic) {
					it->curr_x -= CELL_SIZE*24;
				}
				break;
			case UP:
				it->curr_y -= CELL_SIZE;
				if (it->curr_y <= CELL_SIZE && classic) {
					it->curr_y += (CELL_SIZE*19);
				}
				break;
			case DOWN:
				it->curr_y += CELL_SIZE;
				if (it->curr_y >= CELL_SIZE*20 && classic) {
					it->curr_y -= (CELL_SIZE*19);
				}
				break;
			}

		}
		else {
			it->pre_x = it->curr_x;
			it->pre_y = it->curr_y;
			it->curr_x = (it - 1)->pre_x;
			it->curr_y = (it - 1)->pre_y;
		}
	}
}
void Snake::init() {
	snake.clear();
	for (int i = 0; i < 3; i++) {
		Point* p = new Point(200 + CELL_SIZE/2 + i * CELL_SIZE, 200 + CELL_SIZE/2);
		snake.push_back(*p);
	}
}


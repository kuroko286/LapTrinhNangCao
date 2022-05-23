#include"Painter.h"
#include"Constants.h"

Painter::Painter() {};

Painter::Painter(SDL_Renderer* render) {
	this->render = render;
}

void Painter::drawPoint(Point* point) {
	SDL_Rect rec;
	rec.x = point->curr_x - CELL_SIZE / 2;
	rec.y = point->curr_y - CELL_SIZE / 2;
	rec.w = CELL_SIZE - 1;
	rec.h = CELL_SIZE - 1;
	SDL_RenderFillRect(render, &rec);
}
void Painter::drawFood(Food* food) {
	drawPoint(food->food);
}
void Painter::drawSnake(Snake* s) {
	vector<Point> snake = s->snake;
	for (auto it = snake.begin(); it != snake.end(); it++) {
		if (it == snake.begin()) {
			SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
			drawPoint(it._Unwrapped());
		}
		else {
			SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
			drawPoint(it._Unwrapped());
		}
	}
}


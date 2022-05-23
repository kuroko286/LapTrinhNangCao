#pragma once
#include <SDL.h>
#include"Point.h"
#include"Food.h"
#include"Snake.h"
#include<SDL_ttf.h>
#include<string>

class Painter {
	public:
		SDL_Renderer* render;
		Painter();
		Painter(SDL_Renderer* render);
		void drawPoint(Point* point);
		void drawFood(Food* food);
		void drawSnake(Snake* snake);
		
};

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include<vector>
#include<iostream>
#include<time.h>
#include<SDL_ttf.h>
#include "string"

#define FONT_LINK "font.ttf"



using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 500;
const int CELL_SIZE = 10;
int dir = 0;
int score = 0;



enum Direction {
	LEFT,RIGHT,UP,DOWN
};		

//The window we'll be rendering to
SDL_Window* window = NULL;
//The surface contained by the window
SDL_Surface* screenSurface = NULL;
//Render
SDL_Renderer* render = NULL;
//Font to render text
TTF_Font* font;

//color of text
SDL_Color foreground = { 255, 255, 255, 0 };

//location of score board
SDL_Rect score_label = {10, 10, 50, 50};
SDL_Rect score_rect = {65, 10};


struct Point {
	int curr_x, curr_y;
	int pre_x, pre_y;
	Point() {};
	Point(int x, int y) {
		this->curr_x = x;
		this->curr_y = y;
		this->pre_x = x;
		this->pre_y = y;
	}
	
	void drawRect() {
		
		SDL_Rect rec;
		rec.x = curr_x - CELL_SIZE / 2;
		rec.y = curr_y - CELL_SIZE / 2;
		rec.w = CELL_SIZE-1;
		rec.h = CELL_SIZE-1;
		SDL_RenderFillRect(render, &rec);
		
	}
	
};

vector<Point> snake;
Point food;
void initSnake() {
	for (int i = 0; i < 3; i++) {
		Point* p = new Point(205 + i * CELL_SIZE,205);
		snake.push_back(*p);
	}
}
void initFood() {
	food.curr_x = (10 + rand() % (SCREEN_WIDTH + 1 - 10))/10 * 10+5;
	food.curr_y = (10 + rand() % (SCREEN_HEIGHT + 1 - 10))/10 * 10+5;
}
void drawFood() {
	SDL_SetRenderDrawColor(render, 0, 0, 255, 255);
	food.drawRect();
}
void eatFood() {
	auto head = snake.begin();
	if (head->curr_x == food.curr_x && head->curr_y==food.curr_y) {
		score++;
		snake.push_back(food);
		initFood();
	}
}

void eatSelf() {
	int x = snake[0].curr_x;
	int y = snake[0].curr_y;
	for (auto it = snake.begin() + 1; it != snake.end(); it++) {
		if (x == it->curr_x && y == it->curr_y) {
			exit(0);
		}
	}
}

void drawSnake() {
	for (auto it = snake.begin(); it != snake.end(); it++) {
		if (it == snake.begin()) {
			SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
			it->drawRect();
		}
		else {
			SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
			it->drawRect();
		}
	}
}
void moveSnake() {
	Point head = *snake.begin();

	/*if(head.curr_x == )*/

	for (auto it = snake.begin(); it != snake.end(); ++it) {
		if (it == snake.begin()) {
			it->pre_x = it->curr_x;
			it->pre_y = it->curr_y;
			switch (dir)
			{
			case LEFT: it->curr_x -= 10; break;
			case RIGHT: it->curr_x += 10; break;
			case UP: it->curr_y -= 10; break;
			case DOWN: it->curr_y += 10; break;
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

void drawScore() {
	string slabel = "SCORE :";
	string score_str = to_string(score);


	//render "SCORE :"
	SDL_Surface* slabel_sur = TTF_RenderText_Blended(font, slabel.c_str(), foreground);
	if (!slabel_sur) {
		cerr << "Can't create SCORE laber surface : " << SDL_GetError() << endl;
		return;
	}
	SDL_Texture* slabel_texture = SDL_CreateTextureFromSurface(render, slabel_sur);
	SDL_RenderCopy(render, slabel_texture, nullptr, &score_label);

	//render score
	SDL_Surface* score_sur = TTF_RenderText_Blended(font, score_str.c_str(), foreground);
	if (!score_sur) {
		cerr << "Can't create score surface: " << SDL_GetError() << endl;
		return;
	}
	score_rect.w = score_sur->w;
	score_rect.h = score_sur->h;
	SDL_Texture* score_texture = SDL_CreateTextureFromSurface(render, score_sur);
	SDL_RenderCopy(render, score_texture, nullptr, &score_rect);

	//free memory
	SDL_FreeSurface(slabel_sur);
	SDL_FreeSurface(score_sur);
	slabel_sur = nullptr;
	score_sur = nullptr;

}


bool init() {
	/*if (!SDL_Init(SDL_INIT_VIDEO)) {
		cerr << "Can't init SDL for video : " << SDL_GetError << endl;
		return false;
	};*/

	SDL_Init(SDL_INIT_VIDEO);
	
	window = SDL_CreateWindow("Hello", 200, 200, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		cerr << "Can't create window :"  << SDL_GetError << endl;
		return false;
	}
	
	screenSurface = SDL_GetWindowSurface(window);
	if (!screenSurface) {
		cerr << "Can't create surface from window : " << SDL_GetError << endl;
		return false;
	}

	render = SDL_CreateRenderer(window,1,0);
	if (!render) {
		cerr << "Can'r create renderer : " << SDL_GetError << endl;
		return false;
	}
	
	if (TTF_Init() < 0) {
		cout << "Error initializing SDL_ttf: " << TTF_GetError() << endl;
	}
	
	font = TTF_OpenFont(FONT_LINK, 36);
	if (!font) {
		cerr << "Can't open font :" << SDL_Error << endl;
	}
}

void close() {
	
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();

}


void display() {
	bool quit = false;
	initSnake();
	initFood();
	SDL_Event e;
	while (!quit) {
		
		while (SDL_PollEvent(&e)) {
			
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
				cout << "quit";
			}
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_DOWN) { 
					if (dir == LEFT || dir==RIGHT) {
						dir = DOWN;
					}
					
				}
				if (e.key.keysym.sym == SDLK_UP) { 
					if (dir == LEFT || dir == RIGHT) {
						dir = UP;
					}
				}
				if (e.key.keysym.sym == SDLK_LEFT) { 
					if (dir == DOWN || dir == UP) {
						dir = LEFT;
					}
				}
				if (e.key.keysym.sym == SDLK_RIGHT) { 
					if (dir == DOWN || dir == UP) {
						dir = RIGHT;
					}
				}
			}
		}		
		moveSnake();
		drawSnake();
		drawFood();
		drawScore();
		eatSelf();
		eatFood();
		SDL_RenderPresent(render);
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);
		
		SDL_Delay(100);
	}
	cout << score;
	close();
}

	

int main( int argc, char* args[] )
{
	if(!init()) return 1;
	srand(time(0));
	display();
	return 0;
}
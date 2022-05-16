
#include"main.h"

int score = 0;
int x = 0, y=0;
int level;
bool isEnd = false;
bool isPlayAgain;
bool inGameMenu=1;
bool inGameType=0;
bool isClassic = 0;
bool isModern = 0;
bool inGameLevel=0;
bool inHighScore=0;

bool inAbout=0;

Snake* snake = new Snake();
Food* food = new Food(new Point());


//The window we'll be rendering to
SDL_Window* window = NULL;
//The surface contained by the window
SDL_Surface* screenSurface = NULL;
//Render
SDL_Renderer* render = NULL;
Painter* painter;
//Font to render text
TTF_Font* font;
//The music that will be played
Mix_Music* gMusic = NULL;
//The sound effects that will be used
Mix_Chunk* select = NULL;
Mix_Chunk* eat = NULL;
Mix_Chunk* changeDir = NULL;
Mix_Chunk* highScore = NULL;
//color of text
SDL_Color foreground = { 0, 255, 255, 0 };

void drawText(string text,int x,int y,int w,int h) {
	SDL_Rect rect = { x,y,w,h };
	SDL_Surface* sur = TTF_RenderText_Blended(font, text.c_str(), foreground);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, sur);
	SDL_RenderCopy(render, texture, nullptr, &rect);
	SDL_FreeSurface(sur);
	sur = nullptr;
}
bool hitWall() {
	int x = snake->snake[0].curr_x;
	int y = snake->snake[0].curr_y;
	if (x <= CELL_SIZE || x >= CELL_SIZE * 25 || y <= CELL_SIZE || y >= CELL_SIZE * 20) {
		isEnd = true;
		SDL_Delay(400);
		return true;
	}
	return false;
}
void show() {
	SDL_RenderPresent(render);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);
	SDL_Delay(100);
}
bool ClickIn(int x1, int y1, int w, int h) {
	if (x > x1 && x<x1 + w && y>y1 && y < y1 + h) {
		return true;
	}
	return false;
}
void drawMenu() {
	drawText("Ran San Moi", 200, 50, 300, 100);
	drawText("New Game", 250, 250, 150, 50);
	drawText("High Score", 250, 300, 150, 50);
	drawText("Quit Game", 250, 350, 150, 50);
	drawText("About", 250, 400, 150, 50);
	show();
}

void drawGameType() {
	drawText("Ran San Moi", 200, 50, 300, 100);
	drawText("Classic", 100, 250, 100, 100);
	drawText("Modern", 400, 250, 100, 100);
	show();
}
void drawAbout() {
	drawText("<-- Back", 20, 20, 100, 50);
	drawText("Le Van Quoc", 100, 150, 300, 100);
	drawText("A1 - K22", 100, 250, 100, 50);
	drawText("K66 - CD", 100, 300, 100, 50);
	show();
}
void drawHighScore() {
	drawText("<-- Back", 20, 20, 100, 50);
	drawText("Player 1 :   400", 200, 150, 180, 70);
	drawText("Player 2 :   350", 200, 220, 180, 70);
	drawText("Player 3 :   300", 200, 290, 180, 70);
	show();
}
void drawGameLevel() {
	drawText("Level   ", 150, 150, 100, 100);
	drawText("1    ", 250, 175, 50, 50);
	drawText("2    ", 300, 175, 50, 50);
	drawText("3    ", 350, 175, 50, 50);
	drawText("4    ", 400, 175, 50, 50);
	drawText("5    ", 450, 175, 50, 50);
	show();
}

void gameStart() {
	bool quit = false;
	if (Mix_PausedMusic()) {
		Mix_PlayMusic(gMusic, -1);
	}
	SDL_Event e;

	while (!quit) {
		
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				Mix_PlayChannel(-1, select, 0);
				SDL_GetMouseState(&x, &y);
				if (inGameMenu) {
					if (ClickIn(250, 250, 150, 50)) {
						inGameMenu = false;
						inGameType = true;
					}
					if (ClickIn(250, 300, 150, 50)) {
						inGameMenu = false;
						inHighScore = true;
					}
					if (ClickIn(250, 350, 150, 50)) {
						exit(0);
					}
					if (ClickIn(250, 400, 150, 50)) {
						inGameMenu = false;
						inAbout = true;
					}
				}
				if (inHighScore) {
					if (ClickIn(20, 20, 100, 50)) {
						inHighScore = false;
						inGameMenu = true;
					}
				}
				if (inAbout) {
					if (ClickIn(20, 20, 100, 50)) {
						inAbout = false;
						inGameMenu = true;
					}
				}
				if (inGameType) {
					if (ClickIn(100, 250, 100, 100)) {
						isClassic = true;
						isModern = false;
						inGameType = false;
						inGameLevel = true;
					}
					if (ClickIn(400, 250, 100, 100)) {
						isModern = true;
						isClassic = false;
						inGameType = false;
						inGameLevel = true;
					}
				}
				if (inGameLevel) {
					if (ClickIn(250, 175, 50, 50)) {
						inGameLevel = false;
						level = 1;
						gameLoop();
					}
					if (ClickIn(300, 175, 50, 50)) {
						inGameLevel = false;
						level = 2;
						gameLoop();
					}
					
					if (ClickIn(350, 175, 50, 50)) {
						inGameLevel = false;
						level = 3;
						gameLoop();
					}
					if (ClickIn(400, 175, 50, 50)) {
						inGameLevel = false;
						level = 4;
						gameLoop();
					}
					if (ClickIn(450, 175, 50, 50)) {
						inGameLevel = false;
						level = 5;
						gameLoop();
					}
				}
			}
		}
		if (inGameMenu) {
			drawMenu();
		}
		else if (inGameLevel) {
			drawGameLevel();
		}
		else if (inGameType) {
			drawGameType();
		}
		else if (inAbout) {
			drawAbout();
		}
		else if (inHighScore) {
			drawHighScore();
		}
		else {
			break;
		}
		
	}
}

void drawBorder(int x,int y,int w,int h,int thick) {
	SDL_SetRenderDrawColor(render,255,255,255,255);
	for (int i = 0; i < thick; i++) {
		SDL_Rect* rect = new SDL_Rect({ x+i,y+i,w-2*i,h-2*i });
		SDL_RenderDrawRect(render, rect);
		delete rect;
	}
}
void drawGameArea() {
	drawBorder(CELL_SIZE/2, CELL_SIZE/2, CELL_SIZE * 25, CELL_SIZE * 20, CELL_SIZE/2);
}
void drawBeside() {
	drawBorder(CELL_SIZE * 26, CELL_SIZE / 2, CELL_SIZE * 8, CELL_SIZE * 20, CELL_SIZE / 2);
	drawBorder(CELL_SIZE * 26, CELL_SIZE / 2, CELL_SIZE * 8, CELL_SIZE * 5, CELL_SIZE / 2);

	drawText("Score: ",  CELL_SIZE * 26.5,CELL_SIZE,CELL_SIZE * 5,CELL_SIZE * 5 );
	drawText(to_string(score), CELL_SIZE * 31.5, CELL_SIZE, CELL_SIZE * 2, CELL_SIZE * 5);
	drawText("Control", CELL_SIZE * 26.5, CELL_SIZE * 5.5, CELL_SIZE * 7, CELL_SIZE * 2.5);
	drawText("p = pause", CELL_SIZE * 26.5, CELL_SIZE * 8, CELL_SIZE * 6, CELL_SIZE * 2.1);
	drawText("r = resume", CELL_SIZE * 26.5, CELL_SIZE * 10.2, CELL_SIZE * 6, CELL_SIZE * 2.1);
	drawText("Esc = exit", CELL_SIZE * 26.5, CELL_SIZE * 12.4, CELL_SIZE * 6, CELL_SIZE * 2.1);
	drawText("arrows", CELL_SIZE * 26.5, CELL_SIZE * 14.6, CELL_SIZE * 6, CELL_SIZE * 2.1);
	drawText("  -> movement", CELL_SIZE * 26.5, CELL_SIZE * 16.8, CELL_SIZE * 6, CELL_SIZE * 2.1);
}
void drawBelow() {
	drawBorder(CELL_SIZE / 2, CELL_SIZE * 21, CELL_SIZE * 33.5, CELL_SIZE*4,CELL_SIZE/2);
	drawText("Ran San Moi ", CELL_SIZE*10 , CELL_SIZE * 21, CELL_SIZE * 15, CELL_SIZE * 4);
}

void eatSelf() {
	int x = snake->snake[0].curr_x;
	int y = snake->snake[0].curr_y;
	for (auto it = snake->snake.begin() + 1; it != snake->snake.end(); it++) {
		if (x == it->curr_x && y == it->curr_y) {
			SDL_Delay(400);
			isEnd = true;
		}
	}
}

bool outScreen() {
	Point p = *food->food;
	if (p.curr_x >= SCREEN_WIDTH || p.curr_y >= SCREEN_HEIGHT) {
		return true;
	}
	return false;
}
bool inSnake() {
	Point p = *food->food;
	vector<Point> v = snake->snake;
	for (auto it = v.begin() + 1; it != v.end(); it++) {
		if (p.curr_x == it->curr_x && p.curr_y == it->curr_y) {
			return true;
		}
	}
	return false;
}
void initFood() {
	do {
		food->init();
	} while (outScreen() || inSnake());
}
void eatFood() {
	auto head = snake->snake.begin();
	Point* p = food->food;
	
	if (head->curr_x == p->curr_x && head->curr_y == p->curr_y) {
		Mix_PlayChannel(-1, eat, 0);
		initFood();
		snake->snake.push_back(*p);
		score+=level;
	}
}
void init() {
	

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	window = SDL_CreateWindow("Hello", 200, 200, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		
	}
	gMusic = Mix_LoadMUS("C:/Users/ADMIN/Music/GroundMusic/happy.wav");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		
	}
	select = Mix_LoadWAV("C:/Users/ADMIN/Music/GroundMusic/select.wav");
	eat = Mix_LoadWAV("C:/Users/ADMIN/Music/GroundMusic/eat.wav");
	changeDir = Mix_LoadWAV("C:/Users/ADMIN/Music/GroundMusic/buttonclick.wav");
	highScore = Mix_LoadWAV("C:/Users/ADMIN/Music/GroundMusic/win.wav");
	screenSurface = SDL_GetWindowSurface(window);
	

	render = SDL_CreateRenderer(window,1,0);
	painter = new Painter(render);
	if (TTF_Init() < 0) {
		cout << "Error initializing SDL_ttf: " << TTF_GetError() << endl;
	}
	
	font = TTF_OpenFont(FONT_LINK, 36);
	if (!font) {
		cerr << "Can't open font :" << SDL_Error << endl;
	}
	snake->init();
	food->init();
	
}

void close() {
	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;
	//Destroy window   
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	window = NULL;
	render = NULL;
	SDL_Quit();

}
void gameLoop() {
	bool quit = false;
	if (Mix_PausedMusic()) {
		Mix_PlayMusic(gMusic, -1);
	}
	SDL_Event e;

	while (!quit) {

		while (SDL_PollEvent(&e)) {

			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}

			if (e.type == SDL_KEYDOWN) {
				Mix_PlayChannel(-1, changeDir, 0);
				if (e.key.keysym.sym == SDLK_DOWN) {
					if (snake->dir == LEFT || snake->dir == RIGHT) {
						snake->dir = DOWN;
						
					}

				}
				if (e.key.keysym.sym == SDLK_UP) {
					if (snake->dir == LEFT || snake->dir == RIGHT) {
						snake->dir = UP;
						
					}
				}
				if (e.key.keysym.sym == SDLK_LEFT) {
					if (snake->dir == DOWN || snake->dir == UP) {
						snake->dir = LEFT;
						
					}
				}
				if (e.key.keysym.sym == SDLK_RIGHT) {
					if (snake->dir == DOWN || snake->dir == UP) {
						snake->dir = RIGHT;
						
					}
				}
				if (e.key.keysym.sym == SDLK_p) {
					snake->isMove = false;
				}
				if (e.key.keysym.sym == SDLK_r) {
					snake->isMove = true;
				}
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					exit(0);
				}
			}
		}
		if (snake->isMove) {
			snake->move(isClassic);
		}

		painter->drawSnake(snake);
		painter->drawFood(food);

		eatSelf();
		if (isModern) {
			hitWall();
		}
		
		
		if (isEnd) {
			if (Mix_PlayingMusic()) {
				Mix_PauseMusic();
			}
			Mix_PlayChannel(-1, highScore, 0);
			
			break;
		}
		eatFood();
		drawGameArea();
		drawBeside();
		drawBelow();
		SDL_RenderPresent(render);
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);
		SDL_Delay(300/level);
	}
}

void display() {
	
	Mix_PlayMusic(gMusic, -1);
	
	gameStart();
	SDL_Event e;
	
	if (isEnd) {
		if (Mix_PlayingMusic()) {
			Mix_PauseMusic();
		}
		
		Mix_PlayChannel(-1, highScore, 0);
	}
	
	while (isEnd) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&x, &y);
				Mix_PlayChannel(-1, select, 0);
				
				if (ClickIn(150, 350, 100, 100)) {
					
					isEnd = !isEnd;
					snake->init();
					snake->isMove = false;
					score = 0;
					gameLoop();
				}
				else if(ClickIn(425, 350, 100, 100)){
					isEnd = !isEnd;
					snake->init();
					score = 0;
					snake->isMove = false;
					inGameMenu = true;
					gameStart();
				}
			}
		}
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);
		
		drawText("Your score is: " + to_string(score), 250, 100, 200, 100);
		drawText("Play Again? ", 250, 200, 200, 100);
		drawText("YES", 150, 350, 100, 100);
		drawText("NO", 425, 350, 100, 100);
		SDL_RenderPresent(render);
	}
	
	
	
	
}

	

int main( int argc, char* args[] )
{	
	
	init();
	
	srand(time(0));
	display();
	
	return 0;
}

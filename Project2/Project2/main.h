#pragma once
//Using SDL and standard IO
#include <SDL.h>
#include"Constants.h"
#include"Food.h"
#include"Painter.h"
#include"Snake.h"
#include<SDL_ttf.h>
#include"Point.h"
#include"string"
#include<iostream>
#include<SDL_mixer.h>

#define FONT_LINK "font.ttf"

using namespace std;
bool outScreen();
bool inSnake();
void initFood();
void eatFood();
void eatSelf();
void gameLoop();

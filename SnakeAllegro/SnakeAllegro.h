#pragma once
const int					DISPLAY_WIDTH  = 500;
const int					DISPLAY_HEIGHT = 500;
int snakeSize = 10;
const float					FPS = 60.0;
bool						GAME = true;
int							targetY = 0;											  
int							targetX = 0;
int							movementVariable = 2;											 
int							result = 0;
enum						Direction { UP, DOWN, LEFT, RIGHT };
Direction					snakeDirection = RIGHT;

bool collisionOff;
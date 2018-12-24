#pragma once
const int					DISPLAY_WIDTH  = 500;
const int					DISPLAY_HEIGHT = 500;
int snakeSize = 10;
 float					FPS = 60.0;
bool						GAME = true;
int							targetY = 0;											  
int							targetX = 0;
int							movementVariable = 3;											 
int							result = 0;
enum						Direction { UP, DOWN, LEFT, RIGHT };
Direction					snakeDirection = RIGHT;

bool collisionOff;
int cooldown = 0;

int Rcolor, Gcolor, Bcolor;
int specialApples = 0;
int specialAppleTimer = 300;
 
bool specialAppleSpawned = false;
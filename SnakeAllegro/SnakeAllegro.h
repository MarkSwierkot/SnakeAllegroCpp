#pragma once
const int							DISPLAY_WIDTH  = 500;
const int							DISPLAY_HEIGHT = 500;

const float							FPS = 60.0;
bool							    GAME = true;
enum								Direction { UP, DOWN, LEFT, RIGHT };
Direction							snakeDirection = RIGHT;

int									snakeSize = 10;
int									targetY = 0;											  
int									targetX = 0;
int									movementVariable = 3;											 
int									result = 1;
int									cooldown = 0;
int									specialApples = 0;
int									specialAppleTimer = 300;
bool								collisionOff;
bool								specialAppleSpawned = false;
int									Rcolor, Gcolor, Bcolor;


 

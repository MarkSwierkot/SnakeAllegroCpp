#include "pch.h"
#include "Snake.h"
#include <iostream>
using namespace std;


Snake::Snake()
{
	posX = posY = 250;
}
Snake::Snake(int X, int Y)
{
	posX = X;
	posY = Y;
}

int Snake::getX()
{
	return posX;
}
int Snake::getY()
{
	return posY;
}
void Snake::setX(int X)
{
	posX = X;
}
void Snake::setY(int Y)
{
	posY = Y;
}

void Snake::updatePosition(int X, int Y)
{
	this->posX = X;
	this->posY = Y;
}
void Snake::moveDown()
{
	this->posY++;
}
void Snake::moveUp()
{
	this->posY--;
}
void Snake::moveLeft()
{
	this->posX--;
}
void Snake::moveRight()
{
	this->posX++;
}
void Snake::displayCordinates()
{
	cout << "X -> " << posX << ", Y -> " << posY << endl;
}
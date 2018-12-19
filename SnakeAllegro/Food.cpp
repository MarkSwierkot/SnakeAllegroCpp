#include "pch.h"
#include "Food.h"
#include <iostream>
using namespace std;


Food::Food()
{
	posX = posY = 250;
}
Food::Food(int X, int Y)
{
	posX = X;
	posY = Y;
}

int Food::getX()
{
	return posX;
}
int Food::getY()
{
	return posY;
}
void Food::setX(int X)
{
	posX = X;
}
void Food::setY(int Y)
{
	posY = Y;
}

void Food::updatePosition(int X, int Y)
{
	this->posX = X;
	this->posY = Y;
}
void Food::moveDown()
{
	this->posY++;
}
void Food::moveUp()
{
	this->posY--;
}
void Food::moveLeft()
{
	this->posX--;
}
void Food::moveRight()
{
	this->posX++;
}
void Food::displayCordinates()
{
	cout << "X -> " << posX << ", Y -> " << posY << endl;
}
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
	this->posX = X;
	this->posY = Y;
	
 
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

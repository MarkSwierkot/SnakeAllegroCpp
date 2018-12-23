#include "pch.h"
#include "Food.h"
#include <iostream>
using namespace std;


Food::Food()
{
	posX = posY = 250;
	type = 1;
	
}
Food::Food(int X, int Y, int type )
{
	this->posX = X;
	this->posY = Y;
	this->type = type;
 
}


int Food::getX()
{
	return posX;
}
int Food::getY()
{
	return posY;
}
int Food::getType()
{
	return type;
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

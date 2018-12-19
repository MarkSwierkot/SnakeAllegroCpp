 
#pragma once
class Snake
{

private:
	int posX, posY; // two fields storing position coordinates

public:
	Snake(); // constructor
	Snake(int X, int Y);
	void setX(int X);
	void setY(int Y);
	int getX();
	int getY();

	void updatePosition(int X, int Y);


	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void displayCordinates(); // Function is not used in working program, it is just for debugging
};
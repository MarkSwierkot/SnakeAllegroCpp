
#pragma once

class Food
{

private:
	int posX, posY; // two fields storing position coordinates
	 

public:
	Food(); // constructor
	Food(int X, int Y );
	void setX(int X);
	void setY(int Y);
	int getX();
	int getY();

	void updatePosition(int X, int Y);


};
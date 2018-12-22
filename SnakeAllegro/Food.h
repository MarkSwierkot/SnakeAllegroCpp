
#pragma once

class Food
{
enum FoodType { REGULAR, PACE, SPECIAL };

private:
	int posX, posY; // two fields storing position coordinates



	// 1 - REGULAR - lengthen snake, adds points to score counter
	// 2 - PACE	   - either speeds up or slows game pace
	// 3 - SPECIAL - for a short period of time, makes walls dissapear and enables it for user to walk through them

public:
	Food(); 
	Food(int X, int Y);
	
	void setX(int X);
	void setY(int Y);

	int getX();
	int getY();
	void updatePosition(int X, int Y);
	


};
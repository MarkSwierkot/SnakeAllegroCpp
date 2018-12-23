
#pragma once

class Food
{


private:
	int posX, posY; // two fields storing position coordinates
	int type;


	// 1 - REGULAR - lengthen snake, adds points to score counter
	// 2 - PACE	   - either speeds up or slows game pace
	// 3 - SPECIAL - for a short period of time, makes walls dissapear and enables it for user to walk through them

public:
 
	Food(); 
	Food(int X, int Y, int type );
	
	void setX(int X);
	void setY(int Y);
	void setType(int type);

	int getX();
	int getY();
	int getType();
	void updatePosition(int X, int Y);
	


};
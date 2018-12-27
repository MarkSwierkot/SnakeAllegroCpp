
#pragma once

class Food
{


private:
	int posX, posY; // two fields storing position coordinates
	int type;


 
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
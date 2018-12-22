#include "pch.h"
#include<allegro5\allegro5.h> 
#include<allegro5\allegro_native_dialog.h> 
#include<allegro5\allegro_primitives.h>
#include "SnakeAllegro.h"
#include <iostream>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <vector>

#include "Snake.h"
#include "Food.h"
#include <time.h>
 

using namespace std;


/*	MAREK ŚWIERKOT 2018 SILESIAN UNIVERSITY OF TECHNOLOGY, AEI, MAKROFACULTY, FUNDAMENTALS OF COMPUTER PROGRAMMING SEMESTER I PROJECT	*/
/*			*/



int * randomiseFoodPosition( vector<Snake> snakeBody)
{
	srand(time(NULL));

	int			position[2]; // 0 element stands for X, 1 element stands for Y
	bool		spawnedWithinSnake;
	
	do
	{
		spawnedWithinSnake = false;
		
		position[0] = rand() % 725 + 10;
		position[1] = rand() % 725 + 10;

		for (Snake element : snakeBody)
		{
			if (element.getX() - 8 <= position[0] && element.getX() + 16 >= position[0] && element.getY() - 8 <= position[1] && element.getY() + 16 >= position[1])
			{
				spawnedWithinSnake = true;
			}
			
		}


	} while (spawnedWithinSnake != false); // Repeat, if food was spawned in snake body 

	return position;
}
 

void displaySnakeOnScreen( vector<Snake> snakeBody)
{
	int head;
	for(Snake segment : snakeBody)
	{
		al_draw_rectangle(segment.getX(), segment.getY(), segment.getX() + 10, segment.getY() + 10, al_map_rgb(51, 134, 211), 20);
		
 
	}
	al_flip_display();
}


bool doesSnakeTouchFood(vector<Snake> snakeBody, Food food)						// explanation of numbers logic in pdf file
{
	if (snakeBody[0].getX() - 8 <= food.getX() && snakeBody[0].getX()+16 >= food.getX() )
	{
		if (snakeBody[0].getY()-8 <= food.getY()  && snakeBody[0].getY()+16  >= food.getY() )
		{
			return true;
		}
	}

	return false;
}
 void detectCollision(vector<Snake> snakeBody)
{
	if (snakeBody[0].getX() <= 17 || snakeBody[0].getX() >= 733 || snakeBody[0].getY() <= 17 || snakeBody[0].getY() >= 733) //check for wall colision
	{
		cout << "Koniec";
	}
	else //check for self colision
	{
		for (int i = 3; i< snakeBody.size(); i++)
		{
			if (snakeBody[0].getX() == snakeBody[i].getX() && snakeBody[0].getY() == snakeBody[i].getY())
			{
				cout << "Koniec";
			}
		}
	}
}
 
int main()
{
 
	if (!al_init())																	// allegro library initialization
	{
		cout << "Failed to initialize Allegro library" << endl;
	}

	const float				FPS = 60.0; 
	enum					Direction { UP, DOWN, LEFT, RIGHT };
	Direction				snakeDirection = RIGHT;									// there has to be default value for snakeDirection in order for switch to be started
	
	ALLEGRO_DISPLAY			*display;												// bunch of allegro variables
	ALLEGRO_EVENT_QUEUE		*event_queue;
	ALLEGRO_KEYBOARD_STATE	keyboardState;
	ALLEGRO_TIMER			*timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT			event;
	
	event_queue				= al_create_event_queue();
	display					= al_create_display(750, 750);
																					// default y position ...
	int						 targetY = 0;											  //is used for seting future head position change 
	int						 targetX = 0;
	bool					 GAME = true;											// main loop initial condition
	
	vector<Snake>			 snakeBody;												// vector which stores every next segment of snake

	Snake					 head(250, 250);										//creating snake first object - its head, and populating vector with i																			
	snakeBody.push_back(head);															
					
	 

	Food apple(250, 380);
	

	al_init_primitives_addon();
	al_install_keyboard();
 
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
	
	
	while (GAME)
	{
		
		detectCollision(snakeBody);
		al_wait_for_event(event_queue, &event);
		al_clear_to_color(al_map_rgb(255, 255, 255));
		al_draw_filled_circle(apple.getX(), apple.getY(), 5, al_map_rgb(125, 200, 19));

		al_draw_rectangle(0,0,750,0,al_map_rgb(0, 0, 0), 15);
		al_draw_rectangle(0,0,0,750,al_map_rgb(0, 0, 0), 15);
		al_draw_rectangle(750,0,750,750,al_map_rgb(0, 0, 0), 15);
		al_draw_rectangle(0,750,750,750,al_map_rgb(0, 0, 0), 15);
		

		if (doesSnakeTouchFood(snakeBody, apple))	
		{
		
		
			int *position;

			position = randomiseFoodPosition(snakeBody);

			apple.updatePosition((*position), *(position + 1));

			Snake eatenApple(*position, *(position + 1));
			
			snakeBody.push_back(eatenApple);

			
			
		}
		
		

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			GAME = false;
		}
		else if (event.type == ALLEGRO_EVENT_TIMER)
		{
			al_get_keyboard_state(&keyboardState);

			if (al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT) && snakeDirection != LEFT )
			{
				snakeDirection = RIGHT;
			}
			else if (al_key_down(&keyboardState, ALLEGRO_KEY_DOWN) && snakeDirection != UP)
			{
				snakeDirection = DOWN;
			}
			else if (al_key_down(&keyboardState, ALLEGRO_KEY_UP) && snakeDirection != DOWN)
			{
				snakeDirection = UP;
			}
			else if (al_key_down(&keyboardState, ALLEGRO_KEY_LEFT) && snakeDirection != RIGHT)
			{
				snakeDirection = LEFT;
			}

		}

		switch (snakeDirection)														// determines head movement
		{																			// so called "target" variables determines only head movent, they dont
																					// have direct impact on the rest of the body, actually the way snake moves,
																					// is based on moving its tail ahead of his body, I belive it's smarter than moving
																					// each segment seperatly
			case UP:
			{
				targetY = -5;
				targetX = 0;
				break;
			}
			case RIGHT:
			{
				targetY = 0;
				targetX = 5;
				break;
			}
			case DOWN:
			{
				targetY = 5;
				targetX = 0;
				break;
			}
			case LEFT:
			{
				targetY = 0;
				targetX = -5;
				break;
			}
		}
		

		int newX, newY;

		for (int i = 0; i < snakeBody.size(); i++)
		{
			if (snakeBody.size() > 1)
			{
				if (i == 0)
				{
					newX = snakeBody[0].getX() + targetX;
					newY = snakeBody[0].getY() + targetY;

					Snake snake(newX, newY);

					snakeBody.insert(snakeBody.begin(), snake);
				}
				if (i == snakeBody.size() - 1)
				{
					snakeBody.pop_back();
				}
			}
			else																		//things are easier when snake is only 1 segment long, then just move head in given direction
			{
				snakeBody[i].setX(snakeBody[i].getX() + targetX);
				snakeBody[i].setY(snakeBody[i].getY() + targetY);
			}

		}

		displaySnakeOnScreen(snakeBody);
		
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

}


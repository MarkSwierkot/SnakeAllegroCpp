#include "pch.h"
#include<allegro5\allegro5.h> 
#include<allegro5\allegro_native_dialog.h> 
#include<allegro5\allegro_primitives.h>

#include <iostream>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <vector>

#include "Snake.h"
#include "Food.h"
 

using namespace std;


/*	MAREK ŚWIERKOT 2018 SILESIAN UNIVERSITY OF TECHNOLOGY, AEI, MAKROFACULTY, FUNDAMENTALS OF COMPUTER PROGRAMMING SEMESTER I PROJECT	*/
/*																																		*/

void displaySnakeOnScreen(vector<Snake> snakeBody)
{
	int colorMixer = 1;																// just a trivial color mixer

	for (Snake segment : snakeBody)
	{
		al_draw_rectangle(segment.getX(), segment.getY(), segment.getX() + 8, segment.getY() + 8, al_map_rgb(1 * colorMixer, 25 * colorMixer, 25 * colorMixer), 15);
		al_flip_display();
		colorMixer++;
	}
}

void hasSnakeEatenFood(vector<Snake> snakeBody, Food food)
{
	// Calculating position of head/food position
	if(snakeBody[0].getX()> food.getX() && snakeBody[0].getX()+8 < food.getX())
		if (snakeBody[0].getY() > food.getY() && snakeBody[0].getY() + 8 < food.getY())
		{
			cout << "jest";
		}
		
		
}

int main()
{
	if (!al_init())																	// allegro library initialization
	{
		cout << "Failed to initialize Allegro library" << endl;
	}
	
	const float				FPS = 12.0; 
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

	Snake					 head(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head1(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head2(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head3(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head4(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head5(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head6(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head7(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head8(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head9(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head10(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head11(250, 250);										//creating snake first object - its head, and populating vector with it
	Snake					 head12(250, 250);										//creating snake first object - its head, and populating vector with it
																					//creating snake first object - its head, and populating vector with it
	
	snakeBody.push_back(head);															
	snakeBody.push_back(head1);															
	snakeBody.push_back(head2);															
	snakeBody.push_back(head3);															
	snakeBody.push_back(head4);															
	snakeBody.push_back(head5);															
	snakeBody.push_back(head6);															
	snakeBody.push_back(head7);															
	snakeBody.push_back(head8);															
	snakeBody.push_back(head9);															
	snakeBody.push_back(head10);															
	snakeBody.push_back(head11);															
	snakeBody.push_back(head12);															
	
	Food apple(250, 390);

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
		hasSnakeEatenFood(snakeBody, apple);

		al_wait_for_event(event_queue, &event);
		al_clear_to_color(al_map_rgb(255, 255, 255));

		al_draw_filled_circle(apple.getX(), apple.getY(), 15, al_map_rgb(125, 200, 19));

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			GAME = false;
		}

		else if (event.type == ALLEGRO_EVENT_TIMER)
		{
			al_get_keyboard_state(&keyboardState);

			if (al_key_down(&keyboardState, ALLEGRO_KEY_D) && snakeDirection != LEFT )
			{
				snakeDirection = RIGHT;
			}
			else if (al_key_down(&keyboardState, ALLEGRO_KEY_S) && snakeDirection != UP)
			{
				snakeDirection = DOWN;
			}
			else if (al_key_down(&keyboardState, ALLEGRO_KEY_W) && snakeDirection != DOWN)
			{
				snakeDirection = UP;
			}
			else if (al_key_down(&keyboardState, ALLEGRO_KEY_A) && snakeDirection != RIGHT)
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
				targetY = -3;
				targetX = 0;
				break;
			}
			case RIGHT:
			{
				targetY = 0;
				targetX = 3;
				break;
			}
			case DOWN:
			{
				targetY = 3;
				targetX = 0;
				break;
			}
			case LEFT:
			{
				targetY = 0;
				targetX = -3;
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
					newX = snakeBody[0].getX() +  5 * targetX;
					newY = snakeBody[0].getY() +  5 * targetY;
					
					Snake snake(newX, newY);

					snakeBody.insert(snakeBody.begin(), snake);
				}
				if (i == snakeBody.size()-1)
				{
					snakeBody.pop_back();
				}
			}
			else
			{
				snakeBody[i].setX(snakeBody[i].getX() + 5*targetX);
				snakeBody[i].setY(snakeBody[i].getY() + 5*targetY);
			}
		
		}
		 

		displaySnakeOnScreen(snakeBody);
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

}


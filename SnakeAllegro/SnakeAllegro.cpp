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
 

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

 
int * randomiseFoodPosition( vector<Snake> snakeBody, int DISPLAY_WIDTH, int DISPLAY_HEIGHT )
{
	srand(time(NULL));
	

	int			position[2];													// stores randomised position of generated Food object 
	bool		spawnedWithinSnake;												// determines whether Food object was spawned within snake body - which shouldn't be possible								
	
	do
	{
		spawnedWithinSnake = false;
		
		position[0] = rand() % (DISPLAY_WIDTH-30) + 10;
		position[1] = rand() % (DISPLAY_HEIGHT-30) + 10;

		for (Snake element : snakeBody)
		{
			if (element.getX() - 8 <= position[0] && element.getX() + 16 >= position[0] && element.getY() - 8 <= position[1] && element.getY() + 16 >= position[1])
			{
				spawnedWithinSnake = true;
			}	
		}

	} while (spawnedWithinSnake != false); 

	return position;
}
 

void displaySnakeOnScreen( vector<Snake> snakeBody )
{
	int colorMixer = 1;

	for(Snake segment : snakeBody)
	{
		colorMixer++;
		al_draw_rectangle(segment.getX(), segment.getY(), segment.getX() + snakeSize, segment.getY() + snakeSize, al_map_rgb(0 ,10 + colorMixer,0), snakeSize);
	}
	al_flip_display();
}


bool detectFoodCollision(vector<Snake> snakeBody, Food food)						 
{
	if (snakeBody[0].getX() - (snakeSize+5) <= food.getX() && snakeBody[0].getX() + (snakeSize + 5) >= food.getX() )
	{
		if (snakeBody[0].getY() - (snakeSize + 5) <= food.getY()  && snakeBody[0].getY()+ (snakeSize + 5) >= food.getY() )
		{
			result++;
			return true;
		}
	}

	return false;
}
void wallDissapear(vector <Snake> * snakeBody)
{
		if (snakeBody->at(0).getX() <= 0)
		{
			snakeBody->at(0).setX(DISPLAY_WIDTH - 10);
		}
		else if (snakeBody->at(0).getX() >= (DISPLAY_WIDTH - 10))
		{
			snakeBody->at(0).setX(10);
		}
		else if (snakeBody->at(0).getY() <= 0)
		{
			snakeBody->at(0).setY(DISPLAY_HEIGHT - 10);
		}
		else if (snakeBody->at(0).getY() >= (DISPLAY_HEIGHT - 10))
		{
			snakeBody->at(0).setY(10);
		}
	


}
 void detectCollision( vector<Snake> snakeBody)
{
	if (snakeBody[0].getX() <= 20 || snakeBody[0].getX() >= (DISPLAY_WIDTH-20) || snakeBody[0].getY() <= 20 || snakeBody[0].getY() >= (DISPLAY_HEIGHT-20))  
	{
		GAME = FALSE;
	}

	else  
	{
		for (int i = 3; i < snakeBody.size(); i++)
		{
			if (snakeBody[0].getX() == snakeBody[i].getX() && snakeBody[0].getY() == snakeBody[i].getY())
			{
				GAME = FALSE;
			}
		}
	}
}
 
   
 
int main()
{
	al_init();
	 
	ALLEGRO_DISPLAY						*display;												
	ALLEGRO_EVENT_QUEUE					*event_queue;
	ALLEGRO_KEYBOARD_STATE				keyboardState;
	ALLEGRO_TIMER						*timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT						event;
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font = al_load_ttf_font("font.ttf", 17, 0);
 
	event_queue	= al_create_event_queue();
	display	= al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
	
	al_init_primitives_addon();
	al_install_keyboard();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);																	

 

	vector<Snake>						 snakeBody;												 
	Snake								 head(250, 250);										 																														
	Food								 apple(250, 380, 1 );
	Food specialApple(-20, -20, 2);
	snakeBody.push_back(head);
	collisionOff = false;
 

	while (GAME)
	{
		
		al_wait_for_event(event_queue, &event);
		al_clear_to_color(al_map_rgb(219, 225, 219));
		al_draw_filled_circle(apple.getX(), apple.getY(), 5, al_map_rgb(235, 83, 0));
		
		al_draw_filled_circle(specialApple.getX(), specialApple.getY(), 5, al_map_rgb(10, 83, 0));
		
		if (result >= 50) movementVariable = 4;											// Speeds up a game, when certain score is reached
		if (result >= 100) movementVariable = 5;

		if (!collisionOff)
		{
			Rcolor = 4;
			Gcolor = 54;
			Bcolor = 1;
			detectCollision(snakeBody);
		}
		if (collisionOff)
		{
			wallDissapear(&snakeBody);
			cooldown--;
			Rcolor = 104;
			Gcolor = 154;
			Bcolor = 101;
		 
			
			if (cooldown < 300)
			{
				Rcolor = 74;
				Gcolor = 124;
				Bcolor = 71;
			}

			if (cooldown <= 0)
			{
				collisionOff = false;
				
			}
		}
		
		al_draw_text(font, al_map_rgb(0, 0, 0), 50, 10, ALLEGRO_ALIGN_CENTRE,  "SCORE:" );
		al_draw_textf(font, al_map_rgb(0, 0, 0), 100, 10, ALLEGRO_ALIGN_CENTRE, "%d" ,result );
		
		al_draw_text(font, al_map_rgb(0, 0, 0), 390, 10, ALLEGRO_ALIGN_CENTRE, "Magic apples:");
		al_draw_textf(font, al_map_rgb(0, 0, 0), 465, 10, ALLEGRO_ALIGN_CENTRE, "%d", specialApples);

		if (collisionOff == true)
		{
			 al_draw_textf(font, al_map_rgb(5, 25, 75), 450, 50, ALLEGRO_ALIGN_CENTRE, "%d", cooldown/10);
		}

		al_draw_rectangle(0, 0, DISPLAY_WIDTH, 0, al_map_rgb(Rcolor, Gcolor, Bcolor), 20);
		al_draw_rectangle(0, 0, 0, DISPLAY_HEIGHT, al_map_rgb(Rcolor, Gcolor, Bcolor), 20);
		al_draw_rectangle(DISPLAY_WIDTH, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, al_map_rgb(Rcolor, Gcolor, Bcolor), 20);
		al_draw_rectangle(0, DISPLAY_HEIGHT, DISPLAY_WIDTH, DISPLAY_HEIGHT, al_map_rgb(Rcolor, Gcolor, Bcolor), 20);

		
		specialAppleTimer--;
		cout << specialAppleTimer <<  " " <<  specialApple.getX() << " " << specialApple.getY() << endl;

		if (specialApples <=1 &&  specialAppleSpawned == false && collisionOff == false)
		{
			int *position = randomiseFoodPosition(snakeBody, 600, 600);
			specialApple.updatePosition((*position), *(position+1));
			specialAppleSpawned = true;
			
		}

		if (specialAppleSpawned = true)
		{
			if (specialAppleTimer == 0)
			{
				specialAppleTimer = 300;
				specialAppleSpawned = false;
			}
		}

		if (detectFoodCollision(snakeBody, apple))
		{
			int *position;

			position = randomiseFoodPosition(snakeBody, DISPLAY_WIDTH, DISPLAY_HEIGHT);

			 
				apple.updatePosition((*position), *(position + 1));

				Snake eatenApple(*position, *(position + 1));

				snakeBody.push_back(eatenApple);
				snakeBody.push_back(eatenApple);
				snakeBody.push_back(eatenApple);
 
		}
		if (detectFoodCollision(snakeBody, specialApple))
		{
			specialApples++;
			specialAppleSpawned = false;
			specialApple.updatePosition(-20, -20);
		}
 
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			GAME = false;
		}

		else if (event.type == ALLEGRO_EVENT_TIMER)
		{
			al_get_keyboard_state(&keyboardState);

			if (al_key_down(&keyboardState, ALLEGRO_KEY_RIGHT) && snakeDirection != LEFT)
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
			else if (al_key_down(&keyboardState, ALLEGRO_KEY_SPACE) && specialApples > 0)
			{
				if (collisionOff == false)
				{
					specialApples--;
					cooldown = 1000;
				}
				collisionOff = true;
				
				
			}

		}

		switch (snakeDirection)
		{
			case UP:
			{
				targetY = -movementVariable;
				targetX = 0;
				break;
			}
			case RIGHT:
			{
				targetY = 0;
				targetX = movementVariable;
				break;
			}
			case DOWN:
			{
				targetY = movementVariable;
				targetX = 0;
				break;
			}
			case LEFT:
			{
				targetY = 0;
				targetX = -movementVariable;
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
			else																		
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


#pragma once
#include "SnakeAllegro.cpp"

if (!al_init())																	// allegro library initialization
{
	cout << "Failed to initialize Allegro library" << endl;
}

const float				FPS = 24.0;
enum					Direction { UP, DOWN, LEFT, RIGHT };
Direction				snakeDirection = RIGHT;									// there has to be default value for snakeDirection in order for switch to be started

ALLEGRO_DISPLAY			*display;												// bunch of allegro variables
ALLEGRO_EVENT_QUEUE		*event_queue;
ALLEGRO_KEYBOARD_STATE	keyboardState;
ALLEGRO_TIMER			*timer = al_create_timer(1.0 / FPS);
ALLEGRO_EVENT			event;

event_queue = al_create_event_queue();
display = al_create_display(750, 750);
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

snakeBody.push_back(head);
snakeBody.push_back(head1);
snakeBody.push_back(head2);
snakeBody.push_back(head3);
snakeBody.push_back(head4);
snakeBody.push_back(head5);



al_init_primitives_addon();
al_install_keyboard();

al_register_event_source(event_queue, al_get_keyboard_event_source());
al_register_event_source(event_queue, al_get_timer_event_source(timer));
al_register_event_source(event_queue, al_get_display_event_source(display));

al_start_timer(timer);

al_clear_to_color(al_map_rgb(255, 255, 255));
al_flip_display();



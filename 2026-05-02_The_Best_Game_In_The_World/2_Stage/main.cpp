#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

static const float FRICTION = 0.9f;
static const float GRAVITY = 0.2f;
static const float JUMP_POWER = -2.2f;
static const float COIN_DROP_SPEED = -0.7;


static const int MAP_WIDTH = 80;
static const int MAP_HEIGHT = 25;

static const char COLOR_WIN[] = "COLOR 2F";
static const char COLOR_LOSE[] = "COLOR 4F";
static const char COLOR_DEFAULT[] = "COLOR 9F";

static const int SCORE_FOR_KILL = 50;
static const int SCORE_FOR_COIN = 100;

static const char TYPE_BRICK = '#';
static const char TYPE_COIN = '$';
static const char TYPE_ENEMY = '^';
static const char TYPE_EXIT = '+';
static const char TYPE_MARIO = '@';
static const char TYPE_BOX = '?';
static const char TYPE_LINES = '-';


typedef struct SObject{
	float x, y;
	float width, height;
	float vertical_speed;
	float horizontal_speed;
	bool is_flying;
	char object_type;
} Object;

char map[MAP_HEIGHT][MAP_WIDTH+1];
float camera_x = 0.0f;

Object mario;
Object *brick = NULL;
Object *moving_objects = NULL;

int brick_counts = 0;
int moving_objects_count;

int max_level = 3;
int current_level = 1;
int player_score = 0;
 
void clear_map(){
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		map[0][i] = ' ';
	}
	map[0][MAP_WIDTH] = '\0';
	
	for (int i = 0; i < MAP_WIDTH; i++)
	{
        map[1][i] = ' ';
	}
	
	for (int j = 1; j < MAP_HEIGHT; j++)
	{
		sprintf(map[j], map[0]);
	}
}

void show_map(){
	map[MAP_HEIGHT - 1][MAP_WIDTH - 1]= '\0';
	for (int j = 0; j < MAP_HEIGHT; j++)
	{
		printf("%s\n", map[j]);
	}
}


void set_object_pos(Object *obj, float x_pos, float y_pos){
	(*obj).x = x_pos;
	(*obj).y = y_pos;
}

void init_object(Object *obj, float x_pos, float y_pos, float obj_width, float obj_height, char cur_type){
	set_object_pos(obj, x_pos, y_pos);
	(*obj).width = obj_width;
	(*obj).height = obj_height;
	(*obj).vertical_speed = 0;
	(*obj).object_type = cur_type;
	(*obj).horizontal_speed = FRICTION;
}
;
void create_level(int lvl);

void player_dead()
{
	system(COLOR_LOSE);
	Sleep(500);
	create_level(current_level);
}

bool is_collision(Object obj_1, Object obj_2);
Object *get_new_moving_objects();

void vertical_move_object(Object *obj)
{
	(*obj).is_flying = true;
	(*obj).vertical_speed += GRAVITY;
	set_object_pos(obj, (*obj).x, (*obj).y + (*obj).vertical_speed);
	
	for (int i = 0; i < brick_counts; i++)
	{
		if (is_collision(*obj, brick[i]))	
		{
			if (obj[0].vertical_speed > 0)
			{
				obj[0].is_flying = false;
			}
			
			if ( (brick[i].object_type == TYPE_BOX) && (obj[0].vertical_speed < 0) && (obj == &mario) )
			{
				brick[i].object_type = '-';
				init_object(get_new_moving_objects(), brick[i].x, brick[i].y-3, 3, 2, TYPE_COIN);
				moving_objects[moving_objects_count - 1].vertical_speed = COIN_DROP_SPEED;
			}
			(*obj).y -= (*obj).vertical_speed;
			(*obj).vertical_speed = 0;

			if(brick[i].object_type == TYPE_EXIT)
			{
				current_level++;
				if (current_level > max_level)
				{
					current_level = 1;
				}
				
				system(COLOR_WIN);
				Sleep(500);
				create_level(current_level);
			}
				
			break;
		}
	}
}

void delete_moving_objects(int i)
{
	moving_objects_count--;
	moving_objects[i] = moving_objects[moving_objects_count];
	
	if(moving_objects_count == 0)
	{
		free(moving_objects);
		moving_objects = NULL;
	}
	else
	{
		moving_objects = (Object*)realloc(moving_objects, sizeof(*moving_objects) * moving_objects_count);
	}
}

void mario_collision()
{
	for(int i = 0; i < moving_objects_count; i++)
	{
		if (is_collision(mario, moving_objects[i]))
		{
			if(moving_objects[i].object_type == TYPE_ENEMY)
			{
				if ( (mario.is_flying == TRUE)
					&& (mario.vertical_speed > 0)
					&& (mario.y + mario.height < moving_objects[i].y + moving_objects[i].height * 0.5)
				)
				{
					player_score += SCORE_FOR_KILL;
					delete_moving_objects(i);
					i--;
					continue;
				}
				else
				{
					player_dead();
				}
			}
			
			if(moving_objects[i].object_type == TYPE_COIN)
			{
				player_score += SCORE_FOR_COIN;
				delete_moving_objects(i);
				i--;
				continue;
			}
		}
	}
}

void horizontal_move_obj(Object *obj)
{
		(*obj).x += (*obj).horizontal_speed;
		
		for (int i = 0; i < brick_counts; i++)
		{
			if (is_collision(obj[0], brick[i]))
			{
			obj[0].x -= obj[0].horizontal_speed;
			obj[0].horizontal_speed = -obj[0].horizontal_speed;
			return;
			}
		}
		
		if (obj[0].object_type == TYPE_ENEMY)
		{
			Object tmp = *obj;
			vertical_move_object(&tmp);
			if(tmp.is_flying == TRUE)
			{
				obj[0].x -= obj[0].horizontal_speed;
				obj[0].horizontal_speed = -obj[0].horizontal_speed;
			}
		}
}

bool is_position_on_map(int x, int y)
{
	return ( (x >= 0) && (x < MAP_WIDTH) && (y >= 0) && (y < MAP_HEIGHT));
}

void put_object_on_map(Object obj){
	
	int ix = (int)round(obj.x - camera_x);
	int iy = (int)round(obj.y);
	int iWidth = (int)round(obj.width);
	int iHeight = (int)round(obj.height);

	for(int i = ix; i < (ix + iWidth); i++)
	{
		for (int j = iy; j < (iy + iHeight); j++)
		{
			if (is_position_on_map(i, j) &&  j > 1)
			{
				map[j][i] = obj.object_type;
			}
		}
	}
}

void set_current_pos(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void horizontal_move_map(float dx)
{	
	float old_x = mario.x;
	mario.x -= dx;
	
	for (int i = 0; i < brick_counts; i++)
	{
		if (is_collision(mario, brick[i]))
		{
			mario.x = old_x;
			return;
		}
	}
	
	camera_x = mario.x - MAP_WIDTH / 2;
	
	if (camera_x < 0)
	{
		camera_x = 0;
	}
	
	for(int i = 0; i < brick_counts; i++)
	{
		brick[i].x += dx;
	}
	
	for(int i = 0; i < moving_objects_count; i++)
	{
		moving_objects[i].x += dx;
	}
}

bool is_collision(Object obj_1, Object obj_2)
{
	return ((obj_1.x + obj_1.width) > obj_2.x) && (obj_1.x < (obj_2.x + obj_2.width)) && ((obj_1.y + obj_1.height) > obj_2.y) && (obj_1.y < (obj_2.y + obj_2.height));	
}

Object *get_new_brick()
{
	brick_counts++;
	brick = (Object*)realloc(brick, sizeof(*brick) * brick_counts);
	return brick + brick_counts - 1;
}

Object *get_new_moving_objects()
{
	moving_objects_count++;
	moving_objects = (Object*)realloc(moving_objects, sizeof(*brick) * moving_objects_count);
	return moving_objects + moving_objects_count - 1;
}

void put_score_on_map()
{
	 for(int i = 5; i < 45; i++)
	 {
        map[1][i] = ' ';
	 }
	 
	char c[30];
	sprintf(c, "player_score: %d", player_score);
	int len = strlen(c);
	for(int i = 0; i < len; i++)
	{
		map[1][i+5] = c[i];
	}
}

void free_game_resources() {
    if (brick != NULL)
	{
        free(brick);
        brick = NULL;
    }

    if (moving_objects != NULL)
	{
        free(moving_objects);
        moving_objects = NULL;
    }
}

void create_level(int lvl)
{
	system(COLOR_DEFAULT);

	free_game_resources();

	brick_counts = 0;
	moving_objects_count = 0;
	
	init_object(&mario, 39, 10, 3, 3, TYPE_MARIO);
	player_score = 0;
	camera_x = 0;
	
	if(lvl == 1)
	{
		init_object(get_new_brick(), 20, 20, 40, 5, TYPE_BRICK);
			init_object(get_new_brick(), 30, 10, 5, 3, TYPE_BOX);
			init_object(get_new_brick(), 50, 10, 5, 3, TYPE_BOX);
		init_object(get_new_brick(), 60, 15, 40, 10, TYPE_BRICK);
			init_object(get_new_brick(), 60, 5, 10, 3, TYPE_LINES);
			init_object(get_new_brick(), 70, 5, 5, 3, TYPE_BOX);
			init_object(get_new_brick(), 75, 5, 5, 3, TYPE_LINES);
			init_object(get_new_brick(), 80, 5, 5, 3, TYPE_BOX);
			init_object(get_new_brick(), 80, 5, 10, 3, TYPE_LINES);
		init_object(get_new_brick(), 100, 20, 20, 5, TYPE_BRICK);
		init_object(get_new_brick(), 120, 15, 10, 10, TYPE_BRICK);
		init_object(get_new_brick(), 150, 20, 40, 5, TYPE_BRICK);
		init_object(get_new_brick(), 210, 15, 10, 10, TYPE_EXIT);
		
		init_object(get_new_moving_objects(), 25, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 80, 10, 3, 2, TYPE_ENEMY);
		
		
	}
	
	if(lvl == 2)
	{
		init_object(get_new_brick(), 20, 20, 40, 5, TYPE_BRICK);
			init_object(get_new_brick(), 30, 10, 5, 3, TYPE_BOX);
			init_object(get_new_brick(), 50, 10, 5, 3, TYPE_BOX);
		init_object(get_new_brick(), 60, 15, 10, 10, TYPE_BRICK);
		init_object(get_new_brick(), 80, 20, 20, 5, TYPE_BRICK);
		init_object(get_new_brick(), 120, 15, 10, 10, TYPE_BRICK);
			init_object(get_new_brick(), 122, 5, 5, 3, TYPE_BOX);
		init_object(get_new_brick(), 150, 20, 40, 5, TYPE_BRICK);
		init_object(get_new_brick(), 210, 15, 10, 10, TYPE_EXIT);
		
		init_object(get_new_moving_objects(), 25, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 80, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 65, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 120, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 160, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 175, 10, 3, 2, TYPE_ENEMY);
		
		init_object(get_new_moving_objects(), 25, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 80, 10, 3, 2, TYPE_ENEMY);
	}
	
	if(lvl == 3)
	{
		init_object(get_new_brick(), 20, 20, 40, 5, TYPE_BRICK);
		init_object(get_new_brick(), 80, 20, 15, 5, TYPE_BRICK);
		init_object(get_new_brick(), 120, 15, 15, 10, TYPE_BRICK);
		init_object(get_new_brick(), 160, 10, 15, 15, TYPE_EXIT);
		
		init_object(get_new_moving_objects(), 25, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 50, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 80, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 90, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 120, 10, 3, 2, TYPE_ENEMY);
		init_object(get_new_moving_objects(), 130, 10, 3, 2, TYPE_ENEMY);
	}
	
	max_level;
}

int main()
{	
	create_level(current_level);
	
	do{
		clear_map();
		
		if ( (mario.is_flying == false) && (GetKeyState(VK_SPACE) < 0) )
		{
			mario.vertical_speed = JUMP_POWER;
		}
		if (GetKeyState('A') < 0)
		{
			horizontal_move_map(1);
		}
		if (GetKeyState('D') < 0)
		{
			horizontal_move_map(-1);
		}
		
		if (MAP_HEIGHT < mario.y || mario.y < 0)
		{
			player_dead();
		}
		
		vertical_move_object(&mario);
		mario_collision();
		
		for(int i = 0; i < brick_counts; i++)
		{
			put_object_on_map(brick[i]);
		}
		for(int i = 0; i < moving_objects_count; i++)
		{	
			vertical_move_object(moving_objects + i);
			horizontal_move_obj(moving_objects + i);
			put_object_on_map(moving_objects[i]);
		}
		
		put_object_on_map(mario);
		put_score_on_map();
		
		set_current_pos(0, 0);
		show_map();
		
		Sleep(10);
	}
	while(GetKeyState(VK_ESCAPE) >= 0);
		
	return 0;
}
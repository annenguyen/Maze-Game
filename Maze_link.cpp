#include "maze_link.h"

Maze_Link::Maze_Link()
{
		num = 0;		
		next = NULL;
		below = NULL;
		door = false;	// indicate if this is a door
		door_val = 0;
		item = false;	//indicate if this is an item
		item_val = 0; 
}
void Maze_Link::set_door(bool d)
{
	door = d;
}
void Maze_Link::set_door_val(int d)
{
	door_val = d;
}
void Maze_Link::set_item(bool i)
{
	item = i;
}	
void Maze_Link::set_item_val(int i)
{
	item_val = i;
}
		
bool Maze_Link::get_door()
{
	return door;
}
int Maze_Link::get_door_val()
{
	return door_val;
}
bool Maze_Link::get_item()
{
	return item;
}
int Maze_Link::get_item_val()
{
	return item_val;
} 
		
void Maze_Link::set_num(int n)
{
	num = n;
}
void Maze_Link::set_next(Maze_Link * nxt_ptr)
{
	next = nxt_ptr;
}
void Maze_Link::set_below(Maze_Link * blw_ptr)
{
	below = blw_ptr;
}
		
int Maze_Link::get_num()
{
	return num;
}
Maze_Link * Maze_Link::get_next()
{
	return next;
}
Maze_Link * Maze_Link::get_below()
{
	return below;
}
void Maze_Link::display()
{
	cout << num;
}
Maze_Link::~Maze_Link()
{
}

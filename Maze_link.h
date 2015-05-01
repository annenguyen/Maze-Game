#ifndef MAZE_LINK_H
#define MAZE_LINK_H
#include <iostream>
using namespace std;
class Maze_Link
{
	private:
		int num;	// contains 0, 1, or monster decrement
		bool door;	// indicate if this is a door
		int door_val;
		bool item;	//indicate if this is an item
		int item_val; 
		
		Maze_Link * next;
		Maze_Link * below;
	public:
		Maze_Link();
		void set_door(bool);
		void set_door_val(int);
		void set_item(bool);	
		void set_item_val(int);
				
		bool get_door();
		int get_door_val();
		bool get_item();	
		int get_item_val(); 
		
		void set_num(int);
		int get_num();
		
		void set_next(Maze_Link *);
		void set_below(Maze_Link *);
		
		Maze_Link * get_next();
		Maze_Link * get_below();
		
		void display();
		
		~Maze_Link();
	protected:
};

#endif

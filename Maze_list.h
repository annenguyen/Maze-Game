#ifndef MAZE_LIST_H
#define MAZE_LIST_H
#include "Maze_Link.h"
class Maze_List
{
	private:
		int size;		
		Maze_Link * first;

		
	public:
		Maze_List();
		void set_num(int, int, int);
		int get_num(int, int);
		
		void set_door(bool, int, int);
		void set_door_val(int, int, int);
		void set_item(bool, int, int);	
		void set_item_val(int, int, int);
				
		bool get_door(int, int);
		int get_door_val(int, int);
		bool get_item(int, int);	
		int get_item_val(int, int); 
		
		void display();
		~Maze_List();
	protected:
};

#endif

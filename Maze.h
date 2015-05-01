#ifndef MAZE_H
#define MAZE_H
#include <cstdlib>
#include "Link.h"
#include "List.h"
#include "Stack.h"
#include "Maze_List.h"

class Maze
{
	
	private:
		Maze_List my_maze;
		int lifespan;
        int entrance_x, entrance_y;
		int maze_size;
		Stack maze_stack;
		
		List item_list;
		
	public:
		Maze();

		void set_entrance(int, int);
		void set_lifespan(int);
		int get_lifespan();
		Link * search_path();
		
		void display_path(Link *);
		bool check_exit(Link *);
	
		void display_top();
	
		Link * generate_child(int, int, Link *);
		
		void display_maze(Link *);

		Maze_List get_my_maze();
		
		void display_item_list();
		
		
		
		
		~Maze();

};

#endif

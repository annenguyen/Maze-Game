#include "Maze.h"

Maze::Maze()
{
	maze_size = 11;
	// maze linked list initialized
	my_maze.set_num(0,2,0);
	my_maze.set_num(0,2,1);	
	my_maze.set_num(0,3,1);
	my_maze.set_num(0,4,1);
	my_maze.set_num(0,5,1);
	my_maze.set_num(0,2,2);
	my_maze.set_num(0,2,3);
	my_maze.set_num(0,2,4);
	my_maze.set_num(0,2,5);
	my_maze.set_num(0,2,6);
	my_maze.set_num(0,2,7);
	my_maze.set_num(0,2,8);
	my_maze.set_num(0,3,8);
	my_maze.set_num(0,4,8);
	my_maze.set_num(0,5,8);
	my_maze.set_num(0,5,7);
	my_maze.set_num(0,5,6);
	my_maze.set_num(0,6,6);	
	my_maze.set_num(0,6,5);
	my_maze.set_num(0,6,4);
	my_maze.set_num(0,6,3); 
	my_maze.set_num(0,6,2);
	my_maze.set_num(0,7,2);
	my_maze.set_num(0,7,1);
	my_maze.set_num(0,8,1);
	my_maze.set_num(0,9,1); 
	my_maze.set_num(0,9,2);
	my_maze.set_num(0,10,2);
	my_maze.set_num(0,11,2);
	my_maze.set_num(0,2,9);
	my_maze.set_num(0,2,10);
	my_maze.set_num(0,1,10);
	my_maze.set_num(0,3,10);
	my_maze.set_num(0,0,2);
	my_maze.set_num(0,0,3);
	my_maze.set_num(0,0,4);
	my_maze.set_num(0,1,2);
	my_maze.set_num(0,3,1);
	my_maze.set_num(0,3,2);
	my_maze.set_num(0,3,3);
	my_maze.set_num(0,4,3);
	my_maze.set_num(0,3,4);
	my_maze.set_num(0,3,5);
	my_maze.set_num(0,9,3);
	my_maze.set_num(0,9,4);
	my_maze.set_num(0,9,5);
	my_maze.set_num(0,8,5);
	my_maze.set_num(0,10,5);
	my_maze.set_num(0,10,6);
	my_maze.set_num(0,10,7);
	my_maze.set_num(0,9,7);
	my_maze.set_num(0,8,7);
	my_maze.set_num(0,7,7);
	my_maze.set_num(0,4,10);
	my_maze.set_num(0,5,10);
	my_maze.set_num(0,6,10);
	my_maze.set_num(0,7,10);
	my_maze.set_num(0,8,10);
	my_maze.set_num(0,9,10);

}
void Maze::set_lifespan(int l)
{
	lifespan = l;
}

int Maze::get_lifespan()
{
	return lifespan;
}

void Maze::set_entrance(int x, int y)
{
	Link * a_link = new Link;
	entrance_x = x;
	entrance_y = y;
	

	a_link->set_x_coord(x);
	a_link->set_y_coord(y);
	maze_stack.push(a_link);
	
}

void Maze::display_top()
{
	maze_stack.display_top();
}

bool Maze::check_exit(Link * l_pntr)
{

	// check not entrance
	if ((l_pntr->get_x_coord() == entrance_x) 
		&& (l_pntr->get_y_coord() == entrance_y))
		{
			return false;
		}
	else		
	{	// check col == (n-1) or col == 0
		if((l_pntr->get_y_coord() == maze_size) ||
			(l_pntr->get_y_coord()== 0))
		{
			return true;
		}
		
		if ((l_pntr->get_x_coord() == maze_size) ||
			(l_pntr->get_x_coord() == 0))
		{
			return true;
		}
		else
		
		return false;
	}		

}

Link * Maze::search_path()
{
	Link * temp;
	Link * temp_2;
	bool done, exit, entrance_flag;
	int link_x, link_y;
	int parent_x, parent_y;
	
	done = false;
	int round;
	round = 0;
	
								
	while ((maze_stack.get_size() > 0) && (done != true) && (lifespan > 0))
	{
		entrance_flag = false;
		temp = maze_stack.pop();

			
		// check if this is exit
		exit = check_exit(temp);
			
		if (exit)
		{
			done = true;
		}
		else
		{
			link_x = temp->get_x_coord();
			link_y = temp->get_y_coord();
	
			if ((link_x == entrance_x) && (link_y == entrance_y))
			{
				entrance_flag = true; 			
			}	
			else
			{
				entrance_flag = false;				
				parent_x = temp->get_parent()->get_x_coord();
				parent_y = temp->get_parent()->get_y_coord();							
			}
			
				
			// same y as parent
			if ( entrance_flag || (link_y == parent_y))
			{
				temp_2 = generate_child(link_x, link_y+1, temp);
				if (temp_2 != NULL)
				{
					maze_stack.push(temp_2);					
				}
				
				temp_2 = generate_child(link_x, link_y-1, temp);
				if (temp_2 != NULL)
				{
					maze_stack.push(temp_2);
				}
				
				if(entrance_flag == false)
				{
					if(link_x > parent_x)
					{
						temp_2 = generate_child(link_x+1, link_y, temp);
						if (temp_2 != NULL)
						{
							maze_stack.push(temp_2);	
						}	
					}
					else
					{
						temp_2 = generate_child(link_x-1, link_y, temp);
						if (temp_2 != NULL)
						{
							maze_stack.push(temp_2);		
						}					
					}
				}
			}
			
			// same x as parent
			if ( entrance_flag || (link_x == parent_x) )
			{
				temp_2 = generate_child(link_x+1, link_y, temp);
				if (temp_2 != NULL)
				{
					maze_stack.push(temp_2);	
				}
				
				temp_2 = generate_child(link_x-1, link_y, temp);
				if (temp_2 != NULL)
				{
					maze_stack.push(temp_2);
				}
				if (entrance_flag == false)
				{
					if(link_y > parent_y)
					{
						temp_2 = generate_child(link_x, link_y+1, temp);
						if (temp_2 != NULL)
						{
							maze_stack.push(temp_2);
						}	
					}
					else
					{
						temp_2 = generate_child(link_x, link_y-1, temp);
						if (temp_2 != NULL)
						{
							maze_stack.push(temp_2);	
						}					
					}	
				}
				
			}
		}	// end of else	
		round++;
		
	}	// while loop
	
	
	if(exit)
		return temp;
	else
		return NULL;

}

Link * Maze::generate_child(int x, int y, Link * p_link)
{	// this method generates a link for a child if possible
	// else it will return null
	Link * a_link = new Link;
	Item * an_item;
	bool print_path = false;
	
	
	if((my_maze.get_num(x,y) == 1) || (x < 0) || (x > maze_size) || (y < 0) || (y > maze_size))
	{	// it is blocked
		delete a_link;
		print_path = false;
		return NULL;
	}
	else
	{	
		print_path = true;
		// process monster decrement
		if (my_maze.get_num(x,y) < 0)
		{
			// display_maze(a_link);
			system("CLS");
			cout << "You have encountered a monster."<< endl;
			lifespan = lifespan + my_maze.get_num(x,y);
			cout << "Your life level: " << lifespan << endl;
			if (lifespan <= 0)
			{
				cout<< "Your life level is "<<lifespan<< ". Game Over." << endl;
			}
			// system("PAUSE");
		}
		
		// check and process if this is an item
		if (my_maze.get_item(x,y))
		{
			system("CLS");
			cout << "You have encountered a key."<< endl;
			system("PAUSE");
			an_item = new Item;
			// cout<< "my maze get item val : " << my_maze.get_item_val(x, y) << endl;
			an_item->set_value(my_maze.get_item_val(x, y));
			item_list.add(an_item);
		}
	
		if ((my_maze.get_door(x,y)) && (item_list.find_item(my_maze.get_door_val(x,y)))
		|| (my_maze.get_door(x,y) == false))
		{
			if ((my_maze.get_door(x,y)) && (item_list.find_item(my_maze.get_door_val(x,y))))
			{
				system("CLS");
				cout << "You have encountered a door and you have a key."<< endl;
				system("PAUSE");
			}

			// this link can go
			a_link->set_x_coord(x);
			a_link->set_y_coord(y);
			a_link->set_parent(p_link);	

		}	
		else
		{
			system("CLS");
			cout << "You have encountered a door but you don't have a key."<< endl;
			system("PAUSE");
			delete a_link;
			print_path = false;	
		} 
		
		if (print_path)
			display_maze(a_link);
			

		return a_link;
	}
}


void Maze::display_path(Link * link_pointer)
{

	Link * temp;
	temp = link_pointer;
	
	while (temp != NULL)
	{
	// if link is not null then print coordinates		
		temp->display();
		temp = temp->get_parent();
	}
}

void Maze::display_item_list()
{
	item_list.display();
}

void Maze::display_maze (Link * link_pointer)
{
	Maze_List temp_maze;

	Link * temp;
	int x;
	int y, value;
	
	// populate the matrix with the potential path
	for (int i = 0; i<12; i++)
	{
		for (int j = 0; j<12; j++)
		{
			value = my_maze.get_num(j,i);
			if (value < 0)
			{
				value = 0;
			}
			temp_maze.set_num(value, j, i);	
		}
	}

	
	temp = link_pointer;		
	// populate the matrix with the chosen path
	while (temp != NULL)
	{
		// if link is not null then populate the matrix position		
		x = temp->get_x_coord();
		y = temp->get_y_coord();
		
		temp_maze.set_num(2, x, y);	
		// going back to the parent
		temp = temp->get_parent();
	}
	
		
	// print out matrix
	for (int i = 0; i<12; i++){
		for (int j = 0; j<12; j++)
		{
			if (temp_maze.get_num(j,i) == 2)
			{
				cout << "x";
			}
			else if (temp_maze.get_num(j,i) == 0)
			{
				cout << " ";
			}
			else
			{
				cout << "\333";
			}
		}
		cout << endl;
	}
	system("PAUSE");
	system("CLS");
}


Maze_List Maze::get_my_maze()
{
	return my_maze;
}

Maze::~Maze()
{
}

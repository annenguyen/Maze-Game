#include "maze_list.h"

Maze_List::Maze_List()
{
	size = 12;
	Maze_Link * m_link;  
	Maze_Link * x_next;
	Maze_Link * y_next;
	Maze_Link * y_now;
	
	for(int y= 12; y > 0; y--)	
	{
		for (int x= 12; x > 0; x--)
		{
			// initialize the row
			m_link = new Maze_Link;
			m_link->set_num(1);
			
			if(x < 12)
			{
				m_link->set_next(x_next);
			}
			x_next = m_link;
			
			if(x == 1)
			{
				y_now = m_link;
			}
		}
		
		if(y < 12)
		{
			y_now->set_below(y_next);
				
		}
		y_next = y_now;
		
		if(y == 1)
		{
			first = y_now;
		}
	}	
	
}

void Maze_List::set_num(int value, int x, int y)
{
	Maze_Link * temp;
	temp = first;
	// move in the y direction
	if(y > 0)
	{
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}	
	
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j <x; j++)
		{
			temp = temp->get_next();
		}	
	}
	
	//set the value
	temp->set_num(value);

}

int Maze_List::get_num(int x, int y)
{
	Maze_Link * temp;
	temp = first;
	if(y > 0)
	{
		// move in the y direction
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j < x; j++)
		{
			temp = temp->get_next();
		}
	}
	
	//return the value
	return temp->get_num();
}
void Maze_List::set_door(bool d, int x, int y)
{
	Maze_Link * temp;
	temp = first;
	// move in the y direction
	if(y > 0)
	{
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}	
	
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j <x; j++)
		{
			temp = temp->get_next();
		}	
	}
	
	//set whether it is a door or not
	temp->set_door(d);
}
void Maze_List::set_door_val(int value, int x, int y)
{
	Maze_Link * temp;
	temp = first;
	// move in the y direction
	if(y > 0)
	{
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}	
	
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j <x; j++)
		{
			temp = temp->get_next();
		}	
	}
	
	//set the door's code
	temp->set_door_val(value);
}
void Maze_List::set_item(bool i, int x, int y)
{
	Maze_Link * temp;
	temp = first;
	// move in the y direction
	if(y > 0)
	{
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}	
	
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j <x; j++)
		{
			temp = temp->get_next();
		}	
	}
	
	//set whether it is a item or not
	temp->set_item(i);
}	
void Maze_List::set_item_val(int value, int x, int y)
{
	Maze_Link * temp;
	temp = first;
	// move in the y direction
	if(y > 0)
	{
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}	
	
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j <x; j++)
		{
			temp = temp->get_next();
		}	
	}
	
	//set the door's code
	temp->set_item_val(value);	
}
				
bool Maze_List::get_door(int x, int y)
{
	Maze_Link * temp;
	temp = first;
	if(y > 0)
	{
		// move in the y direction
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j < x; j++)
		{
			temp = temp->get_next();
		}
	}
	
	//return the value
	return temp->get_door();	
}
int Maze_List::get_door_val(int x, int y)
{
	Maze_Link * temp;
	temp = first;
	if(y > 0)
	{
		// move in the y direction
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j < x; j++)
		{
			temp = temp->get_next();
		}
	}
	
	//return the value
	return temp->get_door_val();
}
bool Maze_List::get_item(int x, int y)
{
	Maze_Link * temp;
	temp = first;
	if(y > 0)
	{
		// move in the y direction
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j < x; j++)
		{
			temp = temp->get_next();
		}
	}
	
	//return the value
	return temp->get_item();
}	
int Maze_List::get_item_val(int x, int y)
{
	Maze_Link * temp;
	temp = first;
	if(y > 0)
	{
		// move in the y direction
		for(int i= 0; i <y; i++)
		{
			temp = temp->get_below();
		}	
	}
	if(x > 0)
	{
		//move in the x direction
		for(int j = 0; j < x; j++)
		{
			temp = temp->get_next();
		}
	}
	
	//return the value
	return temp->get_item_val();
} 

void Maze_List::display()
{
	Maze_Link * x_temp;
	Maze_Link * y_temp;
	
	x_temp = first;
	y_temp = first;
	
	for(int y= 0; y < 12; y++)	
	{
		for (int x= 0; x < 12; x++)
		{
			//cout << x_temp->get_num();
			cout << x_temp->get_item_val() << "x" << x_temp->get_door_val() <<" ";			
			x_temp = x_temp->get_next();
		}

		cout << endl;
		y_temp = y_temp->get_below();
		x_temp = y_temp;		
	}		
}

Maze_List::~Maze_List()
{
}

#include "List.h"

List::List()
{
	first = NULL;

	
}
void List::add(Item* a_item)
{
	a_item->set_next(first);
	first = a_item;

}

bool List::find_item(int value)
{
	Item * temp; 
	temp = first;
	while (temp != NULL)
	{
		if ((temp->get_value() == value))			
		{
			return true;
		}
		else
		{
			temp = temp->get_next();
		}
	}
	return false;
}

void List::display()
{
	Item * temp;
	temp = first;

	while (temp != NULL)
	{
		temp->display();
		temp = temp->get_next();
	}
}

List::~List()
{
}

#include "Link.h" // class's header file

// class constructor
Link::Link()
{
	// insert your code here
    x_coord = 0;
    y_coord = 0;
	_next = NULL;
	_parent = NULL;
}

void Link::set_x_coord(int x)
{
	x_coord = x;
}
void Link::set_y_coord(int y)
{
	y_coord = y;
}

void Link::set_parent(Link * p_Link)
{
     _parent = p_Link;    
}

void Link::set_next(Link * n_Link)
{
     _next = n_Link;   
}

void Link::display()
{
	cout << "x coordinate: " << x_coord << " y coordinate:  " << y_coord << endl;
}

Link * Link::get_parent()
{
     return _parent;
}

Link * Link::get_next()
{
     return _next;
}

int Link::get_x_coord()
{
	return x_coord;
}

int Link::get_y_coord()
{
	return y_coord;
}

// class destructor
Link::~Link()
{
	// insert your code here
}

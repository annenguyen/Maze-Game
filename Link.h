#include<iostream>
#ifndef LINK_H
#define LINK_H

using namespace std;
class Link
{
    private:
    		int x_coord;
    		int y_coord;
    		
			Link * _parent;
            Link * _next;  
	public:
		// class constructor
		Link();
		void set_x_coord(int);
		void set_y_coord(int);
		
		void set_parent(Link *);
		void set_next(Link *);
		
		void display();
		
		int get_x_coord();
		int get_y_coord();
		
        Link * get_next();
		Link * get_parent();
  

		// class destructor
		~Link();
};

#endif // LINK_H

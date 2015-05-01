#include <iostream>
#ifndef LIST_H
#define LIST_H
#include "Item.h"
using namespace std;
class List
{
	private:
		Item * first;
		
	public:
		List();
		void add(Item*);
		bool find_item(int);
		void display();
		~List();

};

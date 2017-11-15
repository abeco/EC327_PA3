#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "CartPoint.h"
#include "CartVector.h"
using namespace std;

class GameObject{
	private:
		int id_num;
	protected:
		CartPoint location;
		char display_code;
		char state;
	public:
		GameObject(char in_code, int in_id);
		GameObject(char in_code, int in_id, CartPoint in_loc);
		CartPoint get_location();
		int get_id();
		//regular virtual, definition in gameobject.cpp as well as others
		virtual void show_status();
		//on that pure virtual flow -- this wasn't throwing an error before?
		//needed to include a blank function in the .cpp
		//pure virtual stuff is weird
		virtual bool update() = 0;
		//destructors. no clue what I'm doing with these
		virtual ~GameObject();

		void drawself(char* grid);
};

#endif


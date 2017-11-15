#ifndef PORT_H
#define PORT_H

#include "GameObject.h"
#include "CartPoint.h"
//#include "CartVector.h"


class Port:public GameObject{
	private:
		double inventory;
	public:
		Port();
		Port(int in_id, CartPoint in_loc);
		~Port();
		bool is_empty();
		double provide_supplies(double amount_to_provide = 50);
		bool update();
		void show_status();
};

#endif
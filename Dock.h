#ifndef DOCK_H
#define DOCK_H

#include "GameObject.h"
#include "CartPoint.h"
#include "Sailor.h"

class Sailor;

class Dock : public GameObject{
	private:
		double berths;
	public:
		Dock();
		Dock(int in_id, CartPoint in_loc);
		~Dock();
		bool dock_boat(Sailor* sailor_to_dock);
		bool set_sail(Sailor* sailor_to_sail);
		bool update();
		void show_status();
};

#endif
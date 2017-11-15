#ifndef SAILOR_H
#define SAILOR_H

#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Port.h"
#include "Dock.h"

class Dock;

class Sailor : public GameObject{
	private:
		double health;
		double size;
		double hold;
		double cargo;
		CartPoint destination;
		CartVector delta;
		Port* port;
		Dock* dock;
		Dock* hideout;
		bool update_location();
		void setup_destination(CartPoint dest);
	public:
		Sailor();
		Sailor(int in_id, Dock* hideout);
		~Sailor();
		bool update();
		double get_size();
		double get_cargo();
		void start_sailing(CartPoint dest);
		void start_supplying(Port* dest);
		void start_hiding();
		bool is_hidden();
		void start_docking(Dock* destDock);
		void anchor();
		void show_status();
		double get_speed();
		double original_size;

};



#endif
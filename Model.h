#ifndef MODEL_H
#define MODEL_H

#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"

using namespace std;
//I think I need this
//really its a good thing I went to 307 last night
class View;

class Model {
	private:
		int time;
		GameObject** object_ptrs;
		int num_objects;
		Sailor** sailor_ptrs;
		int num_sailors;
		Dock** dock_ptrs;
		int num_docks;
		Port** port_ptrs;
		int num_ports;
	public:
		Model();
		//learn what destructors are/do
		~Model();
		Sailor* get_sailor_ptr(int id_num);
		Port* get_port_ptr(int id_num);
		Dock* get_dock_ptr(int id_num);
		bool update();
		void display(View& view);
		void show_status();
};

#endif
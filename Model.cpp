#include <iostream>
using namespace std;

#include "Model.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"
#include "View.h"

/*Model::Model(){
	time = 0;
	num_objects = 10;
	num_sailors = 3;
	num_ports = 4;
	num_docks = 3;
	Dock* dock1 = new Dock(1, CartPoint(5, 1));
	Dock* dock2 = new Dock(2, CartPoint(6, 2));
	Dock* dock3 = new Dock(3, CartPoint(1, 8));

	dock_ptrs = {dock1 , dock2 , dock3};

	Sailor* sailor1 = new Sailor(1, dock1);
	Sailor* sailor2 = new Sailor(2, dock2);
	Sailor* sailor3 = new Sailor(3, dock3);

	sailor_ptrs = {sailor1 , sailor2 , sailor3};

	Port* port1 = new Port(1, CartPoint(1, 20));
	Port* port2 = new Port(2, CartPoint(20, 1));
	Port* port3 = new Port(3, CartPoint(20, 20));
	Port* port4 = new Port(4, CartPoint(7, 2));

	port_ptrs = {port1 , port2 , port3 , port4};

	object_ptrs = {dock1 , dock2 , dock3 , sailor1 , sailor2, sailor3 , port1 , 
		port2 , port3 , port4};
	cout<<"Model default constructed"<<endl;
}*/

Model::Model(){
	time = 0;
	this->dock_ptrs = new Dock*[3];
    this->dock_ptrs[0] = new Dock(1, CartPoint(5, 1));
    this->dock_ptrs[1] = new Dock(2, CartPoint(6, 2));
    this->dock_ptrs[2] = new Dock(3, CartPoint(1, 8));
    this->num_docks = 3;

    // - 4 ports
    this->port_ptrs = new Port*[4];
    this->port_ptrs[0] = new Port(1, CartPoint(1, 20));
    this->port_ptrs[1] = new Port(2, CartPoint(20, 1));
    this->port_ptrs[2] = new Port(3, CartPoint(20, 20));
    this->port_ptrs[3] = new Port(4, CartPoint(7, 2));
    this->num_ports = 4;

    // - 3 sailors
    this->sailor_ptrs = new Sailor*[3];
    this->sailor_ptrs[0] = new Sailor(1, dock_ptrs[0]);
    this->sailor_ptrs[1] = new Sailor(2, dock_ptrs[1]);
    this->sailor_ptrs[2] = new Sailor(3, dock_ptrs[2]);
    this->num_sailors = 3;

    this->object_ptrs = new GameObject*[10];
    this->object_ptrs[0] = dock_ptrs[0];
    this->object_ptrs[1] = dock_ptrs[1];
    this->object_ptrs[2] = dock_ptrs[2];

    this->object_ptrs[3] = sailor_ptrs[0];
    this->object_ptrs[4] = sailor_ptrs[1];
    this->object_ptrs[5] = sailor_ptrs[2];

    this->object_ptrs[6] = port_ptrs[0];
    this->object_ptrs[7] = port_ptrs[1];
    this->object_ptrs[8] = port_ptrs[2];
    this->object_ptrs[9] = port_ptrs[3];
    this->num_objects = 10;

    cout<<"Model default constructed"<<endl;
}

Model::~Model(){
	for(int i = 0; i < num_objects; i++){
		delete object_ptrs[i];
	}

	cout<<"Model destructed"<<endl;
}

Sailor* Model::get_sailor_ptr(int id_num){
	//cout<<"got here get sailor ptr"<<endl;
	for(int i = 0; i < num_sailors; i++){
		if(id_num == sailor_ptrs[i]->get_id())
			return sailor_ptrs[i];
	}
	return NULL;	
}

Port* Model::get_port_ptr(int id_num){
	for(int i = 0; i < num_ports; i++){
		if(id_num == port_ptrs[i]->get_id())
			return port_ptrs[i];
	}
	return NULL;
}

Dock* Model::get_dock_ptr(int id_num){
	for(int i = 0; i < num_docks; i++){
		//cout<<"i: "<<i<<"\t dock_ptrs->get_id(): "<<dock_ptrs[i]->get_id()<<endl;
		if(id_num == dock_ptrs[i]->get_id()){
			//cout<<"i: "<<i<<endl;
			//cout<<"got here get dock ptr"<<endl;
			return dock_ptrs[i];
		}
	}
	//cout<<"got here get dock ptr NULL"<<endl;
	return NULL;	
	
}

//won't this stop after the first object returns either true or false?
//should I create a bool array, and if they're all false return false?
//I like this idea, it's well thought out
bool Model::update(){
	time = time + 1;
	//cout<<"time: "<<time<<endl;
	bool* values = new bool[num_objects];
	/*for(int i = 0; i < num_objects; i++){
		//do i need this call? I don't think so
		//GameObject::update(object_ptrs[i]);
		values[i] = object_ptrs[i]->update();
	}*/
	for(int i = 0; i < num_objects; i++){
		values[i] = object_ptrs[i]->update();
	}
	for(int i = 0; i < num_objects; i++){
		if(values[i])
			return true;
	}
	return false;
}
//figure this one out after you understand more stuff
void Model::display(View& view){
	cout<<"Time: "<<time<<endl;
	view.clear();

	for(int i = 0; i < num_objects; i++){
		view.plot(object_ptrs[i]);
	}
	view.draw();
}

void Model::show_status(){
	for(int i = 0; i < num_objects; i++){
		object_ptrs[i]->show_status();
	}
}


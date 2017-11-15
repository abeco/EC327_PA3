#include <iostream>
using namespace std;

#include "Dock.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "Sailor.h"

//this default constructor is probably never going to be used
Dock::Dock() : GameObject('d' , 0){
	state = 'u';
	berths = 30;
	cout<<"Dock default constructed"<<endl;
}

Dock::Dock(int in_id , CartPoint in_loc) : GameObject('d' , in_id , in_loc){
	state = 'u';
	berths = 30;
	//cout<<"Berths: "<<berths<<endl;
	cout<<"Dock constructed"<<endl;
}

Dock::~Dock(){
	cout<<"Dock destructed"<<endl;
}
//somewhere in here set the state to p
bool Dock::dock_boat(Sailor* sailor_to_dock){
	//double* original_size = sailor_to_dock->get_size();
	sailor_to_dock->original_size = sailor_to_dock->get_size();
	if(berths >= sailor_to_dock->get_size()){
		//cout<<"Got here"<<endl;
		berths = berths - sailor_to_dock->get_size();
		return true;
	}
	return false;
}
//somewhere in here set the state to u
bool Dock::set_sail(Sailor* sailor_to_sail){
	if(sailor_to_sail->get_cargo() == 0){
		//make sure to update space based on sailors original size,
		//not the size he leaves with(which will always be bigger)
		//idiot, just do -5
		//cout<<"old value of berths: "<<berths<<endl; 
		//cout<<"got to set_sail. size of sailor is "<<sailor_to_sail->get_size()<<endl;
		berths += sailor_to_sail->original_size;
		//cout<<"new value of berths: "<<berths<<endl;
		//berths += *original_size;
		return true;
	}
	else
		return false;
}

bool Dock::update(){
	//cout<<"Update Berths: "<<berths<<endl;
	if(berths == 0 && state != 'p'){
		state = 'p';
		display_code = 'D';
		cout<<"Dock"<<get_id()<<" is packed"<<endl;
		return true;
	}
	else if(berths > 0 && state == 'p'){
		state = 'u';
		display_code = 'd';
		cout<<"Dock"<<get_id()<<"is unpacked"<<endl;
		return true;
	}
	else
		return false;
}

void Dock::show_status(){
	//cout<<"Show status berths: "<<berths<<endl;
	cout<<"Dock Status: "<<display_code<<" with ID "<<get_id()<<
	" at location "<<location<<" has "<<berths<< " berths"<<endl;
}

#include <iostream>
using namespace std;

#include "Port.h"
#include "GameObject.h"
#include "CartPoint.h"


//never going to really use this default constructor
Port::Port() : GameObject('P', 0) {
	//display_code = 'P';
	state = 'f';
	inventory = 500;
	cout<<"Port default constructed"<<endl;
}
//gonna use this one
Port::Port(int in_id, CartPoint in_loc) : GameObject('P',in_id, in_loc){
	//display_code = 'P';
	state = 'f';
	inventory = 500;
	//id_num = in_id;
	//location = in_loc;
	cout<<"Port constructed"<<endl;
}

Port::~Port(){
	cout<<"Port destructed"<<endl;
}

bool Port::is_empty(){
	if(inventory == 0)
		return true;
	else
		return false;
}

double Port::provide_supplies(double amount_to_provide){
	if(inventory >= amount_to_provide){
		inventory = inventory - amount_to_provide;
		return amount_to_provide;
	}
	else{
		double temp = inventory;
		inventory = 0;
		return temp;
	}
}

bool Port::update(){
	if(is_empty() && state != 'e'){
	//if(is_empty){
		state = 'e';
		display_code = 'p';
		cout<<"Port"<<get_id()<<" has been depleted of supplies"<<endl;
		return true;
	}
	else
		return false;
}

void Port::show_status(){
	cout<<"Port Status: "<<display_code<<" with ID "<<get_id()<<" at location "<<location
	<<" containing supplies "<<inventory<<endl;
}
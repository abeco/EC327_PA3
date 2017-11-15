#include <iostream>
using namespace std;
#include <math.h>

#include "Sailor.h"
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "CartPoint.h"
#include "CartVector.h"

Sailor::Sailor() : GameObject('S' , 0 , CartPoint(0, 0)){
	state = 'h';
	health = 25;
	size = 15;
	hold = 100;
	cargo = 0;
	destination = CartPoint(0.0,0.0);
//what do I do for this one --see other delta initialization
	delta = CartVector(0,0);
	port = NULL;
	dock = NULL;
	hideout = NULL;
	cout<<"Sailor default constructed"<<endl;
}
//use the GameObject constructor to get it in an initial location
//or maybe you could just use the default and set the location 
//later using the location of the hideout dock
Sailor::Sailor(int in_id , Dock* hideout) : GameObject('S' , in_id , hideout->get_location()){
	state = 'h';
	health = 25;
	size = 15;
	hold = 100;
	cargo = 0;
	//this looks right, but I'm not so sure
	destination = location;
//no clue what to do for this one
//pretty sure it doesn't matter though, setup_dest takes care of it
	delta = CartVector(0,0);
	port = NULL;	
	dock = NULL;
//I'm using this-> correctly right?
	this->hideout = hideout;
	cout<<"Sailor constructed"<<endl;
}

Sailor::~Sailor(){
	cout<<"Sailor destructed"<<endl;
}

//update_location
//only returns true when it arrives at the destination
//see ** for correct methodology, needs math.h
//or just be really sure this works for all cases
bool Sailor::update_location(){
	if(fabs(location.y - destination.y) > fabs(delta.y) && 
		fabs(location.x - destination.x) > fabs(delta.x)){
		location = location + delta;
		cout<<this->display_code<<this->get_id()<<": Just keep sailing..."<<endl;
		//cout<<"location: "<<location<<endl; 
		return false;
	}
	else{
		location = destination;
		cout<<this->display_code<<this->get_id()<<": I'm there!"<<endl;
		//cout<<"location: "<<location<<endl;
		//state = 'a';
		return true;
	}
}

//setup_destination sets the destination for this journey, and
//also calculates a unique delta value to be used on this journey
void Sailor::setup_destination(CartPoint dest){
	destination = dest;
	//double speed = get_speed();
	delta = (destination - location) * (this->get_speed() / cart_distance(destination, location));
}

//Do later, when you understand more things
//set original_state, run switch, set new_state
//return(new_state != original_state)
bool Sailor::update(){
	char original_state = state;
	switch (state){
		case 'a':
			//does nothing...ok so I guess I'm not putting anything here
			break;
		case 's':
			//not sure if this call is legal... but I'm about to find out
			//problem is probably here somewhere
			//update_location();
			if(update_location())
				state = 'a';
			break;
		case 'o':
			//update_location();
			//cout<<"case o got here"<<endl;
			//cout<<this->display_code<<this->get_id()<<": Supplies here I come!"<<endl;
			if(update_location()){
				cout<<this->display_code<<this->get_id()<<": Starting to supply at a port"<<endl;
				state = 'l';
			}
			break;
		case 'i':
			//update_location();
			if(update_location()){
				cout<<display_code<<get_id()<<": Starting to unload at a dock"<<endl;
				state = 'u';
			}
			break;
		case 'l':
			if(cargo == hold){
				state = 'a';
				cout<<display_code<<" "<<get_id()<<": My boat is filled	up. Send me to a Dock to unload. Dropping anchor."<<endl;
			}
			else{
				//cout<<"Case l got here"<<endl;
				//cargo += port->provide_supplies();

				if(port->update()){
					state = 'a';
					cout<<display_code<<" "<<get_id()<<": This Port has no more	supplies for me. Dropping anchor."<<endl;
				}
				else if (cargo >= hold - 50){
					int temp = (hold - cargo);
					cargo += port->provide_supplies(temp);
					cout<<display_code<<" "<<get_id()<<": My new cargo is "<<
					cargo<<endl;
				}
				else{
					cargo += port->provide_supplies();
					cout<<display_code<<" "<<get_id()<<": My new cargo is "<<
					cargo<<endl;
				}
			}
				/*	if(hold < cargo){
						double temp = cargo - hold;
						cargo = cargo - temp;
					}
					else if(port->is_empty()){
						state = 'a';
						cout<<display_code<<" "<<get_id()<<": This Port has no more	supplies for me. Dropping anchor."<<endl;
						break;
					}
					else{
						cargo += port->provide_supplies();
					}
					}

				if (port->is_empty() && cargo == hold){
					state = 'a';
					cout<<display_code<<get_id()<<": This Port has no more supplies for me. Dropping anchor."<<endl;
				}
				state = 'a';
				cout<<display_code<<get_id()<<": My new cargo is "<<cargo<<endl;

				break;*/
			break;
		//call dock::update somewhere in here I think	
		//figure out the dock size thing
		//also fix the case, not t if hes docked but not unloading cargo
		case 'u':
			//dock->dock_boat(this);
			if(dock->dock_boat(this))// cargo > 0){
				{
					if(cargo > 0){
				//double original_size = this->size;
						state = 'd';
						cout<<display_code<<" "<<get_id()<<": I am unloading at the dock"<<endl;
						cargo = 0;
				//does this make sense?
				//dock->set_sail(this);
						hold += 20;
						size += 5;
						cargo = 0;
			}
			else{
				state = 'd';
				cout<<display_code<<get_id()<<": I am unloading at the dock"<<endl;
			}
			}
			else{
				state = 't';
				cout<<display_code<<" "<<get_id()<<": Help! My dock is full"<<endl;
			}
			break;
		case 'd':
			//j chillin
			break;
		case 'h':
			if(get_location().x == hideout->get_location().x
			&& get_location().y == hideout->get_location().y){
				state = 'a';
				cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
				" at location "<<hideout->get_location()<<": Is going to hide at Dock "<<hideout->get_id()<<endl;
			}
			else
				start_hiding();
				update_location();
			break;
		case 't':
			//buggin out...not a good situation
			cout<<display_code<<" "<<get_id()<<" is in trouble"<<endl;
			break;
	}
	char new_state = state;
	return(new_state != original_state);
}

double Sailor::get_size(){
	return size;
}
double Sailor::get_cargo(){
	return cargo;
}
//write function
void Sailor::start_sailing(CartPoint dest){
	if(state == 'd'){
	//how do I implement this line??
	//this is where the member Dock comes in
		//this is going to give a segfault until I write other functions
	//cout<<"GOT here"<<endl;
	dock->set_sail(this);	
	}
	setup_destination(dest);
	state = 's';

	//call update somewhere in here
	cout<<"Sailing "<<get_id()<<" to "<<destination<<endl;
	//do I put this functionality here? Or somewhere else?
	//if(location.x == dest.x && location.y == dest.y)
		cout<<display_code<<" "<<get_id()<<": On my way"<<endl;
	//else
	//	cout<<display_code<<" "<<get_id()<<": I'm there!"<<endl;

}
//tells Sailor to start supplying?
//should this call start_sailing?
//I'm so confused about where to put all the functionality code
void Sailor::start_supplying(Port* destPort){
	if(state == 'd'){
		//perfectly reasonable to sail from a dock to a port, right?
		//how to implement this line?? -- see other time
		dock->set_sail(this);
	}
	port = destPort;
	setup_destination(port->get_location());
	state = 'o';
	cout<<"Sailor "<<get_id()<<" supplying at Port "<<destPort->get_id()
	<<" and going to Port "<<destPort->get_id()<<endl;
	cout<<this->display_code<<this->get_id()<<": Supplies here I come!"<<endl;
	//use Port::provide_supplies with hold size
	/*if(destPort->get_location().x == location.x 
		&& destPort->get_location().y == location.y 
		){
		state = 'l';
		double amount = Port::provide_supplies(hold);
		cargo += amount;
	}*/
}

void Sailor::start_hiding(){
	setup_destination(hideout->get_location());
	state = 'h';
	cout<<"Sailor "<<get_id()<<" hiding "<<get_id()<<endl;
	cout<<display_code<<" "<<get_id()<<": Off to hide"<<endl;
}
//i think this syntax works
bool Sailor::is_hidden(){
	return (location.x == hideout->get_location().x 
		&& location.y == hideout->get_location().y);
}

void Sailor::start_docking(Dock* destDock){
	dock = destDock;
	//cout<<"dock: "<<destDock<<endl;
	setup_destination(destDock->get_location());
	state = 'i';
	cout<<"Sailor "<<get_id()<<" sailing to Dock "<<dock->get_id()<<endl;
	cout<<display_code<<get_id()<<": Off to Dock"<<endl;
}

void Sailor::anchor(){
	state = 'a';
	cout<<"Stopping "<<get_id()<<"."<<endl;
	cout<<display_code<<" "<<get_id()<<": Dropping anchor"<<endl;
}
void Sailor::show_status(){
	cout<<"Show status state: "<<state<<endl;
	switch(state){
		//cout<<this->display_code<<this->get_id()<<": ";
		//separate case a && location == hideout
		case 'a':
		//add the hiding thing, maybe a separate case
			if(this->get_location().x == hideout->get_location().x
			&& this->get_location().y == hideout->get_location().y){
				cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<" is anchored(and hiding). Has a size of: "<<size<<", cargo of: "<<
				cargo<<", hold of: "<<hold<<", and health of: "<<health<<endl;
				break;
			}
			else{
				cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<" is anchored. Has a size of: "<<size<<", cargo of: "<<
				cargo<<", hold of: "<<hold<<", and health of: "<<health<<endl;
				break;
			}
		case 's':
			cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<" has speed of: "<<get_speed()<<" and is heading to "<<
			destination<<endl;
			break;
		case 'o':
			//cout<<"case o got here"<<endl;
			cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<" is outbound to Port: "<<port->get_id()<<" With a speed of"<<
			get_speed()<<endl;
			break;
		case 'i':
			cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<" is inbound to Dock: "<<dock->get_id()<<" With a speed of "<<
			get_speed()<<endl;
			break;
		case 'l'://fix, if else
			cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<"  is supplying at Port "<<port->get_id()<<endl;
			break;
		case 'u'://fix, call dockboat
			cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<" is unloading at Dock "<<dock->get_id()<<endl;
			break;
		case 'd':
			cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<" is docked at Dock "<<dock->get_id()<<endl;
			break;
		case 'h':
			cout<<"Sailor status: "<<display_code<<" with ID "<<get_id()<<
			" at location"<<get_location()<<" is going to hide at Dock "<<hideout->get_id()<<endl;
			break;
		case 't':
			cout<<"Is in trouble "<<get_id()<<endl;
			break;
	}
}

double Sailor::get_speed(){
	return (size - (cargo*.1));
}
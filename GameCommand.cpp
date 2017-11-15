#include <iostream>
using namespace std;

#include "GameCommand.h"
/*#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"
*/
#include "Model.h"



void do_sail_command(Model* model){
	int input_id;
	cin>>input_id;
	double input_x;
	double input_y;
	cin>>input_x;
	cin>>input_y;
	(model->get_sailor_ptr(input_id))->start_sailing(CartPoint(input_x , input_y));
}

void do_port_command(Model* model){
	int input_id1;
	int input_id2;
	cin>>input_id1;
	cin>>input_id2;
	(model->get_sailor_ptr(input_id1))->start_supplying(model->get_port_ptr(input_id2));
}

void do_anchor_command(Model* model){
	int input_id;
	cin>>input_id;
	(model->get_sailor_ptr(input_id))->anchor();
}

void do_dock_command(Model* model){
	//cout<<"do dock command got here"<<endl;
	int input_id1;
	int input_id2;
	cin>>input_id1;
	cin>>input_id2;
	//cout<<"do dock command got here 2"<<endl;
	(model->get_sailor_ptr(input_id1))->start_docking((model->get_dock_ptr(input_id2)));
}

void do_hide_command(Model* model){
	int input_id;
	cin>>input_id;
	(model->get_sailor_ptr(input_id))->start_hiding();
}

void do_go_command(Model* model){
	cout<<"Advancing one time tick"<<endl;
	model->update();

	model->show_status();
	//whats the story with time? do I increment that myself? I think so
	//just by virtue of the fact that in this program its an int
	//time++;
}

void do_run_command(Model* model){
	cout<<"Advancing to next event or 5 ticks"<<endl;
	int count = 0;
	while(!(model->update()) && count < 5){
	//while(!(model->update()))
		//model->update();
		//cout<<"update: "<<model->update();
		//model->show_status()
		count++;
		//cout<<"\tcount: "<<count<<endl;
		//time++;
	}
	model->show_status();
}

//should this be in a main of some sort?
//cout<<"Enter command: ";
//char input_char;
//cin>>input_char;

//now should this be in a function somewhere?
//this needs to be in the final main function
/*
switch (input_char) {
	case 's':
		do_sail_command(Model* model);
		break;
	case 'p':
		do_port_command(Model* model);
		break;
	case 'a':
		do_anchor_command(Model* model);
		break;
	case 'd':
		do_dock_command(Model* model);
		break;
	case 'h':
		do_hide_command(Model* model);
		break;
	case 'g':
		do_go_command(Model* model);
		break;
	case 'r':
		do_run_command(Model* model);
		break;
	case 'q':
		//figure out what to put here
		//i think this is where I call the destructors I haven't made yet
		cout<<"Quit the game"<<endl;
		break;

}
*/
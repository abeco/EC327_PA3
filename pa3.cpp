#include <iostream>
using namespace std;

#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"

int main(){
	cout<<"EC327: Introduction to Software Engineering"<<endl;
	cout<<"Fall 2015"<<endl<<"Programming Assignment 3"<<endl;

	Model* model = new Model();
    model->show_status();

    View view;

    //view.clear();

    //model->display(view);

    //view.draw();
    //delete model;


	bool loop_var = true;
	while(loop_var){

	//view.clear();
	model->display(view);
	//view.draw();

	cout<<"Enter command: ";
	char input_char;
	cin>>input_char;

	switch (input_char) {
	case 's':
		do_sail_command(model);
		break;
	case 'p':
		do_port_command(model);
		break;
	case 'a':
		do_anchor_command(model);
		break;
	case 'd':
		do_dock_command(model);
		break;
	case 'h':
		do_hide_command(model);
		break;
	case 'g':
		do_go_command(model);
		break;
	case 'r':
		do_run_command(model);
		break;
	case 'q':
		//figure out what to put here
		//i think this is where I call the destructors I haven't made yet
		delete model;
		loop_var = false;
		cout<<"Quit the game"<<endl;
		break;

}
}

return 0;
}
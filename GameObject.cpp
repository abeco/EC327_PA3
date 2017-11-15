#include <iostream>
#include "GameObject.h"

#include "CartPoint.h"
#include "CartVector.h"
using namespace std;

GameObject::GameObject(char in_code, int in_id){
	display_code = in_code;
	id_num = in_id;
	location = CartPoint(0,0);
	cout<<"GameObject default constructed"<<endl;
}

GameObject::~GameObject(){
	cout<<"GameObject destructed"<<endl;
}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc){
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	cout<<"GameObject constructed"<<endl;
}
CartPoint GameObject::get_location(){
	return location;
}
int GameObject::get_id(){
	return id_num;
}
void GameObject::show_status(){
	cout<<display_code<<" with ID "<<id_num<<" at location "<<location<<endl;
}

bool GameObject::update(){}

//there's no way this is right
void GameObject::drawself(char* grid){
	*grid = display_code;
	*(grid + 1) = id_num + 48;
}
#include <iostream>
#include <iomanip>
using namespace std;

#include "View.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "Model.h"

View::View(){
	size = 11;
	scale = 2;
	origin = CartPoint(0,0);

}

View::~View(){
	cout<<"view destructed"<<endl;
}

bool View::get_subscripts(int &ix, int &iy, CartPoint location){
	ix = ((location.x - origin.x)/scale);
	iy = ((location.y - origin.y)/scale);
	if(ix <= view_maxsize && iy <= view_maxsize && ix >= 0 && iy >= 0){
		return true;
	}
	else{
		cout<<"An object is outside the display"<<endl;
		return false;
	}
}

//what?
void View::clear(){
	//creates empty grid
	//how to unflip? do it in draw
	for(int i = 0; i < view_maxsize; i++){
	//for(int i = view_maxsize - 1; i >= 0; i--){
		for(int j = 0; j < view_maxsize; j++){
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

//in model display loop through the objects and plot them
void View::plot(GameObject* ptr){
	int x;
	int y;
	if(get_subscripts(x , y , ptr->get_location())){
		//if nothing is plotted in that cell
		//if cell == '.' , ' '
		//call drawself
		if(*(grid[x][y]) == '.'){
			ptr->drawself(grid[x][y]);
		}
		else{
			grid[x][y][0] = '*';
			grid[x][y][1] = ' ';
		}
	}
}

void View::draw(){
	for(int i = (view_maxsize/2); i >= 0; i--){
	//for(int i = 0; i < view_maxsize; i++){
		if((i*2)%4 == 0 && (i*2) > 10){
			cout<<i*2;
		}
		else if((i*2)%4 == 0)
			cout<<i*2<<" ";
		else
			cout<<"  ";
		for(int j = 0; j < (view_maxsize/2)+1; j++){
			cout<<grid[j][i][0]<<grid[j][i][1];
		}

		cout<<endl;
	}
	cout<<"  0   4   8   12  16  20"<<endl;
}
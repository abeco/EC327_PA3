#ifndef VIEW_H
#define VIEW_H

#include "CartPoint.h"
#include "GameObject.h"
#include "Model.h"

class Model;

const int view_maxsize = 20;

class View{
	private:
		int size;
		double scale;
		CartPoint origin;
		char grid[view_maxsize][view_maxsize][2];
		bool get_subscripts(int &ix, int &iy, CartPoint location);
	public:
		View();
		~View();
		void clear();
		void plot(GameObject* ptr);
		void draw();
};

#endif
#ifndef CARTPOINT_H
#define CARTPOINT_H

using namespace std;

#include <fstream>
#include "CartVector.h"

class CartPoint{
	public:
		double x;
		double y;
		CartPoint();
		CartPoint(double in_x, double in_y);
		//friend ostream& operator<<(ostream& os, const CartPoint& p1); 
};
double cart_distance(CartPoint p1, CartPoint p2);
bool cart_compare(CartPoint p1, CartPoint p2);

CartPoint operator+(CartPoint p1, CartVector v1);
CartVector operator-(CartPoint p1, CartPoint p2);

ostream& operator<<(ostream& os, const CartPoint& p1);
#endif
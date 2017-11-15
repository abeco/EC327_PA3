#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#include "CartPoint.h"
#include "CartVector.h"

//CartPoint::CartPoint{
//	public:
//		double x;
//		double y;
		CartPoint::CartPoint(){
			x = 0.0;
			y = 0.0;
		}
		CartPoint::CartPoint(double in_x, double in_y){
			x = in_x;
			y = in_y;
		}
//};

double cart_distance(CartPoint p1, CartPoint p2){
	double x = (p1.x - p2.x)*(p1.x - p2.x);
	double y = (p1.y - p2.y)*(p1.y - p2.y);
	return sqrt(x + y);
}
bool cart_compare(CartPoint p1, CartPoint p2){
	if( p1.x == p2.x && p1.y == p2.y)
		return true;
	else
		return false;
}
CartPoint operator+(CartPoint p1, CartVector v1){
	return CartPoint((p1.x + v1.x), (p1.y + v1.y));
}
CartVector operator-(CartPoint p1, CartPoint p2){
	return CartVector((p1.x - p2.x), (p1.y - p2.y));
}
ostream& operator<<(ostream& os, const CartPoint& p1){
	os << "(" << p1.x << ", " << p1.y << ")";
	return os;
}

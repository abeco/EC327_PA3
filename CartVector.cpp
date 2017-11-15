#include <iostream>
using namespace std;

#include <fstream>

#include "CartVector.h"
//#include <math.h>

CartVector::CartVector(){
	x = 0.0;
	y = 0.0;
}
CartVector::CartVector(double in_x, double in_y){
	x = in_x;
	y = in_y;
}

CartVector operator*(CartVector v1, double d){
	return CartVector((v1.x * d), (v1.y * d));
}

CartVector operator/(CartVector v1, double d){
	if (d == 0)
		return v1;
	else
		return CartVector((v1.x / d), (v1.y / d));
}


ostream& operator<<(ostream& os, const CartVector& v1){
	os << "<" << v1.x << ", " << v1.y << ">";
	return os;
}
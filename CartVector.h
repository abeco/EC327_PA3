#ifndef CARTVECTOR_H
#define CARTVECTOR_H

using namespace std;

#include <fstream>

class CartVector{
	public:
		double x;
		double y;
		CartVector();
		CartVector(double in_x, double in_y);
		friend ostream& operator<<(ostream& os, const CartVector& v1);
};
CartVector operator*(CartVector v1, double d);
CartVector operator/(CartVector v1, double d);

#endif
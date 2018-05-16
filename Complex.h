#ifndef COMPLEX_H
#define COMPLEX_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

class Complex{
	public : 
		Complex(double new_x, double new_y);
		double x,y,xx,yy ,module;
		void add(Complex a);
		void mult(Complex a);
        double get_module();
		
};

#endif	

#include "Complex.h"
#include <math.h>

Complex::Complex(double new_x, double new_y){
	x=new_x;
	y=new_y;
    xx=x;
    yy=y;
}

void Complex::add(Complex a){
	x+=a.x;
	y+=a.y;
    xx=x;
    yy=y;
}
void Complex::mult(Complex a){
	x=xx*a.x-yy*a.y;
	y=xx*a.y + yy*a.x;
    xx=x;
    yy=y;
}
double Complex::get_module(){
    module=sqrt(x*x+y*y);
    return module;
}
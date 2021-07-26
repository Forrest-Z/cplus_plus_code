#include "sample.h"
#include <iostream>
#include <cmath>

int sample_add(int x, int y) {
 std::cout<<"sample_add("<<x<<", "<< y<<")="<<x+y<<std::endl;
 return x + y; 
}

double sample_sin(double x) { return std::sin(x); }

#include <iostream>
#include <iomanip>
#include <cmath>
#include "1.5.back.cpp"

double under_int_func(double x, double t, double s);

double left_rectangles(double(*func)(double, double, double), int N,
    double a, double b, double t, double s);

void double_calc(int N, int a, int b, double E,
    double s1, double s2, double ds, 
    double t1, double t2, double dt);
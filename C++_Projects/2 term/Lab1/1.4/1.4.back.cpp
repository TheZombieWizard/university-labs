#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double a_func(double x, double s)
{
    return ((x - 1) * (x - 1) - 3);
}

double b_func(double x, double s)
{
    return (exp(x - s) - sqrt(x + 1));
}

void half_division(
    double(*func)(double, double), 
    double a = 0, double b = 10, 
    double s_min = 0, double s_max = 0, double ds = 0.1, 
    double E = 1e-6
    )
{
    cout << setw(15) << "S" << setw(15) << "X" << setw(15) << "F(x)" << setw(15) << "k_iter" << endl;
    
    for (double s = s_min; s <= s_max; s += ds)
    {
        double left = a,
            right = b,
            middle = (left + right) / 2,
            func_middle = func(middle, s),
            func_left = func(left, s),
            func_right = func(right, s);
            
        int k_iter = 1;
        
        while ((abs(left - right) > E) && (abs(func_middle) > E))
        {
            k_iter++;
            if (func_left * func_middle < 0)
                right = middle;
            else
                left = middle;

            middle = (left + right) / 2,
            func_middle = func(middle, s),
            func_left = func(left, s),
            func_right = func(right, s);
        }
        
        cout << setw(15) << s << setw(15) << middle << setw(15) << func_middle << setw(15) << k_iter << endl;
    }
}

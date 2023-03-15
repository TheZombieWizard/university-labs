using namespace std;
double under_int_func(double x, double t, double s)
{
    return pow(1 + x * x, 1/t) / exp(sin(x) + s);
}

double left_rectangles(double(*func)(double, double, double), int N,
    double a, double b, double t, double s)
{
    double integral = 0,
        h = (b - a) / N;
    
    for (double x = a; x < b; x += h)
    {
        integral += func(x, t, s);
    }
    integral *= h;


    return integral;
}

void double_calc(int N = 1, int a = -1, int b = 1, double E = 1e-6,
    double s1 = 0, double s2 = 2, double ds = 0.5, 
    double t1 = 2, double t2 = 5, double dt = 1)
{

    cout << setw(15) << "S" << setw(15) << "t" << setw(15) << "Int" << setw(15) << "k_iter" << endl;
    
    for (double s = s1; s <= s2; s += ds)
    {
        for (double t = t1; t <= t2; t += dt)
        {
	        double integral1 = 0, 
                integral2 = 0;
	        int k_iter = 1;
            int N = 1;

            integral1 = left_rectangles(under_int_func, N, a, b, t, s);
            do
	        {
	        	integral2 = integral1;  
	        	N *= 2;
                integral1 = left_rectangles(under_int_func, N, a, b, t, s);
                k_iter++;
	        }
	        while (abs(integral1 - integral2) > E);

            cout << setw(15) << s << setw(15) << t << setw(15) << integral1 << setw(15) << k_iter << endl;
        }
    }
}

#include "RationalFraction.h"

int main()
{
    RationalFraction ratfrac1(1, 2);
    RationalFraction ratfrac2(1, 3);
    cout << ratfrac1 << endl;
    cout << ratfrac2 << endl;
    ratfrac2 += ratfrac1;
    cout << ratfrac2 << endl;
    ratfrac2 -= ratfrac1;
    cout << ratfrac2 << endl;
    ratfrac2 *= ratfrac1;
    cout << ratfrac2 << endl;
    ratfrac2 /= ratfrac1;
    cout << ratfrac2 << endl;
    ratfrac2.reduce2nonreducable();    
    cout << ratfrac2 << endl;
    cout << (ratfrac2 == ratfrac1) << endl;
    cout << (ratfrac2 >= ratfrac1) << endl;
    cout << (ratfrac2 <= ratfrac1) << endl;
    cout << (ratfrac2 > ratfrac1) << endl;
    cout << (ratfrac2 < ratfrac1) << endl;

    return 0;
}
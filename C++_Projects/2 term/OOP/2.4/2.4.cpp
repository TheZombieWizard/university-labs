#include "RationalFraction.h"

int main()
{
    RationalFraction ratfrac1(1, 2);
    RationalFraction ratfrac2(1, 3);
    cout << ratfrac1 << endl;
    cout << "Cin input check (input numerator & denominator): " << endl;
    cin >> ratfrac1;
    cout << endl;
    
    cout << "Cout output check: " << endl;
    cout << ratfrac1 << endl;
    cout << ratfrac2 << endl;
    
    cout << endl << "Operations check: " << endl;
    ratfrac2 += ratfrac1;
    ratfrac2.reduce2nonreducable();
    cout << ratfrac2 << endl;
    
    ratfrac2 -= ratfrac1;
    ratfrac2.reduce2nonreducable();
    cout << ratfrac2 << endl;
    
    ratfrac2 *= ratfrac1;
    ratfrac2.reduce2nonreducable();
    cout << ratfrac2 << endl;
    
    ratfrac2 /= ratfrac1;
    ratfrac2.reduce2nonreducable();
    cout << ratfrac2 << endl;
    cout << endl << "Partial output check:" << endl;
    ratfrac2.print('n');
    ratfrac2.print('d');
    cout << endl;

    cout << endl << "Comparison check: " << endl;
    cout << (ratfrac2 == ratfrac1) << endl;
    cout << (ratfrac2 >= ratfrac1) << endl;
    cout << (ratfrac2 <= ratfrac1) << endl;
    cout << (ratfrac2 > ratfrac1) << endl;
    cout << (ratfrac2 < ratfrac1) << endl;

    return 0;
}
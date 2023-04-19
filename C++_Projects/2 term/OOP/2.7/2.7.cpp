#include "Matrix.h"


int main()
{
    srand(time(NULL));
    Matrix A(3, 3);
    A.fill_random();
    A.print();
    cout << endl;

    Matrix B(3, 1);
    B.fill_random();
    B.print();
    cout << endl;

    Matrix C = (A * A) * B;
    C.print();

    return 0;
}
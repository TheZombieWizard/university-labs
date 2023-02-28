#include "1.3_back.h"

int main()
{
    srand(time(NULL));
    const int N = 10;
    int array[N] = {0};
    int k = 42;

    random_creation(array, N);
    array[0] = 0;
    array[1] = 0;
    array_output(array, N);
    cout << endl;
    find_2max(array, N) = k;
    array_output(array, N);
    cout << endl;

    return 0;
}
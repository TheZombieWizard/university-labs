#include "1.6.back.h"

int main()
{
    srand(time(NULL));
    const int size = 42;
	// int array[size] = {0};
    char array[size] = {'\0'};

    random_creation(array, size);
    array_output(array, size);
    mergeSort(array, 0, size - 1, size);
    array_output(array, size);

    return 0;
}
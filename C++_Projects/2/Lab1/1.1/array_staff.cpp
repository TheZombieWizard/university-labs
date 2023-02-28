#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void increasing_creation(int *arr_pointer, int size)
{
    for (int i = 0; i < size; i++, arr_pointer++)
        *arr_pointer = i;
}

void random_creation(int* arr_pointer, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++, arr_pointer++)
        *arr_pointer = rand() % 50;
}

void arr_output(int* arr_pointer, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int q = 0; q < N; q++, arr_pointer++)
            cout << setw(4) << *arr_pointer << " ";
        cout << endl;
    }
}

void snake_creation(int* inp_arr_pointer, int* out_arr_pointer, int N)
{
    int horizontal_step = 1;
    int vertical_step = N;

    for (int i = 0; i < N - 1; i++, inp_arr_pointer++, out_arr_pointer += vertical_step)
        *out_arr_pointer = *inp_arr_pointer;

    for (int border = 1; border < N; border++)
    {

        for (int i = 0; i < N - border; i++, inp_arr_pointer++, out_arr_pointer += horizontal_step)
            *out_arr_pointer = *inp_arr_pointer;

        for (int i = 0; i < N - border; i++, inp_arr_pointer++, out_arr_pointer -= vertical_step)
            *out_arr_pointer = *inp_arr_pointer;

        horizontal_step = -horizontal_step;
        vertical_step = -vertical_step;
    }
    
    *out_arr_pointer = *inp_arr_pointer;
}

#include <iostream>

using namespace std;


int main() 
{
    short n, m;
    cin >> n >> m;
    int* array = new int[m];

    for (int i = 0; i < m; ++i)
        cin >> array[i];
    
    for (int i = 1; i < n; ++i)
    {
        int arr_index = 0;
        int input_arr_index = 0;
        int* new_array = new int[m*(i+1)];
        int* input_array = new int[m];
        
        for (int q = 0; q < m; ++q)
            cin >> input_array[q];
        
        for (int q = 0; q < m*(i+1); ++q)
        {
            if (arr_index >= m*i)
                new_array[q] = input_array[input_arr_index++];
            else if (input_arr_index >= m)
                new_array[q] = array[arr_index++];
            else if (input_array[input_arr_index] <= array[arr_index])
                new_array[q] = input_array[input_arr_index++];
            else
                new_array[q] = array[arr_index++];
        }

        delete[] array;
        delete[] input_array;
        array = new_array;
    }

    for (int i = 0; i < n*m; ++i)
        cout << array[i] << " ";
    
    return 0;
}
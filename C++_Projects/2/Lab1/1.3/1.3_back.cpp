#include <iostream>
#include <cstdlib>

using namespace std;

void array_output(int array[], int N)
{
    for (int i = 0; i < N; i++)
        cout << array[i] << " ";
    cout << endl;
}

void random_creation(int array[], int N)
{
    for (int i = 0; i < N; i++)
        array[i] = rand() % 30 + 1;
}

void choose_sort(int array[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int q = i + 1; q < N; q++)
            if (array[q] < array[min])
                min = q;
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

int& find_2max(int arr[], int N)
{
    // Копируем массив, чтобы отсортировать
    int array[N] = {0};
    for (int i = 0; i < N; i++)
        array[i] = arr[i];
    
    choose_sort(array, N);
    
    // В отсортированном массиве находим нужные числа
    int temp = array[N - 1];
    int count = 1;
    int max_valid_num = array[N-1];

    for (int i = N - 2; i >= -1; i--)
        if ((i == -1) || (array[i] != temp))
        {
            if (count == 2)
            {
                max_valid_num = temp;
            }
            else
            {
                count = 1;
                temp = array[i * (i != -1)];
            }
        }
        else
            count++;
    
    // В изначальном массиве находим первое подходящее число и возвращаем его ссылку
    for (int i = 0; i < N; i++)
        if (arr[i] == max_valid_num)
            return arr[i];
}
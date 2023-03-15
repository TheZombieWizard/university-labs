#include <iostream>
#include <cstdlib>

using namespace std;

template <class type>
void array_output(type array[], int size)
{
    for (int n = 0; n < size; n++)
        cout << array[n] << " ";
    cout << endl;
}

void increasing_creation(char array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++)
    {
        if ((65 + i) == 91) i += 6;
        array[i] = char(65 + i);
    }
}

void decreasing_creation(char array[], int n)
{
    srand(time(NULL));
    for (int i = 0, q = 122; i < n ; i++, q--)
    {
        if (q == 96) q -= 6;
        array[i] = char(q);
    }
}

void random_creation(char array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++)
    {
        bool upper_case = rand() % 2;
        if (upper_case) 
            array[i] = char((rand() % 26) + 65);
        else
            array[i] = char((rand() % 26) + 97);
    }
}

template <class type>
void increasing_creation(type array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++)
        array[i] = type(i) + type(rand() % 10) / 100;
}

template <class type>
void decreasing_creation(type array[], int n)
{
    srand(time(NULL));
    for (int i = n - 1, q = 0; i >= 0 ; i--, q++)
        array[i] = type(q) + type(rand() % 10) / 100;
}

template <class type>
void random_creation(type array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++)
        array[i] = type(rand() % 100) + type(rand() % 10) / 100;
}

template <class type>
void merge(type list[], int start, int end, int mid, int size)
{
	type mergedList[size];
	int i, j, k;
	i = start;
	k = start;
	j = mid + 1;
	
	while (i <= mid && j <= end) 
    {
		if (list[i] < list[j]) 
        {
			mergedList[k] = list[i];
			k++;
			i++;
		}
		else 
        {
			mergedList[k] = list[j];
			k++;
			j++;
		}
	}
	
	while (i <= mid) 
    {
		mergedList[k] = list[i];
		k++;
		i++;
	}
	
	while (j <= end) 
    {
		mergedList[k] = list[j];
		k++;
		j++;
	}
	
	for (i = start; i < k; i++) 
		list[i] = mergedList[i];
}

template <class type>
void mergeSort(type list[], int start, int end, int size)
{
	int mid;
	if (start < end)
    {  
		mid = (start + end) / 2;
		mergeSort(list, start, mid, size);
		mergeSort(list, mid+1, end, size);
		merge(list, start, end, mid, size);
	}
}
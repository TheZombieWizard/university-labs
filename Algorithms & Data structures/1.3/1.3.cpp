#include <iostream>

using namespace std;

void merge(){;}

int main() 
{
    short n, m;
    cin >> n >> m;
    int* pointers_array[n];
    int array[n][m];
    int answer[n*m];
    
    for (int i = 0; i < n; i++)
        pointers_array[i] = &array[i][0];
    
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
            cin >> array[i][q];
    }
    
    for (int i = 0; i < n*m; i++)
    {
        int min = 0;
        for (int q = 0; q < n; q++)
            if (*pointers_array[q] < *pointers_array[min])
                min = q;
        answer[i] = *pointers_array[min];
        pointers_array[min]++;
        if (pointers_array[min] - pointers_array[])
    }

    for (int i = 0; i < n*m; i++)
        cout << answer[i] << " ";

    return 0;
}
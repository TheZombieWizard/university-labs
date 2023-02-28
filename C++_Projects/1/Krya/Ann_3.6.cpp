#include <iostream>
#include <iomanip> // Для setw() - определяет, сколько символов отведено под текущий вывод

using namespace std;

int main()
{
    const int n = 10;
    int A[n][n];

    enum input_modes { default_input, random_input, user_input};
    
    cout << "Input mode:" << endl
        << "(" << default_input << ") - default configuration" << endl
        << "(" << random_input << ") - random numbers" << endl
        << "(" << user_input << ") - by user" << endl;
    
    int choose_input_mode = 0;
    cin >> choose_input_mode;

    // Инициализация матрицы A[n][n] одним из трёх способов
    if (choose_input_mode == default_input) {
        for (int i = 0; i < n; i++)
            for (int q = 0; q < n; q++)
                A[i][q] = q + n * i;
    } else if (choose_input_mode == random_input) {
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            for (int q = 0; q < n; q++)
                A[i][q] = rand() % 20;
    } else if (choose_input_mode == user_input) {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter " << i + 1 << " line of " << n << " numbers:" << endl;
            for (int q = 0; q < n; q++)
                cin >> A[i][q];
        }
    } else { 
        cout << "Wrong input"; 
    }

    // Выводим матрицу A[n][n] для самопроверки
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < n; q++)
            cout << setw(4) << A[i][q] << " ";
        cout << endl;
    }
    cout << endl;
    // Чтение матрицы A[n][n] заданным способом
    for (int q = 0, j = 0; q < n; q++, j++)
    {
        // Чётные столбцы читаем сверху вниз
        if (j % 2 == 0) 
            for (int i = 0; i < n; i++)
                cout << setw(4) << A[i][q] << " ";
        // Нечётные столбцы читаем снизу вверх
        else
            for (int i = n - 1; i >= 0; i--)
                cout << setw(4) << A[i][q] << " ";
        cout << endl;
    }
    return 0;
}
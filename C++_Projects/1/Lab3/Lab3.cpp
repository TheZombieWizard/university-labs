#include <iomanip>
#include <cstdlib> // содержит srand() и rand()
#include <iostream>

using namespace std;

void B7_3_1() 
{
    const int n = 13;
    int A[n] = {0};

    enum input_modes { default_input, random_input, user_input};
    
    cout << "Input mode:" << endl
        << "(" << default_input << ") - default configuration" << endl
        << "(" << random_input << ") - random numbers" << endl
        << "(" << user_input << ") - by user" << endl;
    
    int choose_input_mode = 0;
    cin >> choose_input_mode;

    // Инициализация массива A[n] одним из трёх способов
    if (choose_input_mode == default_input) {
        int default_arr[n] = {3, 4, 5, 2, 1, 0, 6, 3, 5, 9, 8, 2, 4};
        for (int i = 0; i < n; i++)
           A[i] = default_arr[i];
    } else if (choose_input_mode == random_input) {
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            A[i] = rand() % 50;
    } else if (choose_input_mode == user_input) {
        cout << "Enter " << n << " numbers:" << endl;
        for (int i = 0; i < n; i++)
            cin >> A[i];
    } else { 
        cout << "Wrong input"; 
    }

    // Вывод значений массива A[n]
    for (int i = 0; i < n; i++)
        cout << setw(3) << A[i] << "  ";
    cout << endl;

    // Инициализация массива B[n]
    int B[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < i; q++)
            if (A[q] > A[i])
                B[i]++;
    }

    // Вывод значений массива A[n]
    for (int i = 0; i < n; i++)
        cout << setw(3) << B[i] << "  ";
}

/**/
void B7_3_2()
{
    const int n = 6;
    static int A[n][n];
    static int B[n][n];
    
    srand(time(NULL));
    for (int i = (n - 1); i >= 0; i--)
    {
        // cout << "Krya" << i << " ";
        for (int q = (n - 1); q >= 0; q--)
        {
            A[i][q] = rand() % 10;
            if ((i == (n - 1)) && (q == (n - 1)))
                B[i][q] = A[i][q];
            else if (i == (n - 1))
                B[i][q] = max(B[i][q + 1], A[i][q]);
            else if (q == (n - 1))
                B[i][q] = max(B[i + 1][q], A[i][q]);
            else
                B[i][q] = max( max(B[i + 1][q], B[i][q + 1]), A[i][q]);
        }
    }
    /**/
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < n; q++)
            cout << A[i][q] << "  ";  
        cout << endl;
    }

    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < n; q++)
            cout << B[i][q] << "  ";  
        cout << endl;
    }
    /**/
}
/**/

/**/
void B7_3_3()
{
    int found_numbers = 0;
    const int N = 10000;
    bool nums_array[N] = {0};

    for (int k = 1; k <= N; k++)
        nums_array[k] = 1;

    int n = 0;
    cout << "Amount of numbers: ";
    cin >> n;
    cout << "Sum of digits must be lesser then: ";
    int m = 0;
    cin >> m;

    // Применение алгоритма Эратосфена к массиву
    for (int i = 2; i + 1 < N ; i++)
    {
        // cout << "Krya" << i << " ";
        if (!nums_array[i])
                continue;
        for (int q = i + 1; q < N; q++)
        {
            if (!nums_array[q])
                continue;
            else if (q % i == 0)
                nums_array[q] = 0;
        }
    }

    // Вывод первых n простых чисел, сумма цифр которых меньше m
    for (int nums_amount = 0, i = 1; (nums_amount < n) && (i < N); i++)
    {
        if (!nums_array[i])
            continue;
        int sum_of_digits = 0;
        int nums_left_part = i; 
        while (nums_left_part > 0)
        {
            sum_of_digits += nums_left_part % 10;
            nums_left_part = nums_left_part / 10;
        }
        if (sum_of_digits < m)
        {
            nums_amount++;
            cout << i << "  ";
        }
    } 
}
/**/

int main()
{
    for (int i = 0; i <= 10; i++)
    {
        int n = 0;
        cout << endl << "Вариант 7B" << endl
            << "(1) - Задание 3.1 - Обработка одномерных массивов" << endl
            << "(2) - Задание 3.2 - Построение новой матрицы по части заданной матрицы" << endl
            << "(3) - Задание 3.3 - Алгоритм Эратосфена для нахождения простых чисел" << endl;
        cin >> n;
        cout << "//////////////////////////////////////////////////////" << endl;
        switch (n)
        {
        case 1:
            B7_3_1();
            break;
        case 2:
            B7_3_2();
            break;
        case 3:
            B7_3_3();
            break;
        default:
            cout << "Ah, crap, wrong input..." << endl;
        }
        cout << endl << "//////////////////////////////////////////////////////" << endl;
    }
    return 0;
}
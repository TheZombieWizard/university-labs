#include <iostream>
#include <iomanip> // Для setw() - определяет, сколько символов отведено под текущий вывод

using namespace std;

int main()
{
    const int n = 10;
    char A[n][n];
    int digits_amount = 0,
        min_digits_amount = n + 1,
        line_with_min_da = 0;
    // Инициализация матрицы A[n][n] случайными символами с кодом от 30 до 70
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int q = 0; q < n; q++)
            A[i][q] = char(rand() % 40 + 30);
    
    // Выводим матрицу A[n][n] для самопроверки
    for (int i = 0; i < n; i++)
    {
        digits_amount = 0;
        for (int q = 0; q < n; q++)
        {
            // Заодно проверяем, равен ли код символа коду какой-либо цифры и считаем кол-во таких символов
            // Код 0 = 48, код 9 = 57. Цифры от 0 до 9 находятся в этом промежутке
            if ((int(A[i][q]) >= 48) && (int(A[i][q]) <= 57))
                digits_amount++;
            cout << setw(5) << A[i][q];
        }

        // Проверяем, меньше ли кол-во цифр в этой строке, чем в найденной ранее
        if (digits_amount < min_digits_amount)
        {
            min_digits_amount = digits_amount;
            line_with_min_da = i;
        }
        cout << endl;
    }
    cout << endl;
    // Выводим номер строки (в человеческой системе исчисления от 1)
    cout << "Line with min amount of digits: " << line_with_min_da + 1 << endl;
    // Выводим саму строку
    for (int q = 0; q < n; q++)
        cout << A[line_with_min_da][q] << " ";
    return 0;
}
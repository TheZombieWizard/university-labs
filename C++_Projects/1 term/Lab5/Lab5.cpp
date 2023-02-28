#include <iostream>
#include "Solidus.h"
;

using namespace std;

double func_return(double x)
{
    double E = 1E-6,
        part = -1.0 * x * x / 2,
        sum = part;
    for (int k = 2; abs(part) > E; k++)
    {
        part = part * (-1.0 * x * x) / (2 * k);
        sum += part;
    }
    return sum;
}

void func_pointer(double x, double* psum)
{
    double E = 1E-6,
        part = (-1.0 * x * x) / (2 * 1);
    *psum = part;
    for (int k = 2; abs(part) > E; k++)
    {
        part = part * (-1.0 * x * x) / (2 * k);
        *psum += part;
    }
}

void func_reference(double x, double& rsum)
{
    double E = 1E-6,
        part = (-1.0 * x * x) / (2 * 1);
    rsum = part;
    for (int k = 2; abs(part) > E; k++)
    {
        part = part * (-1.0 * x * x) / (2 * k);
        rsum += part;
    }
}

void B7_5_1()
{
    double x = 0;
    cout << "Введите x (0 < x <= 1): ";
    cin >> x;

    cout.precision(20);
    cout << "С помощью return:" << endl 
        << func_return(x) << endl;

    double sum = 0;
    double* psum = &sum;
    func_pointer(x, psum);
    cout.precision(20);
    cout << "С помощью pointer:" << endl
        << sum << endl;

    sum = 0;
    double& rsum = sum;
    func_reference(x, rsum);
    cout.precision(20);
    cout << "С помощью reference:" << endl
        << sum << endl;
}

void B7_5_2()
{
    int const MAX = 1024;
    int array[MAX];
    // float array[MAX];
    // double array[MAX];
    // char array[MAX];


    // Выбираем способ заполнения массива
    enum creation_modes { increasing, decreasing, random};
    
    cout << "Creation mode:" << endl
        << "(" << increasing << ") - increasing creation" << endl
        << "(" << decreasing << ") - decreasing creation" << endl
        << "(" << random << ") - random creation" << endl;

    int choose_creation_mode = 0;
    cin >> choose_creation_mode;

    // Заполнение массива array[MAX] одним из трёх способов
    if (choose_creation_mode == increasing) increasing_creation(array, MAX);
    else if (choose_creation_mode == decreasing) decreasing_creation(array, MAX);
    else if (choose_creation_mode == random) random_creation(array, MAX);
    else cout << "Wrong input";

    // Выводим массив
    for (int i = 0; i < MAX; i++)
        cout << array[i] << " ";
    cout << endl;

    // Выбираем способ сортировки массива
    enum sort_modes { quick, select};
    
    cout << "Sort mode:" << endl
        << "(" << quick << ") - quick sort" << endl
        << "(" << select << ") - select sort" << endl;
    
    int choose_sort_mode = 0;
    cin >> choose_sort_mode;

    // Сортировка массива array[MAX] одним из двух способов
    if (choose_sort_mode == quick) quick_sort_comparison(array, 0, MAX);
    else if (choose_sort_mode == select) sort_select_comparison(array, MAX);
    else cout << "Wrong input";

    // Выводим массив
    for (int i = 0; i < MAX; i++)
        cout << array[i] << " ";
    cout << endl;
}

void B7_5_3()
{
    int const 
        N = 10,
        M = 10;
    int array[N][M] = {0};
    int* p_element = &array[0][0];
    int* start = &array[0][0];

    // Выбираем способ заполнения массива
    enum creation_modes { increasing, decreasing, random};
    
    cout << "Creation mode:" << endl
        << "(" << increasing << ") - increasing creation" << endl
        << "(" << decreasing << ") - decreasing creation" << endl
        << "(" << random << ") - random creation" << endl;

    int choose_creation_mode = 0;
    cin >> choose_creation_mode;

    // Заполнение массива array[MAX] одним из трёх способов
    if (choose_creation_mode == increasing) increasing_creation(p_element, N * M);
    else if (choose_creation_mode == decreasing) decreasing_creation(p_element, N * M);
    else if (choose_creation_mode == random) random_creation(p_element, N * M);
    else cout << "Wrong input";

    // Вывод массива array[N][M]
    array_output(p_element, N, M);

    // Массив count для подсчёта суммы элементов в строках массива array[N][M]
    int count[N][2] = {0};
    count_lines_sums(p_element, N, M, count);
    /** 
    int* p_count = &count[0][0]; 
    array_output(p_count, N, 2); 
    /**/ 
    cout << endl;

    sort_select(p_element, N, M, count);
    
    
    array_output(p_element, N, M);
}

void str_part_delete(char in_text[], int text_length, int start_position, int amount)
{
    for (int q = start_position; q < text_length - amount; q++)
        in_text[q] = in_text[q + amount];
    in_text[text_length - amount] = char('\0');
}

void B7_5_4()
{
    const int MAX = 1000; 
    char in_text[MAX];

    cout << "Мессир, извольте строку предоставить: " << endl;
    cin.getline(in_text, MAX, '\n');
    
    int amount = 0,
        start_position = 0,
        text_length = 0;
    char last_char = in_text[0];
    /**/
    for (; in_text[text_length]; text_length++); // Просто считаем длину строки
    
    for (int i = 0; in_text[i]; i++)
    {
        if (!amount && (in_text[i] == char(' ')))
            start_position = i;
        
        if ((in_text[i] == char(' ')) && (last_char == char(' ')))
            amount++;
        else if ((last_char == char(' ')) && (amount > 1))
        {
            str_part_delete(in_text, text_length, start_position, amount);
            amount = 0;
        }
        last_char = in_text[i];
    }
    /**/
    /**
    cout << "Стартовая позиция символов к удалению: ";
    cin >> start_position;
    cout << "Кол-во символов к удалению: ";
    cin >> amount;
    str_part_delete(start_position, text_length, amount, in_text);
    /**/
    cout << in_text << endl;
}

int main()
{
    for (int j = 0; j < 13; j++)
    {
        int n = 0;
        cout << endl << "Вариант 7B" << endl
            << "(1) - Задание 5.1 - Вычисления с точностью с помощью return, pointer, reference" << endl
            << "(2) - Задание 5.2 - Создание и сортировка массивов" << endl
            << "(3) - Задание 5.3 - Упорядоченность значений в матрицах" << endl
            << "(4) - Задание 5.4 - Удаление символов из C-строк" << endl;
        cin >> n;
        cin.get();
        cout << "//////////////////////////////////////////////////////" << endl;
        switch (n)
        {
        case 1:
            B7_5_1();
            continue;
        case 2:
            B7_5_2();
            continue;
        case 3:
            B7_5_3();
            continue;
        case 4:
            B7_5_4();
            continue;
        default:
            cout << "Ah, crap, wrong input..." << endl;
        }
        cout << endl << "//////////////////////////////////////////////////////" << endl;
        return 0;
    }
}
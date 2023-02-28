#include <iostream>
#include <cstring>

using namespace std;

void B7_4_1()
{
    const int MAX = 1000; 
    char in_text[MAX];
    cout << "Мессир, извольте строку предоставить: " << endl;
    cin.getline(in_text, MAX, '\n');

    int amount = 1,
        start_char_i = 0,
        max_amount = 0,
        max_start_char_i = 0,
        text_length = 1;
    char last_char = '0';

    for (;; text_length++)
    {
        if (in_text[text_length] == last_char)
            amount++;
        else
        {
            if (amount > max_amount)
            {
                max_amount = amount;
                max_start_char_i = start_char_i;
            }
            start_char_i = text_length;
            amount = 1;
            last_char = in_text[text_length];
        }

        if (!(in_text[text_length]))
            break;
    }

    for (int q = max_start_char_i; q < text_length - max_amount; q++)
        in_text[q] = in_text[q + max_amount];
    in_text[text_length - max_amount] = char('\0');
    cout << in_text << endl;
}

void B7_4_2()
{
    const int MAX = 1000;
    int simple_array[MAX] = {2},
        simple_nums_count = 1,
        sorted_simple_array[MAX],
        N = 0,
        clear_bits_amount = 0,
        n = 0;
    int unclear_bits[32],
        clear_bits[32];
    cout << "Simple nums must`n be greater than (N): "; 
    cin >> N;

    for (int num = 3; num <= N; num++) 
    {
        bool is_simple = true;

        for (int i = 0; i < simple_nums_count; i++) 
        {
            if (num % simple_array[i] == 0)
            {
                is_simple = false;
                break;
            }
        }

        if (is_simple)
        {
            cout << num << " = ";
            simple_array[simple_nums_count++] = num;
            for (int i = 0; i < 32; i++)
            {
                unclear_bits[i] = ((num >> (31 - i)) & 1);
                cout << unclear_bits[i];
            }
            cout << " = ";
            clear_bits_amount = 0;
            for (int i = 0, f = 0; i < 32; i++)
            {
                if (unclear_bits[i] == 1)
                    f++;
                if (f)
                {
                    clear_bits[clear_bits_amount] = unclear_bits[i];
                    cout << clear_bits[clear_bits_amount];
                    clear_bits_amount++;
                }
            }
            cout << endl;
            bool is_symmetric = true;
            if (clear_bits_amount % 2 == 0)
                for (int i = 0, q = clear_bits_amount - 1; (i < clear_bits_amount / 2) && (q >= clear_bits_amount / 2); q--, i++)
                {
                    if (clear_bits[i] != clear_bits[q])
                        is_symmetric = false;
                }
            else
                for (int i = 0, q = clear_bits_amount - 1; (i < clear_bits_amount / 2) && (q > clear_bits_amount / 2); q--, i++)
                {    
                    if (clear_bits[i] != clear_bits[q])
                        is_symmetric = false;
                }
            if (is_symmetric)
            {
                sorted_simple_array[n] = num;
                n++;
            }
        }
    }
    cout << endl << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
        cout << sorted_simple_array[i] << " ";
}

void B7_4_3()
{
    const int MAX = 1000;
    int A_words_amount = 0,
        B_words_amount = 0;
    char data[MAX],
        A[100][100],
        B[100][100],
        separators[11] = " .,:;!?-()";
    char symbol;
    bool is_separator = false;
    cout << "Введите парочку слов: ";
    
    for (int i = 0, q = 0; i < MAX; i++)
    {
        cin.get(symbol);
        if (int(symbol) == '\n')
            break;
        for (int j = 0; j < 11; j++)
            if (symbol == separators[j])
                is_separator = true;
        if (!is_separator)
        {
            A[A_words_amount][q] = symbol;
            q++;
        }
        else
        {
            A_words_amount++;
            q = 0;
            is_separator = false;
        }
    }

    // Выводим массив слов A[n][n], заодно проверяя слова на повторяющиеся буквы и записывая в массив B[n][n] подходящие слова
    cout << "Введённая строка (для проверки): ";
    bool repeats = false;
    for (int i = 0; i <= A_words_amount; i++)
    {
        repeats = false;
        for (int q = 0; A[i][q]; q++)
        {
            cout << A[i][q];
            for (int j = q + 1; A[i][j]; j++)
                if (A[i][q] == A[i][j])
                {
                    repeats = true;
                    break;
                }
        }
        if (!repeats)
        {
            for (int k = 0; A[i][k]; k++)
            {
                B[B_words_amount][k] = A[i][k];
            }
            B_words_amount++;
        }
        cout << " ";
    }
    cout << endl;

    // Выводи массив B[n][n]
    cout << "Итоговая строка: ";
    for (int i = 0; i <= B_words_amount; i++)
    {
        for (int q = 0; B[i][q]; q++)
            cout << B[i][q];
        cout << " ";
    }
    cout << endl;
}

int main()
{
    // for (int i = 0; i <= 10; i++)
    // {
        int n = 0;;
        cout << endl << "Вариант 7B" << endl
            << "(1) - Задание 4.1 - Удаление максимальной серии подряд идущих символов" << endl
            << "(2) - Задание 4.2 - Простые числа, меньше натурального N, битовое представление которых симметрично" << endl
            << "(3) - Задание 4.3 - Удаление слов с повторяющимися буквами" << endl;
        cin >> n;
        cin.get();
        cout << "//////////////////////////////////////////////////////" << endl;
        switch (n)
        {
        case 1:
            B7_4_1();
            break;
        case 2:
            B7_4_2();
            break;
        case 3:
            B7_4_3();
            break;
        default:
            cout << "Ah, crap, wrong input..." << endl;
        }
        cout << endl << "//////////////////////////////////////////////////////" << endl;
    // }
    return 0;
}
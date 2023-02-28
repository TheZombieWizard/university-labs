#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int intPow(int num, int i) 
{
    int x = num;
    for (int count = 1; count < i; count++) 
    {
        num *= x;
    }
    return num;
}

int countDigits(int num) 
{
    int n = 1;
    while ((num /= 10) > 0) n++;
    return n;
}

void B7_2_1_1() 
{
    int num;
    cout << "Insert number: ";  cin >> num;
    bool equal_nums_exist = false, too_many_equal_nums_exist = false;
    int numi, numq;
    int num_lenght = countDigits(num);
    for (int i = 1; (i != num_lenght) && (!too_many_equal_nums_exist); i++)
    {
        if (i == 1) 
        { 
            numi = (num % 10);
        }
        else 
        { 
            numi = (num % intPow(10, i)) / (intPow(10, i - 1));
        }
        for (int q = i + 1; q <= num_lenght; q++)
        {
            numq = (num % intPow(10, q)) / (intPow(10, q - 1));
            if (numi == numq) 
            {
                if (equal_nums_exist) 
                {
                    too_many_equal_nums_exist = true;
                    break;
                }
                else 
                {
                    equal_nums_exist = true;
                }
            }

        }
    }
    if (too_many_equal_nums_exist) 
    { 
        cout << "False. Too many equal numbers"; 
    }
    else if (equal_nums_exist) 
    { 
        cout << "True. There are only 2 equal numbers."; 
    }
    else 
    { 
        cout << "False. There are no equal numbers."; 
    }
}

void B7_2_1_2() 
{
    double number;
    int k;
    cout << "Insert number: ";  
    cin >> number;
    cout << "Insert k: ";  
    cin >> k;
    int digit_before_dot = 0;
    int sum_of_digits_before_dot = 0;
    int num_before_dot = int(number);
    int num_lenght = countDigits(number);
    // cout.precision(30);
    // cout << num_before_dot << endl;
    for (int i = 1; i != num_lenght + 1; i++) 
    {
        if (i == 1) 
        {
            digit_before_dot = (num_before_dot % intPow(10, i));
        }
        else 
        {
            digit_before_dot = (num_before_dot % intPow(10, i)) / (intPow(10, i - 1));
        }
        sum_of_digits_before_dot += digit_before_dot;
    }
    // cout << sum_of_digits_before_dot << endl;

    int digit_after_dot = 0;
    int sum_of_digits_after_dot = 0;
    int num_after_dot = int((number - int(number)) * intPow(10, k));
    int num_after_dot_lenght = countDigits(num_after_dot);
    // cout << num_after_dot << endl;
    for (int i = 1; i != num_after_dot_lenght + 1; i++)
    {
        if (i == 1) 
        {
            digit_after_dot = (num_after_dot % intPow(10, i));
        }
        else 
        {
            digit_after_dot = (num_after_dot % intPow(10, i)) / (intPow(10, i - 1));
        }
        sum_of_digits_after_dot += digit_after_dot;
    }
    // cout << sum_of_digits_after_dot << endl;
    if (sum_of_digits_after_dot == sum_of_digits_before_dot) 
    { 
        cout << "True"; 
    }
    else 
    { 
        cout << "False"; 
    }
}

/**/
void B7_2_2()
{
    double
        simple_function = 0,
        compl_formula = 0,
        compl_formula_part = 0,
        part = 0;
    const double E = 1.0E-6;
    double
        x = -0.5,
        xn = 0.5,
        dx = 0.1,
        a = 0,
        b = 0;
    int n = 0;
    cout.width(15);
    cout << "X";
    cout.width(30);
    cout << "Built-in function";
    cout.width(30);
    cout << "Teylors row";
    cout.width(30);
    cout << "Teylors nums amount";
    cout << endl;
    for (; x <= xn; x += dx) 
    {
        simple_function = sqrt(1 + x);
        compl_formula = 0;
        compl_formula_part = 0;
        cout.width(15);
        cout << x;
        cout.width(30);
        cout << simple_function;
        for (int i = 0, n = 0;; i++, n++, a += 2, b += 2)
        {
            if (i == 0)
            {
                compl_formula_part = 1;
            } else if (i == 1) {
                compl_formula_part = 0.5 * x;
            } else if (i == 2) {
                compl_formula_part = -0.125 * x * x;
                a = 1;
                b = 4;
            } else {
                compl_formula_part *= (-1) * x * a / b;
            }
            compl_formula += compl_formula_part;
            if (abs(compl_formula_part) < E) 
            { 
                cout.width(30);
                cout.precision(10);
                cout << compl_formula;
                cout.width(30);
                cout << n;
                cout << endl;
                break; 
            }
        }
    }
}
/**/

void B7_2_3() 
{
    int n, m;
    cout << "Insert n, m: "; 
    cin >> n >> m;
    int simple_nums_count = 0;
    for (int num = 2; simple_nums_count < n; num++) 
    {
        int nums_left_part = num, sum_of_digits = 0;
        bool is_simple = true;
        for (int i = 2; i <= num / 2; i++) 
        {
            if (num % i == 0) 
            {
                is_simple = false;
            }
        }

        if (is_simple)
        {
            while (nums_left_part > 0)
            {
                sum_of_digits += nums_left_part % 10;
                nums_left_part = nums_left_part / 10;
            }
            if (sum_of_digits < m)
            {
                simple_nums_count++;
                cout << num << endl;
            }
        }
    }

}

void B7_2_4()
{
    int n = 0;
    cout << "Кол-во чисел в последовательности (n): ";
    cin >> n;
    double num = 0, last_num = 0, k = 0, last_k = 0, amount = 2, max_amount = 1;
    if (n < amount)
    {
        max_amount = amount = n;
    }
    else {
        for (int i = 0; i <= n - 1; i++)
        {
            cout << "num: ";
            cin >> num;
            if (i == 0)
            {
                last_num = num;
                continue;
            }
            else if (i == 1) {
                k = num / last_num;
                last_k = k;
                amount = 2;
                last_num = num;
                continue;
            }
            k = num / last_num;
            // cout << "/////////    " << num << " / " << last_num << " || " << k << " ?= " << last_k;
            if (k == last_k)
            {
                amount++;
                if (amount > max_amount)
                    max_amount = amount;
            }
            else {
                last_k = k;
                amount = 2;
            }
            // cout << " --  amount = " << amount << endl;
            last_num = num;
        }
    }
    cout << "Кол-во чисел в самой длинной геометрической подпоследовательности: " << max_amount;
}

void B7_2_5() 
{
    int k = 0;
    int ki = 0;
    cout << "Insert k: ";
    cin >> k;
    bool answer_is_found = false;
    for (int i = 1; !answer_is_found; i++)
    {
        int num = i * i * i;
        cout << "Iteration: " << i << " // " << "Num = " << num << endl;
        int check_num = num, num_length = 0;
        while (check_num != 0)
        {
            num_length += 1;
            check_num /= 10;
        }
        for (int q = 1; (q <= num_length) && (!answer_is_found); q++)
        {
            int numi = num / int(pow(10, num_length - q));
            ki++;
            if (ki == k)
            {
                cout << "Answer = " << numi % 10;
                answer_is_found = true;
            }
        }
    }
}

int main() 
{
    while (true)
    {
        int n = 0;
        cout << endl << "Вариант B7 " << endl
            << "(11) - Задание 2.1.1 - Дано натуральное n. Верно ли, что какая-то цифра встречается в числе ровно 2 раза" << endl
            << "(12) - Задание 2.1.2 - Определить равна ли сумма первых k цифр дробной части заданного положительного вещественного числа сумме цифр целой части этого числа" << endl
            << "(2) - Задание 2.2 - Итерационные циклы" << endl
            << "(3) - Задание 2.3 - Нахождение простых чисел" << endl
            << "(4) - Задание 2.4 - Последовательности значений" << endl
            << "(5) - Задание 2.5 - Вычисления без хранения последовательности значений" << endl;
        cin >> n;
        cout << "//////////////////////////////////////////////////////" << endl;
        switch (n) 
        {
        case 11:
            B7_2_1_1(); 
            break;
        case 12:
            B7_2_1_2(); 
            break;
        case 2:
            B7_2_2();
            break;
        case 3:
            B7_2_3(); 
            break;
        case 4:
            B7_2_4();
            break;
        case 5:
            B7_2_5();
            break;
        default:
            cout << "Ah, crap..." << endl;
        }
        cout << endl << "//////////////////////////////////////////////////////" << endl;
    }
    return 0;
}
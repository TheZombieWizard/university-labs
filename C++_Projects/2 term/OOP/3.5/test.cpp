#include <iostream>
#include <string>

using namespace std;

void task_4_1();
void task_4_2();
void task_4_3();

/*
int main()
{
    //task_4_1();
    //task_4_2();
    //task_4_3();
    
    return 0;
}
*/

void task_4_1()
{
    float float_number = 2.13;
    int hex_number = 0x16;

    short symbols_count[256] = {0};
    string input_text = "";
    
    cout << "Enter the text: " << endl;
    while (true)
    {
        char symbol;
        cin.get(symbol);
        
        if (symbol == '\n')
            break;

        input_text += symbol;
        symbols_count[int(symbol)] += 1;
    }

    string modified_text = "";
    for (int i = 0; i < input_text.size(); ++i)
        if (symbols_count[int(input_text[i])] != 1)
            modified_text += input_text[i];
    
    cout << modified_text;
}

void task_4_2()
{
    string binary_num = "";
    cout << "Enter float binary num: " << endl;
    cin >> binary_num;

    int whole_part = 0;
    double fractional_part = 0;
    int i = 0;
    for (; i < binary_num.size(); ++i)
    {
        if ((binary_num[i] == ',') || (binary_num[i] == '.'))
            break;
        
        if (binary_num[i] == '0')
            whole_part *= 2;
        else if (binary_num[i] == '1')
        {
            whole_part *= 2;
            whole_part += 1;
        }
    }

    ++i;
    
    for (; i < binary_num.size(); ++i)
    {
        if (binary_num[i] == '0')
            fractional_part *= 2;
        else if (binary_num[i] == '1')
        {
            fractional_part *= 2;
            //fractional_part += 1;
        }
    }

    //while (fractional_part > 1)
    //    fractional_part /= 10;

    double decimal_number = whole_part + fractional_part;
    cout << decimal_number;
}

/*
void task_4_3()
{
    string output_text = "";
    string word = "";

    cout << "Enter the text: " << endl;
    while (true)
    {
        char symbol;
        cin.get(symbol);
        
        if (symbol == ' ')
        {
            if (word.size() % 2 == 0)
            {
                bool is_symmetrical = true;
                for (int i = 0, q = word.size()-1; (i < word.size() / 2) && (q >= word.size() / 2); ++i, --q)
                    if (word[i] != word[q])
                        is_symmetrical = false;
                
                if (!is_symmetrical)
                    output_text += word + " ";
            }
            word = "";
            continue;
        } 
        else if (symbol == '\n') 
        {
            if (word.size() % 2 == 0)
            {
                bool is_symmetrical = true;
                for (int i = 0, q = word.size()-1; (i < word.size() / 2) && (q >= word.size() / 2); ++i, --q)
                    if (word[i] != word[q])
                        is_symmetrical = false;
                
                if (!is_symmetrical)
                    output_text += word;
            }
            word = "";
            break;
        }

        word += symbol;
    }

    cout << output_text << endl;
}
*/
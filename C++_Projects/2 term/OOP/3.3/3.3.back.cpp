#include "3.3.back.h"


void task_2_4()
{
    srand(time(NULL));
    forward_list<char> original_list;
    
    for (int i = 0; i < 42; ++i)
    {
        bool upper_case = rand() % 2;
        if (upper_case) 
            original_list.push_front(char((rand() % 26) + 65));
        else
            original_list.push_front(char((rand() % 26) + 97));
    }
    
    cout << "Original list: " << endl;
    for (char symbol : original_list)
        cout << symbol << " ";
    cout << endl;
    
    forward_list<char> sorted_list = original_list;
    sorted_list.sort();
    forward_list<char> modified_list;
    
    cout << endl << "Sorted list: " << endl;
    for (char symbol : sorted_list)
        cout << symbol << " ";
    cout << endl;

    char last_symbol = 0;
    int count = 1;
    for (char symbol : sorted_list)
    {
        if (last_symbol == 0)
            last_symbol = symbol;
        else
        {
            if (symbol == last_symbol)
                ++count;
            else
            {
                if (count == 2)
                    modified_list.push_front(last_symbol);
                count = 1;
                last_symbol = symbol;
            }
        }
    }

    modified_list.sort();
    cout << endl << "Modified list: " << endl;
    for (char symbol : modified_list)
        cout << symbol << " ";
    cout << endl;
}

void task_2_6()
{
    srand(time(NULL));
    list<int> numbers_list;
    
    for (int i = 0; i < 42; ++i)
        numbers_list.push_back(rand() % 13);
    
    cout << "Numbers list: " << endl;
    for (int num : numbers_list)
        cout << num << " ";
    cout << endl;

    list<int> first_number_list = numbers_list;
    list<int> last_number_list = numbers_list;

    int sum = 0;
    int list_size = numbers_list.size();
    for (int i = 0; i < list_size; ++i)
    {
        int first_num = first_number_list.front();
        first_number_list.pop_front();
    
        int second_num = first_number_list.front();

        int last_num = last_number_list.back();
        last_number_list.pop_back();

        int subsum = first_num + second_num + (list_size - i) * (last_num);
        cout << setw(3) << i << " subsum:  " << subsum << endl;   
        sum += subsum;
    }
    cout << "Total sum:  " << sum;

}
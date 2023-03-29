#include "..\..\..\..\headers\LinearList.h"

int main()
{
    LinearList<char> original_list;
    for (unsigned int i = 0; i < 42; i++)
        original_list.add_node();
    original_list.print_list();
    cout << endl;
    original_list.sort();

    cout << "// Sorted list for checking //" << endl;
    original_list.print_list();
    cout << endl;

    LinearList<char> modified_list;
    modified_list.selective_copy(original_list);
    modified_list.print_list();

    return 0;
}
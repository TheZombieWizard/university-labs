#include "2.3.back.h"


int main()
{
    int n = 0;
    cout << "Input n: ";
    cin >> n;
    DoubleLinkedList_2_3<int> original_list;
    for (int i = 0; i < n; i++)
        original_list.add_node();
    original_list.print_list();
    cout << original_list.strange_sum();
}
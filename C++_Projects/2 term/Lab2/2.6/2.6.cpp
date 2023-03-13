#include "2.6.back.h"

int main()
{
    Node *top = NULL;
    int n = 10;
    
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        create_node(top);
    
    print_list(top);
    cout << "Sum = " << strange_sum(top, n) << endl;

    return 0;
}
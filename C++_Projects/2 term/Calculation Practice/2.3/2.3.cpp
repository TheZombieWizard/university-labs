#include "2.3.back.h"

int main()
{
    Node *top = NULL;
    
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        create_node(top);
    
    print_list(top);
    sort(top);
    print_list(top);

    return 0;
}
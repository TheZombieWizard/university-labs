#include "2.4.back.h"

int main()
{
    Node *L1_top = NULL;
    Node *L2_top = NULL;
    
    srand(time(NULL));
    for (int i = 0; i < 42; i++)
        create_node_rand(L1_top);
    
    cout << setw(20) << "1st list:" << "     ";
    print_list(L1_top);

    sort(L1_top);
    create_L2(L1_top, L2_top);
    
    cout << setw(20) << "1st list sorted:" << "     ";
    print_list(L1_top);

    cout << setw(20) << "2st list:" << "     ";
    print_list(L2_top);

    return 0;
}
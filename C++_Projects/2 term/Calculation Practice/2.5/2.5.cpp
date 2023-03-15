#include "2.5.back.h"

int main()
{
    int N = 42;
    int **nodes_arrayL1 = new int*[N];
    int **nodes_arrayL2 = new int*[N];
    
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        create_node_rand(nodes_arrayL1);
    
    cout << setw(20) << "1st list:" << "     ";
    print_list(nodes_arrayL1);

    //sort(nodes_arrayL1);
    //create_L2(nodes_arrayL1, nodes_arrayL2);
    
    //cout << setw(20) << "1st list sorted:" << "     ";
    //print_list(nodes_arrayL1);

    //cout << setw(20) << "2st list:" << "     ";
    //print_list(nodes_arrayL2);

    return 0;
}
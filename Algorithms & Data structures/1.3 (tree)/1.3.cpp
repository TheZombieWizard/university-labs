#include <iostream>
#include "BinaryTree.h"

using namespace std;


int main() 
{
    short n, m;
    cin >> n >> m;
    BinaryTree<int> numbers_tree;
    
    for (int i = 0; i < n; ++i)
    {
        for (int q = 0; q < m; ++q)
        {
            int num;
            cin >> num;
            numbers_tree.add_node(num);
        }
    }

    numbers_tree.print();

    return 0;
}
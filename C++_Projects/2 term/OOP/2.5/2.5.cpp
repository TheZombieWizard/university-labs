#include "..\..\..\..\headers\BinaryTree.h"


int main()
{
    BinaryTree<int> tree;
    for (int i = 0; i < 42; i++)
        tree.add_node();
    tree.print();
    
    return 0;
}
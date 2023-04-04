#include <iostream>
#include <cstdlib>

using namespace std;

template <typename datatype>
struct Node
{
    datatype symbol;
    Node* left;
    Node* right;
};

template <class datatype>
class BinaryTree
{   
    Node<datatype>* tree_root;
public:
    BinaryTree(datatype symbol);
    BinaryTree();
    ~BinaryTree();

    //BinaryTree(const BinaryTree &copying_tree);
    //BinaryTree(BinaryTree&& moving_tree);
    //BinaryTree& operator= (const BinaryTree& copying_tree);
    //BinaryTree& operator=(BinaryTree&& moving_tree);

    void clear(Node<datatype>* node);
    void clear();
    //Node<datatype>* find(datatype symbol);
    void print(Node<datatype>* node);
    void print();
    Node<datatype>* root();
    void delete_node(datatype symbol);
    void add_node(datatype symbol);
    void add_node();
};
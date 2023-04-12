#include "BinaryTree.h"

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<double>;
template class BinaryTree<char>;

template <class datatype>
BinaryTree<datatype> :: BinaryTree(datatype symbol)
{
    tree_root = new Node<datatype>;
    tree_root->symbol = symbol;
    tree_root->left = nullptr;
    tree_root->right = nullptr;
}

template<>
BinaryTree<char> :: BinaryTree()
{
    srand(time(NULL) + rand() % 42);
    tree_root = new Node<char>;
    char symbol;
    if (rand() % 2)
        symbol = char((rand() % 26) + 65);
    else
        symbol = char((rand() % 26) + 97);
    tree_root->symbol = symbol;
    tree_root->left = nullptr;
    tree_root->right = nullptr;
}

template <class datatype>
BinaryTree<datatype> :: BinaryTree()
{
    srand(time(NULL) + rand() % 42);
    tree_root = new Node<datatype>;
    datatype symbol;
    symbol = datatype(rand() % 42) + 1 + datatype((rand() % 100) / 100);
    
    tree_root->symbol = symbol;
    tree_root->left = nullptr;
    tree_root->right = nullptr;
}

template <class datatype>
BinaryTree<datatype> :: ~BinaryTree()
{
    this->clear();
}

template <class datatype>
BinaryTree<datatype> :: BinaryTree(const BinaryTree<datatype> &copying_tree)
{
    tree_root = new Node<datatype>;
    tree_root->symbol = copying_tree.tree_root->symbol;
    tree_root->left = nullptr;
    tree_root->right = nullptr;

    this->copy(copying_tree.tree_root->left);
    this->copy(copying_tree.tree_root->right);
}

template <class datatype>
BinaryTree<datatype> :: BinaryTree(BinaryTree<datatype>&& moving_tree)
{
    tree_root = moving_tree.tree_root;
    moving_tree.tree_root = nullptr;
}

template <class datatype>
BinaryTree<datatype>& BinaryTree<datatype> :: operator= (const BinaryTree<datatype>& copying_tree)
{   
    tree_root = new Node<datatype>;
    tree_root->symbol = copying_tree.tree_root->symbol;
    tree_root->left = nullptr;
    tree_root->right = nullptr;

    this->copy(copying_tree.tree_root->left);
    this->copy(copying_tree.tree_root->right);
    
    return *this;  
}

template <class datatype>
class BinaryTree<datatype>& BinaryTree<datatype> :: operator=(BinaryTree<datatype>&& moving_tree)
{   
    this->clear();
    tree_root = moving_tree.tree_root;
    moving_tree.tree_root = nullptr;
    
    return *this;
}

template <class datatype>
void BinaryTree<datatype> :: copy(Node<datatype>* node)
{
    if (node)
    {
        this->add_node(node->symbol);

        if (node->left)
            copy(node->left);
        
        if (node->right)
            copy(node->right);
    }
}

template <class datatype>
void BinaryTree<datatype> :: clear(Node<datatype>* node)
{
    if (node)
    {
        if (node->left)
        {
            clear(node->left);
            node->left = nullptr;
        }
    
        if (node->right)
        {
            clear(node->right);
            node->right = nullptr;
        }

        node->symbol = 0;
    }
}

template <class datatype>
void BinaryTree<datatype> :: clear()
{
    clear(tree_root);
}

template <class datatype>
Node<datatype>* BinaryTree<datatype> :: find(datatype symbol)
{
    Node<datatype>* current_node = tree_root;

    while (current_node)
    {
        if (symbol == current_node->symbol)
            return current_node;
        if (symbol > current_node->symbol)
        {
            if (current_node->right)
                current_node = current_node->right;
            else
            {
                cout << "There is no such element" << endl;
                break;
            }
        }
        else
        {
            if (current_node->left)
                current_node = current_node->left;
            else
            {
                cout << "There is no such element" << endl;
                break;
            }
        }
    }
    return 0;
}

template <class datatype>
void BinaryTree<datatype> :: print(Node<datatype>* node)
{
    if (node)
    {
        if (node->left)
            print(node->left);
    
        cout << node->symbol << " ";
    
        if (node->right)
            print(node->right);
    }
}

template <class datatype>
void BinaryTree<datatype> :: print() 
{
    print(tree_root);
}

template <class datatype>
Node<datatype>* BinaryTree<datatype> :: root()
{
    return tree_root;
}

template <class datatype>
void BinaryTree<datatype> :: delete_node(datatype symbol)
{
    srand(time(NULL) + rand() % 42);
    Node<datatype>* current_node = tree_root;

    while (current_node)
    {
        if (symbol == current_node->symbol)
        {
            this->clear(current_node);
            break;
        }
        else if (symbol > current_node->symbol)
            current_node = current_node->right;
        else
            current_node = current_node->left;
    }
}

template <class datatype>
void BinaryTree<datatype> :: delete_min_node()
{
    Node<datatype>* last_node = tree_root;
    Node<datatype>* current_node = tree_root;

    while (current_node)
    {
        if (current_node->left)
        {
            last_node = current_node;
            current_node = current_node->left;
        }
        else
        {
            last_node->left = nullptr;
            if (current_node->right && (current_node == tree_root))
                tree_root = current_node->right;
            else if (current_node->right)
                last_node->left = current_node->right;
            current_node->symbol = 0;
            break;
        }
    }
}

template <class datatype>
void BinaryTree<datatype> :: add_node(datatype symbol)
{
    srand(time(NULL) + rand() % 42);
    Node<datatype>* current_node = tree_root;

    while (current_node)
    {
        if (symbol == current_node->symbol)
            break;
        if (symbol > current_node->symbol)
        {
            if (current_node->right)
                current_node = current_node->right;
            else
            {
                current_node->right = new Node<datatype>;
                current_node->right->symbol = symbol;
                current_node->right->left = nullptr;
                current_node->right->right = nullptr;
                break;
            }
        }
        else
        {
            if (current_node->left)
                current_node = current_node->left;
            else
            {
                current_node->left = new Node<datatype>;
                current_node->left->symbol = symbol;
                current_node->left->left = nullptr;
                current_node->left->right = nullptr;
                break;
            }
        }
    }
}

template <>
void BinaryTree<char> :: add_node()
{
    srand(time(NULL) + rand() % 42);
    char symbol;
    if (rand() % 2)
        symbol = char((rand() % 26) + 65);
    else
        symbol = char((rand() % 26) + 97);
    
    Node<char>* current_node = tree_root;

    while (current_node)
    {
        if (symbol == current_node->symbol)
            break;
        if (symbol > current_node->symbol)
        {
            if (current_node->right)
                current_node = current_node->right;
            else
            {
                current_node->right = new Node<char>;
                current_node->right->symbol = symbol;
                current_node->right->left = nullptr;
                current_node->right->right = nullptr;
                break;
            }
        }
        else
        {
            if (current_node->left)
                current_node = current_node->left;
            else
            {
                current_node->left = new Node<char>;
                current_node->left->symbol = symbol;
                current_node->left->left = nullptr;
                current_node->left->right = nullptr;
                break;
            }
        }
    }
}

template <class datatype>
void BinaryTree<datatype> :: add_node()
{
    srand(time(NULL) + rand() % 42);
    datatype symbol;
    symbol = datatype(rand() % 42) + datatype((rand() % 100) / 100);
    Node<datatype>* current_node = tree_root;

    while (current_node)
    {
        if (symbol == current_node->symbol)
            break;
        if (symbol > current_node->symbol)
        {
            if (current_node->right)
                current_node = current_node->right;
            else
            {
                current_node->right = new Node<datatype>;
                current_node->right->symbol = symbol;
                current_node->right->left = nullptr;
                current_node->right->right = nullptr;
                break;
            }
        }
        else
        {
            if (current_node->left)
                current_node = current_node->left;
            else
            {
                current_node->left = new Node<datatype>;
                current_node->left->symbol = symbol;
                current_node->left->left = nullptr;
                current_node->left->right = nullptr;
                break;
            }
        }
    }
}
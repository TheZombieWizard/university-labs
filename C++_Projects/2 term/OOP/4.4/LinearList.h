#include <iostream>
#include <cstdlib>

using namespace std;


//----------------------------------------------------------------------
//----------------------------------------------------------------------
template <class datatype>
class LinearList
{
    struct Node
    {
        datatype* symbol;
        Node* next_node;
    };
    Node* top_node;
public:
    LinearList();
    ~LinearList();

    LinearList(const LinearList &copying_linear_list);
    LinearList& operator= (const LinearList& copying_linear_list);
    LinearList(LinearList&& moving_linear_list);
    LinearList& operator=(LinearList&& moving_linear_list);

    void print();
    void push_back(datatype* symbol);
    void pop_back();
};
//----------------------------------------------------------------------
//----------------------------------------------------------------------

template <class datatype>
LinearList<datatype> :: LinearList()
{
    top_node = nullptr;
}

template <class datatype>
LinearList<datatype> :: ~LinearList()
{
    if (top_node)
    {
        Node* temp_next_node = top_node->next_node;
        while (top_node)
        {
            (*top_node->symbol).delete_self();
            delete top_node;
            top_node = temp_next_node;
            if (temp_next_node)
                temp_next_node = temp_next_node->next_node;
        }
    }
}

template <class datatype>
LinearList<datatype> :: LinearList(const LinearList<datatype> &copying_list)
{
    Node* current_node = copying_list.top_node;
    
    top_node = nullptr;
    top_node = new Node;
    top_node->symbol = current_node->symbol;
    top_node->next_node = nullptr;
    current_node = current_node->next_node;
    
    while (current_node)
    {
        this->push_back(current_node->symbol);
        current_node = current_node->next_node;
    }
}

template <class datatype>
LinearList<datatype>& LinearList<datatype> :: operator= (const LinearList<datatype>& copying_list)
{   
    Node* current_node = copying_list.top_node;
    
    delete top_node;
    top_node = new Node;
    top_node->symbol = current_node->symbol;
    top_node->next_node = nullptr;
    current_node = current_node->next_node;
    
    while (current_node)
    {
        this->push_back(current_node->symbol);
        current_node = current_node->next_node;
    }
    
    return *this;  
}

template <class datatype>
LinearList<datatype> :: LinearList(LinearList<datatype>&& moving_list)
{
    top_node = new Node;
    top_node = moving_list.top_node;
    
    moving_list.top_node = nullptr;
}

template <class datatype>
class LinearList<datatype>& LinearList<datatype> :: operator=(LinearList<datatype>&& moving_list)
{   
    this->~LinearList();
    top_node = new Node;
    top_node = moving_list.top_node;

    moving_list.top_node = nullptr;
    
    return *this;
}

template <class datatype>
void LinearList<datatype> :: print()
{
    Node* current_node = top_node;
    while (current_node)
    {
        cout << *current_node->symbol << endl;
        current_node = current_node->next_node;
    }
    cout << endl;
}

template <class datatype>
void LinearList<datatype> :: push_back(datatype* symbol)
{
    if (!top_node)
    {
        top_node = new Node;
        top_node->symbol = symbol;
        top_node->next_node = nullptr;
        return;
    }

    Node* current_node = top_node;
    Node* created_node = new Node;
    created_node->symbol = symbol;
    created_node->next_node = nullptr;

    while (current_node->next_node)
        current_node = current_node->next_node;
    current_node->next_node = created_node;
}

template <class datatype>
void LinearList<datatype> :: pop_back()
{
    if (!top_node)
        return;
    
    Node* current_node = top_node;
    Node* temp_last_node = current_node;
    
    while (current_node->next_node)
    {
        temp_last_node = current_node;
        current_node = current_node->next_node;
    }


    (*current_node->symbol).delete_self();
    current_node->symbol = nullptr;
    current_node = nullptr;
    temp_last_node->next_node = nullptr;
}
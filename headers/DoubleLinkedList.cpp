#include "DoubleLinkedList.h"

template class DoubleLinkedList<int>;
template class DoubleLinkedList<float>;
template class DoubleLinkedList<double>;
template class DoubleLinkedList<char>;

template <class datatype>
DoubleLinkedList<datatype> :: DoubleLinkedList(datatype symbol)
{
    top_node = new Node<datatype>;
    top_node->symbol = symbol;
    top_node->prev_node = nullptr;
    top_node->next_node = nullptr;
}

template<>
DoubleLinkedList<char> :: DoubleLinkedList()
{
    srand(time(NULL) + rand() % 666);
    top_node = new Node<char>;
    char symbol;
    if (rand() % 2)
        symbol = char((rand() % 26) + 65);
    else
        symbol = char((rand() % 26) + 97);
    top_node->symbol = symbol;
    top_node->prev_node = nullptr;
    top_node->next_node = nullptr;
}

template <class datatype>
DoubleLinkedList<datatype> :: DoubleLinkedList()
{
    srand(time(NULL) + rand() % 666);
    top_node = new Node<datatype>;
    datatype symbol;
    symbol = datatype(rand() % 42) + datatype((rand() % 100) / 100);
    top_node->symbol = symbol;
    top_node->prev_node = nullptr;
    top_node->next_node = nullptr;
}

template <class datatype>
DoubleLinkedList<datatype> :: ~DoubleLinkedList()
{
    if (top_node)
    {
        Node<datatype>* temp_next_node = top_node->next_node;
        while (top_node)
        {
            delete top_node;
            top_node = temp_next_node;
            if (temp_next_node)
                temp_next_node = temp_next_node->next_node;
        }
    }
}

template <class datatype>
DoubleLinkedList<datatype> :: DoubleLinkedList(const DoubleLinkedList<datatype> &copying_vector)
{
    Node<datatype>* current_node = copying_vector.top_node;
    
    top_node = new Node<datatype>;
    top_node->symbol = current_node->symbol;
    top_node->prev_node = nullptr;
    top_node->next_node = nullptr;
    current_node = current_node->next_node;
    
    while (current_node)
    {
        this->add_node(current_node->symbol);
        current_node = current_node->next_node;
    }
}

template <class datatype>
DoubleLinkedList<datatype>& DoubleLinkedList<datatype> :: operator= (const DoubleLinkedList<datatype>& copying_vector)
{   
    Node<datatype>* current_node = copying_vector.top_node;
    
    top_node->symbol = current_node->symbol;
    top_node->prev_node = nullptr;
    top_node->next_node = nullptr;
    current_node = current_node->next_node;
    
    while (current_node)
    {
        this->add_node(current_node->symbol);
        current_node = current_node->next_node;
    }
    
    return *this;  
}

template <class datatype>
DoubleLinkedList<datatype> :: DoubleLinkedList(DoubleLinkedList<datatype>&& moving_list)
{
    top_node = moving_list.top_node;
    moving_list.top_node = nullptr;
}

template <class datatype>
class DoubleLinkedList<datatype>& DoubleLinkedList<datatype> :: operator=(DoubleLinkedList<datatype>&& moving_list)
{   
    Node<datatype>* last_node = this->top_node;
    Node<datatype>* current_node = this->top_node->next_node;
    
    while(last_node)
    {
        last_node->symbol = 0;
        last_node->prev_node = nullptr;
        last_node->next_node = nullptr;
        last_node = current_node;
        if (current_node)
            current_node = current_node->next_node;
    }
    
    swap(this->top_node, moving_list.top_node);
    
    return *this;
}

template <class datatype>
Node<datatype>* DoubleLinkedList<datatype> :: find(datatype symbol)
{
    Node<datatype>* current_node = top_node;
    while(current_node)
    {
        if (current_node->symbol == symbol)
            return current_node;
        current_node = current_node->next_node;
    }
    return 0;
}

template <class datatype>
unsigned int DoubleLinkedList<datatype> :: count(datatype symbol)
{
    Node<datatype>* current_node = top_node;
    unsigned int quantity = 0;
    while(current_node)
    {
        if (current_node->symbol == symbol)
            quantity++;
        current_node = current_node->next_node;
    }
    return quantity;
}

template <class datatype>
void DoubleLinkedList<datatype> :: print_list()
{
    Node<datatype>* current_node = top_node;
    while (current_node)
    {
        cout << current_node->symbol << " ";
        current_node = current_node->next_node;
    }
    cout << endl;
}

template <class datatype>
Node<datatype>* DoubleLinkedList<datatype> :: first_node()
{
    return top_node;
}

template <class datatype>
void DoubleLinkedList<datatype> :: delete_first(datatype symbol)
{
    Node<datatype>* last_node = top_node;
    if (top_node->symbol == symbol)
    {
        top_node->symbol = 0;
        top_node = top_node->next_node;
        last_node->prev_node = nullptr;
        last_node->next_node = nullptr;
    }
    else
    {
        Node<datatype>* current_node = top_node->next_node;
        while(current_node)
        {
            if (current_node->symbol == symbol)
            {
                last_node->next_node = current_node->next_node;
                current_node->symbol = 0;
                current_node->prev_node = nullptr;
                current_node->next_node = nullptr;
                delete current_node;
                break;
            }
            last_node = current_node;
            current_node = current_node->next_node;
        }
    }
}

template <class datatype>
void DoubleLinkedList<datatype> :: delete_all(datatype symbol)
{
    Node<datatype>* current_node = top_node;
    unsigned int quantity = 0;
    while(current_node)
    {
        if (current_node->symbol == symbol)
            quantity++;
        current_node = current_node->next_node;
    }
    for (; quantity > 0; quantity--)
        this->delete_first(symbol);
}

template <class datatype>
void DoubleLinkedList<datatype> :: add_node(datatype symbol)
{
    Node<datatype>* current_node = top_node;
    Node<datatype>* created_node = new Node<datatype>;
    created_node->symbol = symbol;
    created_node->prev_node = nullptr;
    created_node->next_node = nullptr;

    while (current_node->next_node)
        current_node = current_node->next_node;
    current_node->next_node = created_node;
    created_node->prev_node = current_node;
}

template <class datatype>
void DoubleLinkedList<datatype> :: add_node()
{
    srand(time(NULL) + rand() % 666);
    char symbol;
    if (rand() % 2)
        symbol = char((rand() % 26) + 65);
    else
        symbol = char((rand() % 26) + 97);
    
    Node<datatype>* current_node = top_node;
    while (current_node->next_node)
        current_node = current_node->next_node;
    
    current_node->next_node = new Node<datatype>;
    current_node->next_node->prev_node = current_node;
    current_node->next_node->symbol = symbol;
    current_node->next_node->next_node = nullptr;
}

template <class datatype>
void DoubleLinkedList<datatype> :: sort()
{
    Node<datatype>* current_node = top_node;
    Node<datatype>* temp = top_node;
    Node<datatype>* min = top_node;
    
    char temp_symbol = '\0';

    while(current_node && current_node->next_node)
    {
        temp = current_node;
        min = current_node;
        
        while(temp)
        {
            if (temp->symbol < min->symbol)
                min = temp;
            temp = temp->next_node;
        }

        temp_symbol = min->symbol;
        min->symbol = current_node->symbol;
        current_node->symbol = temp_symbol;
        
        current_node = current_node->next_node;
    }
}
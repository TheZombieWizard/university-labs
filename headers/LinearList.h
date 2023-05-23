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
        datatype symbol;
        Node* next_node;
    };
    
    Node* top_node;
public:
    LinearList(datatype symbol);
    LinearList();
    ~LinearList();

    LinearList(const LinearList &copying_linear_list);
    LinearList& operator= (const LinearList& copying_linear_list);
    LinearList(LinearList&& moving_linear_list);
    LinearList& operator=(LinearList&& moving_linear_list);

    Node* find(datatype symbol);
    unsigned int count(datatype symbol);
    void print_list();
    Node* first_node();
    void delete_first(datatype symbol);
    void delete_all(datatype symbol);
    void add_node(datatype symbol);
    void add_node();
    void sort();
};
//----------------------------------------------------------------------
//----------------------------------------------------------------------

template <class datatype>
LinearList<datatype> :: LinearList(datatype symbol)
{
    top_node = new Node;
    top_node->symbol = symbol;
    top_node->next_node = nullptr;
}

template<>
LinearList<char> :: LinearList()
{
    srand(time(NULL) + rand() % 666);
    top_node = new Node;
    char symbol;
    if (rand() % 2)
        symbol = char((rand() % 26) + 65);
    else
        symbol = char((rand() % 26) + 97);
    top_node->symbol = symbol;
    top_node->next_node = nullptr;
}

template <class datatype>
LinearList<datatype> :: LinearList()
{
    srand(time(NULL) + rand() % 666);
    top_node = new Node;
    datatype symbol;
    symbol = datatype(rand() % 42) + datatype((rand() % 100) / 100);
    top_node->symbol = symbol;
    top_node->next_node = nullptr;
}

template <class datatype>
LinearList<datatype> :: ~LinearList()
{
    if (top_node)
    {
        Node* temp_next_node = top_node->next_node;
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
LinearList<datatype> :: LinearList(const LinearList<datatype> &copying_vector)
{
    Node* current_node = copying_vector.top_node;
    
    delete top_node;
    top_node = new Node;
    top_node->symbol = current_node->symbol;
    top_node->next_node = nullptr;
    current_node = current_node->next_node;
    
    while (current_node)
    {
        this->add_node(current_node->symbol);
        current_node = current_node->next_node;
    }
}

template <class datatype>
LinearList<datatype>& LinearList<datatype> :: operator= (const LinearList<datatype>& copying_vector)
{   
    Node* current_node = copying_vector.top_node;
    
    delete top_node;
    top_node = new Node;
    top_node->symbol = current_node->symbol;
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
LinearList<datatype> :: LinearList(LinearList<datatype>&& moving_list)
{
    top_node = new Node;
    top_node = moving_list.top_node;
    
    moving_list.top_node = nullptr;
}

template <class datatype>
class LinearList<datatype>& LinearList<datatype> :: operator=(LinearList<datatype>&& moving_list)
{   
    Node* last_node = this->top_node;
    Node* current_node = this->top_node->next_node;
    
    while(last_node)
    {
        last_node->symbol = 0;
        last_node->next_node = nullptr;
        last_node = current_node;
        if (current_node)
            current_node = current_node->next_node;
    }
    
    swap(this->top_node, moving_list.top_node);
    
    return *this;
}

template <class datatype>
class LinearList<datatype> :: Node* LinearList<datatype> :: find(datatype symbol)
{
    Node* current_node = top_node;
    while(current_node)
    {
        if (current_node->symbol == symbol)
            return current_node;
        current_node = current_node->next_node;
    }
    return 0;
}

template <class datatype>
unsigned int LinearList<datatype> :: count(datatype symbol)
{
    Node* current_node = top_node;
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
void LinearList<datatype> :: print_list()
{
    Node* current_node = top_node;
    while (current_node)
    {
        cout << current_node->symbol << " ";
        current_node = current_node->next_node;
    }
    cout << endl;
}

template <class datatype>
class LinearList<datatype> :: Node* LinearList<datatype> :: first_node()
{
    return top_node;
}

template <class datatype>
void LinearList<datatype> :: delete_first(datatype symbol)
{
    Node* last_node = top_node;
    if (top_node->symbol == symbol)
    {
        top_node->symbol = 0;
        top_node = top_node->next_node;
        last_node->next_node = nullptr;
    }
    else
    {
        Node* current_node = top_node->next_node;
        while(current_node)
        {
            if (current_node->symbol == symbol)
            {
                last_node->next_node = current_node->next_node;
                current_node->symbol = 0;
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
void LinearList<datatype> :: delete_all(datatype symbol)
{
    Node* current_node = top_node;
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
void LinearList<datatype> :: add_node(datatype symbol)
{
    Node* current_node = top_node;
    Node* created_node = new Node;
    created_node->symbol = symbol;
    created_node->next_node = nullptr;

    while (current_node->next_node)
        current_node = current_node->next_node;
    current_node->next_node = created_node;
}

template <class datatype>
void LinearList<datatype> :: add_node()
{
    srand(time(NULL) + rand() % 666);
    char symbol;
    if (rand() % 2)
        symbol = char((rand() % 26) + 65);
    else
        symbol = char((rand() % 26) + 97);
    
    Node* current_node = top_node;
    Node* created_node = new Node;
    created_node->symbol = symbol;
    created_node->next_node = nullptr;

    while (current_node->next_node)
        current_node = current_node->next_node;
    current_node->next_node = created_node;
}

template <class datatype>
void LinearList<datatype> :: sort()
{
    Node *current_node = top_node;
    Node *temp = top_node;
    Node *min = top_node;
    
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

template <class datatype>
void LinearList<datatype>::selective_copy(const LinearList &from_list)
{
    *this = from_list;
    Node* current_from_node = from_list.top_node;
    while (current_from_node)
    {
        if (count(current_from_node->symbol) != 2)
            this->delete_all(current_from_node->symbol);
        else
        {
            this->delete_first(current_from_node->symbol);
            current_from_node = current_from_node->next_node;
        }
        current_from_node = current_from_node->next_node;
    }
}
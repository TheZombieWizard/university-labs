#include <iostream>
#include <cstdlib>

using namespace std;


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

    void selective_copy(const LinearList& from_list);
};
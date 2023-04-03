#include <iostream>
#include <cstdlib>

using namespace std;

template <typename datatype>
struct Node
{
    Node* prev_node;
    datatype symbol;
    Node* next_node;
};

template <class datatype>
class DoubleLinkedList
{   
    Node<datatype>* top_node;
public:
    DoubleLinkedList(datatype symbol);
    DoubleLinkedList();
    ~DoubleLinkedList();

    DoubleLinkedList(const DoubleLinkedList &copying_linear_list);
    DoubleLinkedList(DoubleLinkedList&& moving_linear_list);
    DoubleLinkedList& operator= (const DoubleLinkedList& copying_linear_list);
    DoubleLinkedList& operator=(DoubleLinkedList&& moving_linear_list);

    Node<datatype>* find(datatype symbol);
    unsigned int count(datatype symbol);
    void print_list();
    Node<datatype>* first_node();
    void delete_first(datatype symbol);
    void delete_all(datatype symbol);
    void add_node(datatype symbol);
    void add_node();
    void sort();
};
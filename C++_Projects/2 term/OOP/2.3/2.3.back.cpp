#include "2.3.back.h"


template class DoubleLinkedList_2_3<int>;
template class DoubleLinkedList_2_3<float>;
template class DoubleLinkedList_2_3<double>;

template <class datatype>
datatype DoubleLinkedList_2_3<datatype>:: strange_sum()
{
    Node<datatype>* current_node = this->first_node();
    Node<datatype>* first = this->first_node();
    Node<datatype>* last = nullptr;
    datatype sum = 0;
    unsigned int nodes_quantity = 0;

    while (current_node)
    {
        nodes_quantity++;
        last = current_node;
        current_node = current_node->next_node;
    }
    
    int i = 0;
    while (first->next_node)
    {
        sum += first->symbol + first->next_node->symbol + (nodes_quantity - i) * (last->symbol);
        //cout << i << " sum: " << sum << " ~ " << first->symbol << " " << first->next_node->symbol << " " << last->symbol << endl;
        i++;
        last = last->prev_node;
        first = first->next_node;
    }

    return sum;
}
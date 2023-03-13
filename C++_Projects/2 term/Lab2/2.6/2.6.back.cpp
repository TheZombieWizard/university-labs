#include "2.6.back.h"

void create_node(Node *&top)
{
    Node* list_node = new Node;

    list_node->num = (rand() % 42 + 1) + double(rand() % 100) / 100;
    
    list_node->prev_node = NULL;
    list_node->next = NULL;

    if (!top)
		top = list_node;
	else
    {
        Node* previous_node = top;
        while (previous_node->next)
            previous_node = previous_node->next;
		previous_node->next = list_node;
        list_node->prev_node = previous_node;
    }
}

void print_list(Node *top) 
{
    while (top)
    {
        cout << top->num << " ";  
        top = top->next;
    }
    cout << endl;
}

double strange_sum(Node *top, int n) 
{
    Node *first = top;
    Node *last = NULL;
    double sum = 0;

    while (top)
    {
        last = top;
        top = top->next;
    }

    for (int i = 0; first->next; i++)
    {
        sum += first->num + first->next->num + (n - i) * (last->num);
        last = last->prev_node;
        first = first->next;
    }
    
    return sum;
}

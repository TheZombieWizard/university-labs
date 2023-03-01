#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
    Node *prev_node;
    double num;
    Node *next_node;
};

void create_node(Node *&top)
{
    Node* list_node = new Node;

    list_node->num = (rand() % 42 + 1) + double(rand() % 100) / 100;
    
    list_node->prev_node = NULL;
    list_node->next_node = NULL;

    if (!top)
		top = list_node;
	else
    {
        Node* previous_node = top;
        while (previous_node->next_node)
            previous_node = previous_node->next_node;
		previous_node->next_node = list_node;
        list_node->prev_node = previous_node;
    }
}

void print_list(Node *top) 
{
    while (top)
    {
        cout << top->num << " ";  
        top = top->next_node;
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
        top = top->next_node;
    }

    int i = 0;
    while (first->next_node)
    {
        sum += first->num + first->next_node->num + (n - i) * (last->num);
        i++;
        last = last->prev_node;
        first = first->next_node;
    }
    
    return sum;
}

int main()
{
    Node *top = NULL;
    int n = 10;
    
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        create_node(top);
    
    print_list(top);
    cout << "Sum = " << strange_sum(top, n) << endl;

    return 0;
}
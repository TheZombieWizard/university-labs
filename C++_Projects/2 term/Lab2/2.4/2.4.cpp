#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
    char symbol;
    Node *next_node;
};

void create_node_rand(Node *&top)
{
    Node* list_node = new Node;

    bool upper_case = rand() % 2;
        if (upper_case) 
            list_node->symbol = char((rand() % 26) + 65);
        else
            list_node->symbol = char((rand() % 26) + 97);
    
    list_node->next_node = NULL;

    if (!top)
		top = list_node;
	else
    {
        Node* previous_node = top;
        while (previous_node->next_node)
            previous_node = previous_node->next_node;
		previous_node->next_node = list_node;
    }
}

void create_node(Node *&top, char symbol)
{
    Node* list_node = new Node;

    list_node->symbol = symbol;
    
    list_node->next_node = NULL;

    if (!top)
		top = list_node;
	else
    {
        Node* previous_node = top;
        while (previous_node->next_node)
            previous_node = previous_node->next_node;
		previous_node->next_node = list_node;
    }
}

void print_list(Node *top) 
{
    while (top)
    {
        cout << top->symbol << " ";  
        top = top->next_node;
    }
    cout << endl;
}

void create_L2(Node *L1_top, Node *&L2_top) 
{
    char temp_symbol = L1_top->symbol;
    int count = 0;
    
    while (L1_top)
    {
        if (L1_top->symbol == temp_symbol)
            count++;
        else
        {
            if (count == 2)
                create_node(L2_top, temp_symbol);
            count = 1;
            temp_symbol = L1_top->symbol;
        }
        L1_top = L1_top->next_node;
    }
}

void sort(Node *top)
{
    Node *current_node = top;
    Node *temp = top;
    Node *min = top;
    
    char temp_symbol;

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

int main()
{
    Node *L1_top = NULL;
    Node *L2_top = NULL;
    
    srand(time(NULL));
    for (int i = 0; i < 42; i++)
        create_node_rand(L1_top);
    
    sort(L1_top);
    create_L2(L1_top, L2_top);
    
    print_list(L1_top);
    print_list(L2_top);

    return 0;
}
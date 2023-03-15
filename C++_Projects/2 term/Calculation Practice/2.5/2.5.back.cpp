using namespace std;

struct Node
{
    char symbol;
};

void create_node_rand(Node **nodes_array)
{
    Node* node = new Node;

    bool upper_case = rand() % 2;
        if (upper_case) 
            node->symbol = char((rand() % 26) + 65);
        else
            node->symbol = char((rand() % 26) + 97);

    if (!nodes_array[0])
		nodes_array[0] = node;
	else
    {
        int i = 0;
        for (; nodes_array[i]; i++);
		nodes_array[i] = node;
    }
}

void create_node(Node **nodes_array, char symbol)
{
    Node* node = new Node;

    node->symbol = symbol;

    if (!nodes_array[0])
		nodes_array[0] = node;
	else
    {
        int i = 0;
        for (; nodes_array[i]; i++);
		nodes_array[i] = node;
    }
}

void print_list(Node **nodes_array) 
{
    for (int i = 0; **nodes_array[i]; i++)
        cout << **nodes_array[i]->symbol << " ";  
    cout << endl;
}

/**
void create_L2(char **nodes_arrayL1, char *nodes_arrayL2) 
{
    char temp_symbol = nodes_arrayL1->symbol;
    int count = 0;
    
    while (nodes_arrayL1)
    {
        if (nodes_arrayL1->symbol == temp_symbol)
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
/**/
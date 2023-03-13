#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
    Node *prev_node;
    double num;
    Node *next;
};

void create_node(Node *&top);
void print_list(Node *top);
double strange_sum(Node *top, int n);
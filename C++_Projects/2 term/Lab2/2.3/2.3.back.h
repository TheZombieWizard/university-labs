#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Node
{
    Node *prev_node;
    string surname = "";
    string name = "";
    int birth_date = 0;
    int grade = 0;
    float performance = 0;
    Node *next;
};

void create_node(Node *&top);
void print_list(Node *top);
void sort(Node *top);
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
    short grade = 0;
    float performance = 0;
    Node *next;
};


void create_node_rand(Node *&top);

void create_node(Node *&top, string surname, string name, int birth_date, short grade, float performance);

void print_list(Node *top);

void sort(Node *top);

void modify_list(Node *original_list, Node *&modified_list, char desired_letter);
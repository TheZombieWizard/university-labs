#include "2.3.back.h"

void create_node(Node *&top)
{
    Node* student = new Node;

    student->prev_node = NULL;

    student->surname += char((rand() % 26) + 65);
    for (int i = 1; i < 19; i++)
        student->surname += char((rand() % 26) + 97);
    
    student->name += char((rand() % 26) + 65);
    for (int i = 1; i < 19; i++)
        student->name += char((rand() % 26) + 97);
    
    student->birth_date = (rand() % 31 + 1) * 1000000 + (rand() % 12 + 1) * 10000 + (rand() % 10 + 1997);  

    student->grade = rand() % 4 + 1;

    student->performance = float(rand() % 6 + 4) + float(rand() % 10) / 10;

    student->next = NULL;

    if (!top)
		top = student;
    else
    {
        Node *curr_node = top;
        while(curr_node->next)
            curr_node = curr_node->next;
        student->prev_node = curr_node;
	    curr_node->next = student;
    }
}

void print_list(Node *top) 
{
    cout << setw(25) << "Surname" 
            << setw(25) << "Name" 
            << setw(10) << "Grade" 
            << setw(15) << "Performance"
            << setw(15) << "Birth date" << endl;
    while (top)
    {
        cout << setw(25) << top->surname 
            << setw(25) << top->name 
            << setw(10) << top->grade 
            << setw(15) << top->performance 
            << setw(6) << (top->birth_date / 10000000) << (top->birth_date / 1000000) % 10 << "." 
                << (top->birth_date / 100000) % 10 << (top->birth_date / 10000) % 10 << "." 
                << top->birth_date % 10000 << endl;
        top = top->next;
    }
}

void sort(Node *top)
{
    Node *current_node = top;
    Node *temp = top;
    Node *min = top;
    
    string temp_surname = "";
    string temp_name = "";
    int temp_birth_date = 0;
    int temp_grade = 0;
    float temp_performance = 0;

    while(current_node && current_node->next)
    {
        temp = current_node;
        min = current_node;
        
        while(temp)
        {
            if (temp->surname < min->surname)
                min = temp;
            temp = temp->next;
        }

        temp_surname = min->surname;
        temp_name = min->name;
        temp_birth_date = min->birth_date;
        temp_grade = min->grade;
        temp_performance = min->performance;

        min->surname = current_node->surname;
        min->name = current_node->name;
        min->birth_date = current_node->birth_date;
        min->grade = current_node->grade;
        min->performance = current_node->performance;

        current_node->surname = temp_surname;
        current_node->name = temp_name;
        current_node->birth_date = temp_birth_date;
        current_node->grade = temp_grade;
        current_node->performance = temp_performance;

        current_node = current_node->next;
    }
}
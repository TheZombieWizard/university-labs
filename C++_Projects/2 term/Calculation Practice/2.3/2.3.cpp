#include "2.3.back.h"

int main()
{
    Node *original_student_list = NULL;
    
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        create_node_rand(original_student_list);
    
    sort(original_student_list);
    print_list(original_student_list);

    Node *modified_student_list = NULL;
    
    char desired_letter = '\0';
    cout << "Desired student's surname first letter: ";
    cin >> desired_letter;

    modify_list(original_student_list, modified_student_list, desired_letter);

    print_list(original_student_list);
    cout << endl;
    print_list(modified_student_list);

    return 0;
}
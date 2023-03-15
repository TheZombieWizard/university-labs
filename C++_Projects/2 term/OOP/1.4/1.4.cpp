#include "1.4.back.h"

int main()
{
    create_input_file("input.txt", 10);
    cout << endl;
    read_text_file("input.txt");
    
    char desired_first_letter = '\0';
    cout << "Desired student's surname first letter: ";
    cin >> desired_first_letter;

    short desired_grade = 0;
    cout << "Desired student's grade: ";
    cin >> desired_grade;
    
    analyze_students_database("input.txt", "output.txt", desired_grade, desired_first_letter);
    read_text_file("output.txt");
    
    return 0;
}
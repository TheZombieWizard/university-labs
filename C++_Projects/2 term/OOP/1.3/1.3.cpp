#include "1.3.back.h"

int main()
{
    create_input_file("input.bin", 10);
    cout << endl;
    read_binary_file("input.bin");
    
    char desired_first_letter = '\0';
    cout << "Desired student's surname first letter: ";
    cin >> desired_first_letter;

    short desired_grade = 0;
    cout << "Desired student's grade: ";
    cin >> desired_grade;
    
    analyze_students_database("input.bin", "output.bin", desired_grade, desired_first_letter);
    read_binary_file("output.bin");
    
    return 0;
}
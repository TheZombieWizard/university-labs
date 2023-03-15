#include "1.3.back.h"

void create_input_file(string input_path, unsigned int desired_students_quantity)
{
    ofstream input_file(input_path, fstream::binary);
    
    srand(time(NULL));
    for (unsigned int created_students = 0; created_students < desired_students_quantity; created_students++)
    {
        char surname[21] = {'\0'};
        char name[21] = {'\0'};
        int birth_date = 0;
        short grade = 0;
        float performance = 0;

        surname[0] = char((rand() % 26) + 65);
        for (int i = 1; i < 19; i++)
            surname[i] = char((rand() % 26) + 97);

        name[0] = char((rand() % 26) + 65);
        for (int i = 1; i < 19; i++)
            name[i] = char((rand() % 26) + 97);

        birth_date = (rand() % 31 + 1) * 1000000 + (rand() % 12 + 1) * 10000 + (rand() % 10 + 1997);  
        grade = rand() % 4 + 1;
        performance = float(rand() % 6 + 4) + float(rand() % 10) / 10;
        
        cout << setw(25) << surname 
            << setw(25) << name 
            << setw(4) << grade 
            << setw(6) << performance 
            << setw(6) << (birth_date / 10000000) << (birth_date / 1000000) % 10 << "." 
                << (birth_date / 100000) % 10 << (birth_date / 10000) % 10 << "." 
                << birth_date % 10000 << endl;

        input_file.write((char*)&surname, sizeof(surname));
        input_file.write((char*)&name, sizeof(name));
        input_file.write((char*)&birth_date, sizeof(birth_date));
        input_file.write((char*)&grade, sizeof(grade));
        input_file.write((char*)&performance, sizeof(performance));
    }

    input_file.close();
}

void read_binary_file(string input_path)
{
    ifstream binary_file(input_path, fstream::binary);
    
    cout << setw(25) << "Surname" 
            << setw(25) << "Name" 
            << setw(10) << "Grade" 
            << setw(15) << "Performance"
            << setw(15) << "Birth date" << endl;

    while(!binary_file.eof())
    {
        char surname[21] = {'\0'};
        char name[21] = {'\0'};
        int birth_date = 0;
        short grade = 0;
        float performance = 0;
        
        binary_file.read((char*)&surname, sizeof(surname));
        binary_file.read((char*)&name, sizeof(name));
        binary_file.read((char*)&birth_date, sizeof(birth_date));
        binary_file.read((char*)&grade, sizeof(grade));
        binary_file.read((char*)&performance, sizeof(performance));
        

        cout << setw(25) << surname 
            << setw(25) << name 
            << setw(10) << grade 
            << setw(15) << performance 
            << setw(6) << (birth_date / 10000000) << (birth_date / 1000000) % 10 << "." 
                << (birth_date / 100000) % 10 << (birth_date / 10000) % 10 << "." 
                << birth_date % 10000 << endl;
    }

    binary_file.close();
}

void analyze_students_database(string input_path, string output_path, short desired_grade, char desired_first_letter)
{
    ifstream input_file(input_path, fstream::binary);
    ofstream output_file(output_path, fstream::trunc | fstream::binary);

    
    while(!input_file.eof())
    {
        char surname[21] = {'\0'};
        char name[21] = {'\0'};
        int birth_date = 0;
        short grade = 0;
        float performance = 0;
        
        input_file.read((char*)&surname, sizeof(surname));
        input_file.read((char*)&name, sizeof(name));
        input_file.read((char*)&birth_date, sizeof(birth_date));
        input_file.read((char*)&grade, sizeof(grade));
        input_file.read((char*)&performance, sizeof(performance));

        if ((grade == desired_grade) && (
            (surname[0] == desired_first_letter) || (surname[0] == char(desired_first_letter - 32))))
        {
            output_file.write((char*)&surname, sizeof(surname));
            output_file.write((char*)&name, sizeof(name));
            output_file.write((char*)&birth_date, sizeof(birth_date));
            output_file.write((char*)&grade, sizeof(grade));
            output_file.write((char*)&performance, sizeof(performance));;
        }
    }

    input_file.close();
    output_file.close();
}
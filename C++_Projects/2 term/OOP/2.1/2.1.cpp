#include "2.1.back.h"

int main()
{
    Vector vector;
    unsigned int MAX = 1e4;
    int num = 0;

    ifstream input_file("2.1.test.txt");
    while (!input_file.eof())
    {
        input_file >> num;
        vector.extend_length(num + 1);
        vector[num] = 1;
    }
    input_file.close();

    ofstream output_file("2.1.test_ans.txt");
    unsigned int index = 0;
    
    for (; index < vector.length(); index++)
        if (!vector[index])
            output_file << index << " ";
    
    for (; index <= MAX; index++)
        output_file << index << " ";
    output_file.close();
    
    return 0;
}
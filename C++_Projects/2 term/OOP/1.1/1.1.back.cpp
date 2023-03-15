#include "1.1.back.h"

void create_input_file(string input_path, unsigned int desired_num_blocks_quantity)
{
    ofstream input_file(input_path);
    
    srand(time(NULL));
    for (unsigned int num_blocks_quantity = 0; num_blocks_quantity < desired_num_blocks_quantity; num_blocks_quantity++)
    {
        for (int i = 0; i < 5; i++)
            input_file << (rand() % 42) * 2 << " ";
        for (int i = 0; i < 5; i++)
            input_file << (rand() % 42) * 2 + 1 << " ";
        for (int i = 0; i < 5; i++)
            input_file << (rand() % 42) * 2 << " ";
        for (int i = 0; i < 5; i++)
            input_file << (rand() % 42) * 2 + 1 << " ";
        input_file << endl;
    }
    input_file.close();
}

unsigned int get_num_length(int num)
{
    unsigned int num_length = 1;
    for (; (num = num / 10); num_length++);
    return num_length;
}

void sort_nums_evenly(string input_path, string output_path)
{
    ifstream input_file_even_stream(input_path);
    ifstream input_file_odd_stream(input_path);
    ofstream output_file(output_path, fstream::trunc);
    
    for (int i = 0; !input_file_even_stream.eof() && !input_file_odd_stream.eof(); i++)
    {
        int even_num = 0;
        int odd_num = 0;
        
        while(!input_file_even_stream.eof())
        {
            int num = 0;
            input_file_even_stream >> num;
            if (num % 2 == 0)
            {
                even_num = num;
                break;
            }
        }

        while(!input_file_odd_stream.eof())
        {
            int num = 0;
            input_file_odd_stream >> num;
            if (num % 2 != 0)
            {
                odd_num = num;
                break;
            }
        }

        output_file << even_num << " " << odd_num << " ";
        if ((i > 0) && (i % 10 == 0))
            output_file << endl;
    }

    input_file_even_stream.close();
    input_file_odd_stream.close();
    output_file.close();
}
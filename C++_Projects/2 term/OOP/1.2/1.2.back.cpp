#include "1.2.back.h"

void create_input_file(string input_path, unsigned int desired_num_blocks_quantity)
{
    ofstream input_file(input_path, fstream::binary);
    
    srand(time(NULL));
    for (unsigned int num_blocks_quantity = 0; num_blocks_quantity < desired_num_blocks_quantity; num_blocks_quantity++)
    {
        for (int i = 0; i < 5; i++)
        {
            int num = (rand() % 42) * 2;
            cout << num << " ";
            input_file.write((char*)&num, sizeof(num));
        }

        for (int i = 0; i < 5; i++)
        {
            int num = (rand() % 42) * 2 + 1;
            cout << num << " ";
            input_file.write((char*)&num, sizeof(num));
        }

        for (int i = 0; i < 5; i++)
        {
            int num = (rand() % 42) * 2;
            cout << num << " ";
            input_file.write((char*)&num, sizeof(num));
        }

        for (int i = 0; i < 5; i++)
        {
            int num = (rand() % 42) * 2 + 1;
            cout << num << " ";
            input_file.write((char*)&num, sizeof(num));
        }
        cout << endl;
    }
    
    input_file.close();
}

void read_binary_file(string input_path)
{
    ifstream binary_file(input_path, fstream::binary);

    for (int i = 0; !binary_file.eof(); i++)
    {
        int num = 0;
        binary_file.read((char*)&num, sizeof(num));
        cout << num << " ";
        if ((i > 0) && (i % 20 == 0))
            cout << endl;
    }
}

void sort_nums_evenly(string input_path, string output_path)
{
    ifstream input_file_even_stream(input_path, fstream::binary);
    ifstream input_file_odd_stream(input_path, fstream::binary);
    ofstream output_file(output_path, fstream::trunc | fstream::binary);
    
    for (int i = 0; !input_file_even_stream.eof() && !input_file_odd_stream.eof(); i++)
    {
        int even_num = 0;
        int odd_num = 0;
        
        while(!input_file_even_stream.eof())
        {
            int num = 0;
            input_file_even_stream.read((char*)&num, sizeof(num));
            if (num % 2 == 0)
            {
                even_num = num;
                break;
            }
        }

        while(!input_file_odd_stream.eof())
        {
            int num = 0;
            input_file_odd_stream.read((char*)&num, sizeof(num));
            if (num % 2 != 0)
            {
                odd_num = num;
                break;
            }
        }

        output_file.write((char*)&even_num, sizeof(even_num));
        output_file.write((char*)&odd_num, sizeof(odd_num));
    }

    input_file_even_stream.close();
    input_file_odd_stream.close();
    output_file.close();
}
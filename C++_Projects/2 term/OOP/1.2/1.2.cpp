#include "1.2.back.h"

int main()
{
    create_input_file("input.bin", 10);
    
    cout << endl;
    read_binary_file("input.bin");
    
    sort_nums_evenly("input.bin", "output.bin");
    
    cout << endl;
    read_binary_file("output.bin");
    return 0;
}
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


void create_input_file(string input_path, unsigned int desired_num_blocks_quantity);

void read_binary_file(string input_path);

void sort_nums_evenly(string input_path, string output_path);
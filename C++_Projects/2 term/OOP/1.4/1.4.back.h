#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;


void create_input_file(string input_path, unsigned int desired_num_blocks_quantity);

void read_text_file(string input_path);

void analyze_students_database(string input_path, string output_path, short desired_grade, char desired_first_letter);
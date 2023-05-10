#include <iostream>
#include <string>

using namespace std;


int pow(int num, int power);
int str2int(string str_num);

bool comparison_operators_exist(string expression);
bool logical_and_exist(string expression);
bool logical_or_exist(string expression);
bool brackets_exist(string expression);

string reduce_comparison_operations(string expression);
string reduce_logical_and(string expression);
string reduce_logical_or(string expression);
string reduce_brackets(string expression);

int compute_basic_expression(string num1, string operation, string num2);
string compute_advanced_expression(string expression);
string compute_expressions_with_brackets(string expression);
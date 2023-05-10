#include <iostream>
#include <vector>

using namespace std;


void task_2_1();
void task_2_2();

template <typename type>
void find_c(vector<type> arr_A, vector<type> vec_B, int N);

template <typename type>
void find_c(vector< vector<type> > arr_A, vector<type> vec_B, int N);
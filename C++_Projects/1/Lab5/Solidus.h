#include <cstdlib> // содержит srand() и rand()
#include "Solidus.cpp"

using namespace std;

// ------------------------------  Creation (char) -----------------------------------------------
void increasing_creation(char array[], int n);

void decreasing_creation(char array[], int n);

void random_creation(char array[], int n);

// ------------------------------  Creation (template) -----------------------------------------------
template <class type>
void increasing_creation(type array[], int n);

template <class type>
void decreasing_creation(type array[], int n);

template <class type>
void random_creation(type array[], int n);

// ------------------------------  Sort (template) -----------------------------------------------
template <class type>
void quick_sort(type array[], int left, int right);

template <class type>
void sort_select(type array[], int size);

// ------------------------------  Sort comparison (template) -----------------------------------------------
template <class type>
void quick_sort_comparison_func(type array[], int left, int right, int& swaps_amount_ref, int& comparison_amount_ref);

template <class type>
void quick_sort_comparison(type array[], int left, int right);

template <class type>
void sort_select_comparison(type array[], int size);

// ------------------------------  Creation (pointers) -----------------------------------------------
void increasing_creation(int* p_element, int n);

void decreasing_creation(int* p_element, int n);

void random_creation(int* p_element, int n);

// ------------------------------  Output (pointers) -----------------------------------------------
void array_output(int* p_element, int N, int M);

// ------------------------------  Count (pointers) -----------------------------------------------
void count_lines_sums(int* p_element, int N, int M, int count[][2]);

// ------------------------------  Sort (pointers) -----------------------------------------------
void sort_select(int* p_element, int N, int M, int count[][2]);
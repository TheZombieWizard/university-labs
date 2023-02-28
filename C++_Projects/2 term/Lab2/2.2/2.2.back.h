#include <iostream>
#include <cstdlib>
#include "2.2.back.cpp"

template <class type>
void random_creation(type *p_array, int size);

template <class type>
void random_creation(type **p_array, int N);


template <class type>
void array_output(type *p_array, int size);

template <class type>
void array_output(type **p_array, int N);


template <class type>
void find_c(type *arr_A, type vec_B[], int N);

template <class type>
void find_c(type **arr_A, type vec_B[], int N);
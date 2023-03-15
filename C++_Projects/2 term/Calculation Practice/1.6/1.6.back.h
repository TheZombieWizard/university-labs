#include "1.6.back.cpp"

template <class type>
void array_output(type array[], int size);

void increasing_creation(char array[], int n);
void decreasing_creation(char array[], int n);
void random_creation(char array[], int n);

template <class type>
void increasing_creation(type array[], int n);

template <class type>
void decreasing_creation(type array[], int n);

template <class type>
void random_creation(type array[], int n);

template <class type>
void merge(type list[], int start, int end, int mid, int size);

template <class type>
void mergeSort(type list[], int start, int end, int size);
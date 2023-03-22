#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;


class Vector
{
    unsigned int memory_vector_length = 0;
    unsigned int effective_vector_length = 0;
    int* vector_values = new int[memory_vector_length];

public:
    Vector(unsigned int desired_length);

    Vector();
    
    ~ Vector();
    
    Vector(const Vector &copying_vector);

    Vector& operator= (const Vector& copying_vector);

    Vector(Vector&& copying_vector);

    Vector& operator=(Vector&& copying_vector);

    int& operator[] (unsigned int index);
    
    void print_values();
    
    void change_length(unsigned int desired_length);
    
    void extend_length(unsigned int desired_length);

    void fill_random(int left_border, int right_border);
    
    void fill_random();

    unsigned int length();
};
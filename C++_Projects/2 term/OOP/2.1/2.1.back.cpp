#include "2.1.back.h"


Vector :: Vector(unsigned int desired_length)
{
    memory_vector_length = 2;
    while (memory_vector_length < desired_length)
        memory_vector_length *= 2;
    
    effective_vector_length = desired_length;
    
    vector_values = new int[memory_vector_length];

    for (unsigned int i = 0; i < effective_vector_length; i++)
        vector_values[i] = 0;
}

Vector :: Vector() : Vector(13) {}

Vector :: ~ Vector()
{
    delete [] vector_values;
    memory_vector_length = 0;
    effective_vector_length = 0;
}

Vector :: Vector(const Vector &copying_vector)
{
    memory_vector_length = copying_vector.memory_vector_length;
    effective_vector_length = copying_vector.effective_vector_length;
    vector_values = copying_vector.vector_values;
}

Vector& Vector:: operator= (const Vector& copying_vector)
{   
    this->change_length(copying_vector.effective_vector_length);
    
    for (unsigned int index = 0; index < copying_vector.effective_vector_length; index++)
        vector_values[index] = copying_vector.vector_values[index];
    
    return *this;  
}

Vector :: Vector(Vector&& copying_vector)
{
    memory_vector_length = copying_vector.memory_vector_length;
    effective_vector_length = copying_vector.effective_vector_length;
    
    vector_values = copying_vector.vector_values;
    delete []copying_vector.vector_values;
    
    copying_vector.memory_vector_length = 0;
    copying_vector.effective_vector_length = 0;
}

Vector& Vector :: operator=(Vector&& copying_vector)
{   
    memory_vector_length = copying_vector.memory_vector_length;
    effective_vector_length = copying_vector.effective_vector_length;
    
    vector_values = copying_vector.vector_values;
    delete []copying_vector.vector_values;
    
    copying_vector.memory_vector_length = 0;
    copying_vector.effective_vector_length = 0;
    
    return *this;
}

int& Vector :: operator [](unsigned int index)
{
    if (index > effective_vector_length - 1)
        throw out_of_range("Exceeded the borders of vector");
    return *(vector_values + index);
}

void Vector :: print_values()
{
    for (int* index = vector_values; (index - vector_values) < effective_vector_length; index++)
        cout << *index << " ";
    cout << endl;
}

void Vector :: change_length(unsigned int desired_length)
{
    if (desired_length <= memory_vector_length)
        effective_vector_length = desired_length;
    else
    {
        while (memory_vector_length < desired_length)
            memory_vector_length *= 2;

        int* new_vector_values = new int[memory_vector_length];
        unsigned int index = 0;
        for (; index < effective_vector_length; index++)
            new_vector_values[index] = vector_values[index];
        for (; index < desired_length; index++)
            new_vector_values[index] = 0;
        
        vector_values = new_vector_values;
        effective_vector_length = desired_length;
    }   
}

void Vector :: extend_length(unsigned int desired_length)
{
    if (desired_length > memory_vector_length)
    {
        while (memory_vector_length < desired_length)
            memory_vector_length *= 2;

        int* new_vector_values = new int[memory_vector_length];
        unsigned int index = 0;
        for (; index < effective_vector_length; index++)
            new_vector_values[index] = vector_values[index];
        for (; index < desired_length; index++)
            new_vector_values[index] = 0;
        vector_values = new_vector_values;
        effective_vector_length = desired_length;
    }
}

void Vector:: fill_random(int left_border, int right_border)
{
    srand(time(NULL));
    for (unsigned int index = 0; index < effective_vector_length; index++)
        vector_values[index] = rand() % right_border + left_border;
}

void Vector:: fill_random() { this->fill_random(0, 42); }

unsigned int Vector :: length()
{
    return effective_vector_length;
}
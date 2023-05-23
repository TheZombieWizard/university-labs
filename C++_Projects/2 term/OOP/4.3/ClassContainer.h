#include <vector>
#include <iostream>

using namespace std;


template <class Type>
class ClassContainer
{
protected:
    vector<Type*> container;
public:
    ClassContainer(Type** class_array, int size)
    {
        for (int i = 0; i < size; ++i)
            container.push_back(class_array[i]);
    }

    ClassContainer(Type* class_object)
    {
        container.push_back(class_object);
    }
    ClassContainer(){}
    ~ClassContainer(){}

    void push_back(Type* class_object)
    {
        container.push_back(class_object);
    }

    Type& pop_back()
    {
        if (!container.size())
            throw out_of_range("The container is empty.");
        Type* object_pointer = container[container.size() - 1];
        container.pop_back();
        return *object_pointer;
    }

    Type& operator[](int index)
    {
        if ((index > container.size() - 1) || (index < 0))
            throw out_of_range("Exceded the borders of container.");
        return *(container[index]);
    }

    friend ostream& operator<<(ostream& out, const ClassContainer& self)
    {
        for (int i = 0; i < self.container.size(); ++i)
            out << (*self.container[i]) << endl;
        return out;
    }
};
#include "ClassContainer.h"
#include "RPG.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


int pow(int num, int power)
{
    int powered_num = 1;
    for (int i = 0; i < power; ++i)
        powered_num *= num;
    return powered_num;
}

int str2int(string str_num)
{
    int int_num = 0;

    for (int i = str_num.size() - 1, q = 0; i >= 0; --i, ++q)
    {
        int_num += (int(str_num[i]) - 48) * pow(10, q);
    }
    
    return int_num;
}

unsigned int str2unsint(string str_num)
{
    unsigned int int_num = 0;

    for (int i = str_num.size() - 1, q = 0; i >= 0; --i, ++q)
    {
        int_num += (int(str_num[i]) - 48) * pow(10, q);
    }
    
    return int_num;
}

double str2double(string str_num)
{
    double double_num = 0;

    int i = str_num.size() - 1;
    
    for (; (i >= 0) && (str_num[i] != '.'); --i);
    --i;

    for (int q = 0; i >= 0; --i, ++q)
    {
        double_num += (int(str_num[i]) - 48) * pow(10, q);
    }
    
    i = 0;
    for (; (i < str_num.size() - 1) && (str_num[i] != '.'); ++i);
    ++i;

    for (int q = 0; i < str_num.size(); ++i, ++q)
    {
        double_num += double(int(str_num[i]) - 48) / pow(10, q+1);
    }
    
    return double_num;
}

bool str2bool(string str)
{
    if (str == "1" || str == "true")
        return true;
    return false;
}

template <class Type>
class RPGClassContainer : public ClassContainer<Type>
{
protected:
    vector<Entity> entity_container;
    vector<DynamicObject> dynamicobject_container;
    vector<StaticObject> staticobject_container;
    vector<Asteroid> asteroid_container;
    vector<SpaceShip> spaceship_container;
    vector<Rocket> rocket_container;
    string file_path;
public:
    RPGClassContainer(string input_file_path)
    {
        file_path = input_file_path;
        ifstream input_file(input_file_path);
        while (!input_file.eof())
        {
            string element = "";
            input_file >> element >> element;
            if (element == "Entity")
            {
                Entity entity_object;
                
                input_file >> element;
                input_file >> element;
                entity_object.self_id = str2int(element);
                
                entity_container.push_back(entity_object);
                this->container.push_back(&entity_container[entity_container.size() - 1]);
            }
            else if (element == "DynamicObject")
            {
                DynamicObject dynamicobject_object;

                input_file >> element;
                input_file >> element;
                dynamicobject_object.self_id = str2int(element);

                input_file >> element;
                input_file >> element;
                
                dynamicobject_object.coordx = str2double(element);
                input_file >> element;
                dynamicobject_object.coordy = str2double(element);
                input_file >> element;
                dynamicobject_object.coordz = str2double(element);
                
                input_file >> element;
                input_file >> element;
                dynamicobject_object.speedx = str2double(element);
                input_file >> element;
                dynamicobject_object.speedy = str2double(element);
                input_file >> element;
                dynamicobject_object.speedz = str2double(element);

                dynamicobject_container.push_back(dynamicobject_object);
                this->container.push_back(&dynamicobject_container[dynamicobject_container.size() - 1]);
            }
            else if (element == "StaticObject")
            {
                StaticObject staticobject_object;

                input_file >> element;
                input_file >> element;
                staticobject_object.self_id = str2int(element);
                
                input_file >> element;
                input_file >> element;
                staticobject_object.name = element;
                
                input_file >> element;
                input_file >> element;
                staticobject_object.temperature = str2double(element);
                
                input_file >> element;
                input_file >> element;
                staticobject_object.landing_capability = str2bool(element);

                staticobject_container.push_back(staticobject_object);
                this->container.push_back(&staticobject_container[staticobject_container.size() - 1]);
            }
            else if (element == "Asteroid")
            {
                Asteroid asteroid_object;

                input_file >> element;
                input_file >> element;
                asteroid_object.self_id = str2int(element);
                
                input_file >> element;
                input_file >> element;
                asteroid_object.coordx = str2double(element);
                input_file >> element;
                asteroid_object.coordy = str2double(element);
                input_file >> element;
                asteroid_object.coordz = str2double(element);
                
                input_file >> element;
                input_file >> element;
                asteroid_object.speedx = str2double(element);
                input_file >> element;
                asteroid_object.speedy = str2double(element);
                input_file >> element;
                asteroid_object.speedz = str2double(element);
                
                input_file >> element;
                input_file >> element;
                asteroid_object.maxsize = str2double(element);

                asteroid_container.push_back(asteroid_object);
                this->container.push_back(&asteroid_container[asteroid_container.size() - 1]);
            }
            else if (element == "SpaceShip")
            {
                SpaceShip spaceship_object;

                input_file >> element;
                input_file >> element;
                spaceship_object.self_id = str2int(element);
                
                input_file >> element;
                input_file >> element;
                spaceship_object.name = element;
                
                input_file >> element;
                input_file >> element;
                spaceship_object.coordx = str2double(element);
                input_file >> element;
                spaceship_object.coordy = str2double(element);
                input_file >> element;
                spaceship_object.coordz = str2double(element);
                
                input_file >> element;
                input_file >> element;
                spaceship_object.speedx = str2double(element);
                input_file >> element;
                spaceship_object.speedy = str2double(element);
                input_file >> element;
                spaceship_object.speedz = str2double(element);
                
                input_file >> element;
                input_file >> element;
                spaceship_object.maxvelocity = str2double(element);

                input_file >> element;
                input_file >> element;
                spaceship_object.ammunition = str2int(element);

                spaceship_container.push_back(spaceship_object);
                this->container.push_back(&spaceship_container[spaceship_container.size() - 1]);
            }
            else if (element == "Rocket")
            {
                Rocket rocket_object;

                input_file >> element;
                input_file >> element;
                rocket_object.self_id = str2int(element);
                
                input_file >> element;
                input_file >> element;
                rocket_object.coordx = str2double(element);
                input_file >> element;
                rocket_object.coordy = str2double(element);
                input_file >> element;
                rocket_object.coordz = str2double(element);
                
                input_file >> element;
                input_file >> element;
                rocket_object.speedx = str2double(element);
                input_file >> element;
                rocket_object.speedy = str2double(element);
                input_file >> element;
                rocket_object.speedz = str2double(element);
                
                input_file >> element;
                input_file >> element;
                rocket_object.power = str2double(element);
                
                input_file >> element;
                input_file >> element;
                rocket_object.lifetime = str2double(element);

                rocket_container.push_back(rocket_object);
                this->container.push_back(&rocket_container[rocket_container.size() - 1]);
            }
        }
        input_file.close();
    }

    ~RPGClassContainer()
    {
        ofstream output_file(file_path);
        
        for (int i = 0; i < this->container.size(); ++i)
            output_file << (*this->container[i]) << endl;
        
        output_file.close();
    }
};
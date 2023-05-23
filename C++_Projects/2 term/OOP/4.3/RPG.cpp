#include "RPG.h"

Entity :: Entity()
{
    self_id = id++;
}

DynamicObject :: DynamicObject(
    double desired_coordx, 
    double desired_coordy, 
    double desired_coordz,
    double desired_speedx, 
    double desired_speedy,
    double desired_speedz) 
{
    speedx = desired_speedx;
    speedy = desired_speedy;
    speedz = desired_speedz;
    coordx = desired_coordx;
    coordy = desired_coordy;
    coordz = desired_coordz;
}

DynamicObject :: DynamicObject()
{
    speedx = 0;
    speedy = 0;
    speedz = 0;
    coordx = rand() % 1000 + double(rand() % 100) / 100;
    coordy = rand() % 1000 + double(rand() % 100) / 100;
    coordz = rand() % 1000 + double(rand() % 100) / 100;
}

void DynamicObject :: move_object(
    double desired_coordx, 
    double desired_coordy, 
    double desired_coordz)
{
    coordx = desired_coordx;
    coordy = desired_coordy;
    coordz = desired_coordz;
}

StaticObject :: StaticObject(
    string desired_name, 
    double desired_temperature, 
    bool desired_landing_capability)
{
    name = desired_name;
    temperature = desired_temperature;
    landing_capability = desired_landing_capability;
}

StaticObject :: StaticObject()
{
    for (int i = 0; i < 7; ++i)
    {
        if (rand() % 2)
            name += char(rand() % 26 + 65);
        else
            name += char(rand() % 10 + 48);
    }

    temperature = rand() % 10000 + double(rand() % 100) / 100;

    landing_capability = rand() % 2;
}

Asteroid :: Asteroid(double desired_maxsize)
{
    maxsize = desired_maxsize;
}

Asteroid :: Asteroid()
{
    maxsize = 20 + rand() % 980 + double(rand() % 100) / 100;
}

Rocket :: Rocket(double desired_power, double desired_lifetime)
{
    power = desired_power;
    lifetime = desired_lifetime;
    if (lifetime <= 0)
        lifetime = 0;
}

Rocket :: Rocket()
{
    power = 1 + rand() % 10 + double(rand() % 100) / 100;
    lifetime = 30 + rand() % 50 + double(rand() % 100) / 100;
}

SpaceShip :: SpaceShip(
    string desired_name, 
    double desired_maxvelocity, 
    unsigned int desired_ammunition)
{
    name = desired_name;
    maxvelocity = desired_maxvelocity;
    ammunition = desired_ammunition;
}

SpaceShip :: SpaceShip()
{
    for (int i = 0; i < 7; ++i)
    {
        if (rand() % 2)
            name += char(rand() % 26 + 65);
        else
            name += char(rand() % 10 + 48);
    }

    maxvelocity = 20 + rand() % 50 + double(rand() % 100) / 100;

    ammunition = rand() % 43;
}

Rocket SpaceShip :: fire_rocket()
{
    Rocket new_rocket;
    new_rocket.move_object(coordx, coordy, coordz);
    return new_rocket;
}
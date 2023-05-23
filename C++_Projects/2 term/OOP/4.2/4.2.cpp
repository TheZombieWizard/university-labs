#include "4.2.h"

int main()
{
    srand(time(NULL));

    Entity entity_test;
    DynamicObject dynamicobject_test;
    StaticObject staticobject_test;
    Asteroid asteroid_test;
    SpaceShip spaceship_test;

    //Entity** class_array = new Entity*[5]{&entity_test, &dynamicobject_test, 
    //                    &staticobject_test, &asteroid_test, &spaceship_test};
    ClassContainer<Entity> classcontainer_test(&asteroid_test);
    cout << classcontainer_test;

    return 0;
}
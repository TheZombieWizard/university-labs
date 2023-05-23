#include "RPG.h"


int main()
{
    srand(time(NULL));

    Entity entity_test;
    cout << entity_test << endl;

    DynamicObject dynamicobject_test;
    cout << dynamicobject_test << endl;

    StaticObject staticobject_test;
    cout << staticobject_test << endl;

    Asteroid asteroid_test;
    cout << asteroid_test << endl;

    SpaceShip spaceship_test;
    cout << spaceship_test << endl;
    
    cout << spaceship_test.fire_rocket() << endl;

    return 0;
}
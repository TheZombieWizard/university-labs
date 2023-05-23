#include "4.3.h"

int main()
{
    srand(time(NULL));

    /*
    Entity entity_test;
    DynamicObject dynamicobject_test;
    StaticObject staticobject_test;
    Asteroid asteroid_test;
    SpaceShip spaceship_test;
    Rocket rocket_test = spaceship_test.fire_rocket();
    */
    
    RPGClassContainer<Entity> classcontainer_test("save_file.txt");
    
    /*
    classcontainer_test.push_back(&entity_test);
    classcontainer_test.push_back(&dynamicobject_test);
    classcontainer_test.push_back(&staticobject_test);
    classcontainer_test.push_back(&asteroid_test);
    classcontainer_test.push_back(&spaceship_test);
    classcontainer_test.push_back(&rocket_test);
    */
   
    cout << classcontainer_test;

    return 0;
}
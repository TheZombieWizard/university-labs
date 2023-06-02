#include "LinearList.h"
#include "RPG.h"

int main()
{

    Entity entity_test;
    DynamicObject dynamicobject_test;
    StaticObject staticobject_test;
    Asteroid asteroid_test;
    SpaceShip spaceship_test;

    LinearList<Entity> objects_list;
    
    objects_list.push_back(&entity_test);
    objects_list.push_back(&dynamicobject_test);
    objects_list.push_back(&staticobject_test);
    objects_list.push_back(&asteroid_test);
    objects_list.push_back(&spaceship_test);
    
    objects_list.print();

    cout << "!!!!!!!!!!!s!!!!!!" << endl << endl;

    //objects_list.pop_back();

    //LinearList<Entity> obj(objects_list);
    
    LinearList<Entity> obj; 
    obj = move(objects_list);
    //obj = objects_list;

    //objects_list.~LinearList();

    obj.print(); 
    objects_list.print();

    return 0;
}
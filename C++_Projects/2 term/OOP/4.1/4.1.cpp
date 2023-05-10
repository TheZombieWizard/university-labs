#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class Entity
{
protected:
    static inline unsigned int id{};
    unsigned int self_id;
public:
    Entity()
    {
        self_id = id++;
    }

    virtual void input(istream& in) {}

    virtual void print(ostream& out) const
	{
		out << "Type: " << get_type() << endl;
		out << "id: " << self_id << endl;
	}

    virtual const char* get_type() const
	{
		return "Entity";
	}

	friend istream& operator>>(istream& in, Entity& self)
	{
		self.input(in);
		return in;
	}
	
    friend ostream& operator<<(ostream& out, const Entity& self)
	{
		self.print(out);
		return out;
	}
};

class DynamicObject : public Entity
{
protected:
    double speedx;
    double speedy;
    double speedz;
    double coordx;
    double coordy;
    double coordz;
public:
    DynamicObject(
        double desired_speedx, 
        double desired_speedy,
        double desired_speedz, 
        double desired_coordx, 
        double desired_coordy, 
        double desired_coordz)
    {
        speedx = desired_speedx;
        speedy = desired_speedy;
        speedz = desired_speedz;
        coordx = desired_coordx;
        coordy = desired_coordy;
        coordz = desired_coordz;
    }

    DynamicObject()
    {
        speedx = rand() % 100 + double(rand() % 100) / 100;
        speedy = rand() % 100 + double(rand() % 100) / 100;
        speedz = rand() % 100 + double(rand() % 100) / 100;
        coordx = rand() % 1000 + double(rand() % 100) / 100;
        coordy = rand() % 1000 + double(rand() % 100) / 100;
        coordz = rand() % 1000 + double(rand() % 100) / 100;
    }

    virtual void input(istream& in) 
    {
        cout << "Coordinates: ";
        in >> coordx >> coordy >> coordz;
        cout << "Velocity: ";
        in >> speedx >> speedy >> speedz;
    }
    
    virtual void print(ostream& out) const
	{
		out << "Type: " << get_type() << endl;
		out << "id: " << self_id << endl;
        out << "Coordinates: (" << coordx << ", " << coordy << ", " << coordz << ")" << endl;
        out << "Velocity: (" << speedx << ", " << speedy << ", " << speedz << ")" << endl;
	}

    virtual const char* get_type() const
	{
		return "DynamicObject";
	}
};

class StaticObject : public Entity
{
protected:
    string name;
    double temperature;
    bool landing_capability;
public:
    StaticObject(
        string desired_name, 
        double desired_temperature, 
        bool desired_landing_capability)
    {
        name = desired_name;
        temperature = desired_temperature;
        landing_capability = desired_landing_capability;
    }

    StaticObject()
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

    virtual void input(istream& in) 
    {
        cout << "Name: ";
        in >> name;
        cout << "Temperature: ";
        in >> temperature;
        cout << "Suited for landing (0 or 1): ";
        in >> landing_capability;
    }
    
    virtual void print(ostream& out) const
	{
		out << "Type: " << get_type() << endl;
		out << "id: " << self_id << endl;
        out << "Name: " << name << endl;
        out << "Temperature: " << temperature << endl;
        out << "Suited for landing: " << landing_capability << endl;
	}

    virtual const char* get_type() const
	{
		return "StaticObject";
	}
};

class Asteroid : public DynamicObject
{
protected:
    double maxsize;
public:
    Asteroid(double desired_maxsize)
    {
        maxsize = desired_maxsize;
    }

    Asteroid()
    {
        maxsize = 20 + rand() % 980 + double(rand() % 100) / 100;
    }

    virtual void input(istream& in) 
    {
        cout << "Coordinates: ";
        in >> coordx >> coordy >> coordz;
        cout << "Velocity: ";
        in >> speedx >> speedy >> speedz;
        cout << "Maximum cross-sectional size: ";
        in >> maxsize;
    }
    
    virtual void print(ostream& out) const
	{
		out << "Type: " << get_type() << endl;
		out << "id: " << self_id << endl;
        out << "Coordinates: (" << coordx << ", " << coordy << ", " << coordz << ")" << endl;
        out << "Velocity: (" << speedx << ", " << speedy << ", " << speedz << ")" << endl;
        out << "Maximum cross-sectional size: " << maxsize << endl;
	}

    virtual const char* get_type() const
	{
		return "Asteroid";
	}
};

class Rocket : public DynamicObject
{
protected:
    double power;
    double lifetime;
public:
    Rocket(double desired_power, double desired_lifetime)
    {
        power = desired_power;
        lifetime = desired_lifetime;
    }
    
    Rocket()
    {
        power = 1 + rand() % 10 + double(rand() % 100) / 100;
        lifetime = 30 + rand() % 50 + double(rand() % 100) / 100;
    }

    virtual void input(istream& in) 
    {
        cout << "Coordinates: ";
        in >> coordx >> coordy >> coordz;
        cout << "Velocity: ";
        in >> speedx >> speedy >> speedz;
        cout << "Power: ";
        in >> power;
        cout << "Lifetime: ";
        in >> lifetime;
    }
    
    virtual void print(ostream& out) const
	{
		out << "Type: " << get_type() << endl;
		out << "id: " << self_id << endl;
        out << "Coordinates: (" << coordx << ", " << coordy << ", " << coordz << ")" << endl;
        out << "Velocity: (" << speedx << ", " << speedy << ", " << speedz << ")" << endl;
        out << "Power: " << power << endl;
        out << "Lifetime: " << lifetime << endl;
	}

    virtual const char* get_type() const
	{
		return "Rocket";
	}
};

int main()
{
    Entity entity_test;
    cout << entity_test;
    cout << endl;

    DynamicObject dynamicobject_test;
    cout << dynamicobject_test;
    cout << endl;

    StaticObject staticobject_test;
    cout << staticobject_test;
    cout << endl;

    Asteroid asteroid_test;
    cout << asteroid_test;
    cout << endl;

    return 0;
}
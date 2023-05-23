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
    Entity();

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
        double desired_coordx, 
        double desired_coordy, 
        double desired_coordz,
        double desired_speedx, 
        double desired_speedy,
        double desired_speedz);
    DynamicObject();

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

    void move_object(
        double desired_coordx, 
        double desired_coordy, 
        double desired_coordz);

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
        bool desired_landing_capability);
    StaticObject();

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
    Asteroid(double desired_maxsize);
    Asteroid();

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
    Rocket(double desired_power, double desired_lifetime);
    Rocket();

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

class SpaceShip : public DynamicObject
{
protected:
    string name;
    double maxvelocity;
    unsigned int ammunition;
public:
    SpaceShip(
        string desired_name, 
        double desired_maxvelocity, 
        unsigned int desired_ammunition);
    SpaceShip();

    virtual void input(istream& in) 
    {
        cout << "Coordinates: ";
        in >> coordx >> coordy >> coordz;
        cout << "Velocity: ";
        in >> speedx >> speedy >> speedz;
        cout << "Name: ";
        in >> name;
        cout << "Maximum velocity: ";
        in >> maxvelocity;
        cout << "Ammunition amount: ";
        in >> ammunition;
    }
    
    virtual void print(ostream& out) const
	{
		out << "Type: " << get_type() << endl;
		out << "id: " << self_id << endl;
        out << "Name: " << name << endl;
        out << "Coordinates: (" << coordx << ", " << coordy << ", " << coordz << ")" << endl;
        out << "Velocity: (" << speedx << ", " << speedy << ", " << speedz << ")" << endl;
        out << "Maximum velocity: " << maxvelocity << endl;
        out << "Ammunition amount: " << ammunition << endl;
	}

    Rocket fire_rocket();

    virtual const char* get_type() const
	{
		return "SpaceShip";
	}
};
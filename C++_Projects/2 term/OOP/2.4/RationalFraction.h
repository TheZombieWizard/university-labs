#include <iostream>

using namespace std;


class RationalFraction
{
    int numerator;
    unsigned int denominator;
public:
    RationalFraction(int desired_numerator, unsigned int desired_denominator);
    RationalFraction();
    ~RationalFraction();
    
    RationalFraction(const RationalFraction &copying_rational_fraction);
    RationalFraction& operator= (const RationalFraction& copying_rational_fraction);
    RationalFraction(RationalFraction&& moving_rational_fraction);
    RationalFraction& operator=(RationalFraction&& moving_rational_fraction);

    RationalFraction operator+(const RationalFraction& fraction);
    RationalFraction operator-(const RationalFraction& fraction);
    RationalFraction operator*(const RationalFraction& fraction);
    RationalFraction operator/(const RationalFraction& fraction);
    void operator+=(const RationalFraction& fraction);
    void operator-=(const RationalFraction& fraction);
    void operator*=(const RationalFraction& fraction);
    void operator/=(const RationalFraction& fraction);

    bool operator==(const RationalFraction& fraction);
    bool operator>=(const RationalFraction& fraction);
    bool operator<=(const RationalFraction& fraction);
    bool operator>(const RationalFraction& fraction);
    bool operator<(const RationalFraction& fraction);
    
    friend ostream& operator<<(ostream& str, RationalFraction returning_fraction)
    {
        return str << returning_fraction.numerator << "/" << returning_fraction.denominator;
    }
    
    friend istream& operator>>(istream& str, RationalFraction& fraction) 
	{
        int numerator = 0;
        unsigned int denominator = 0;
        str >> numerator >> denominator; 
		fraction = RationalFraction(numerator, denominator); 
		return str; 
	}

    void reduce2nonreducable();
};
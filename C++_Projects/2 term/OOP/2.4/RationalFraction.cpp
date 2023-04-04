#include "RationalFraction.h"


RationalFraction:: RationalFraction(int desired_numerator, unsigned int desired_denominator)
{
    if (!desired_denominator)
    {
        cout << "You can't divide by zero" << endl;
        throw ("Zero division");
    }
    numerator = desired_numerator;
    denominator = desired_denominator;
}

RationalFraction:: RationalFraction() : RationalFraction(1, 3){}

RationalFraction:: ~RationalFraction()
{
    numerator = 0;
    denominator = 0;
}

RationalFraction:: RationalFraction(const RationalFraction &copying_rational_fraction)
{
    numerator = copying_rational_fraction.numerator;
    denominator = copying_rational_fraction.denominator;
}

RationalFraction& RationalFraction:: operator= (const RationalFraction& copying_rational_fraction)
{
    this->numerator = copying_rational_fraction.numerator;
    this->denominator = copying_rational_fraction.denominator;

    return *this;
}

RationalFraction:: RationalFraction(RationalFraction&& moving_rational_fraction)
{
    numerator = moving_rational_fraction.numerator;
    denominator = moving_rational_fraction.denominator;
    moving_rational_fraction.numerator = 0;
    moving_rational_fraction.denominator = 1;
}

RationalFraction& RationalFraction:: operator=(RationalFraction&& moving_rational_fraction)
{
    this->numerator = moving_rational_fraction.numerator;
    this->denominator = moving_rational_fraction.denominator;
    moving_rational_fraction.numerator = 0;
    moving_rational_fraction.denominator = 1;

    return *this;
}

RationalFraction RationalFraction:: operator+(const RationalFraction& fraction)
{
    return RationalFraction(
        this->numerator * fraction.denominator + 
        fraction.numerator * this->denominator,
        this->denominator * fraction.denominator);
}

RationalFraction RationalFraction:: operator-(const RationalFraction& fraction)
{
    return RationalFraction(
        this->numerator * fraction.denominator - 
        fraction.numerator * this->denominator,
        this->denominator * fraction.denominator);
}

RationalFraction RationalFraction:: operator*(const RationalFraction& fraction)
{
    return RationalFraction(
        this->numerator * fraction.numerator,
        this->denominator * fraction.denominator);
}

RationalFraction RationalFraction:: operator/(const RationalFraction& fraction)
{
    return RationalFraction(
        this->numerator * fraction.denominator,
        this->denominator * fraction.numerator);
}

void RationalFraction:: operator+=(const RationalFraction& fraction)
{
    this->numerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
    this->denominator = this->denominator * fraction.denominator;
}

void RationalFraction:: operator-=(const RationalFraction& fraction)
{
    this->numerator = this->numerator * fraction.denominator - fraction.numerator * this->denominator;
    this->denominator = this->denominator * fraction.denominator;
}

void RationalFraction:: operator*=(const RationalFraction& fraction)
{
    this->numerator = this->numerator * fraction.numerator;
    this->denominator = this->denominator * fraction.denominator;
}

void RationalFraction:: operator/=(const RationalFraction& fraction)
{
    this->numerator = this->numerator * fraction.denominator;
    this->denominator = this->denominator * fraction.numerator;
}

bool RationalFraction:: operator==(const RationalFraction& fraction)
{
    return ((this->numerator * fraction.denominator) == (this->denominator * fraction.numerator));
}

bool RationalFraction:: operator>=(const RationalFraction& fraction)
{
    return ((this->numerator * fraction.denominator) >= (this->denominator * fraction.numerator));
}

bool RationalFraction:: operator<=(const RationalFraction& fraction)
{
    return ((this->numerator * fraction.denominator) <= (this->denominator * fraction.numerator));
}

bool RationalFraction:: operator>(const RationalFraction& fraction)
{
    return ((this->numerator * fraction.denominator) > (this->denominator * fraction.numerator));
}

bool RationalFraction:: operator<(const RationalFraction& fraction)
{
    return ((this->numerator * fraction.denominator) < (this->denominator * fraction.numerator));
}

void RationalFraction:: print(char fraction_part)
{
    if (fraction_part == 'n')
        cout << this->numerator << " ";
    else if (fraction_part == 'd')
        cout << this->denominator << " ";
}

void RationalFraction:: reduce2nonreducable()
{
    for(int i = 2; (i <= numerator) && (i <= denominator); i++)
        if ((numerator % i == 0) && (denominator % i == 0))
        {
            numerator = numerator / i;
            denominator = denominator / i;
            i = 1;
        }
}
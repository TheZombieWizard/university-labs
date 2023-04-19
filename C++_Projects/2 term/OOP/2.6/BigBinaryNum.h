#include <iostream>
#include <iomanip>

using namespace std;


class BigBinaryNum
{
    unsigned int size;
    bool* number;
public:
    BigBinaryNum(string desired_number);
    BigBinaryNum();
    ~BigBinaryNum();

    BigBinaryNum(const BigBinaryNum &copying_bignum);
    BigBinaryNum(BigBinaryNum&& moving_bignum);
    BigBinaryNum& operator=(const BigBinaryNum& copying_bignum);
    BigBinaryNum& operator=(BigBinaryNum&& moving_bignum);

    bool& operator[](unsigned int index);
    BigBinaryNum operator-(const BigBinaryNum& bignum);
    int operator/(const BigBinaryNum& bignum);
    BigBinaryNum operator%(const BigBinaryNum& bignum);
    bool operator>(const BigBinaryNum& bignum);
    void operator>(int offset);
    void operator<(int offset);

    char* bin2dec();
    void resize(int desired_size);

    friend ostream& operator<<(ostream& str, BigBinaryNum bigbin)
    {
        for (int i = bigbin.size - 1; i >= 0; --i)
            str << bigbin.number[i];
        return str;
    }

    friend istream& operator>>(istream& str, BigBinaryNum& bigbin) 
	{
        string desired_number = "";
        str >> desired_number;
		bigbin = BigBinaryNum(desired_number); 
		return str;
	}
};
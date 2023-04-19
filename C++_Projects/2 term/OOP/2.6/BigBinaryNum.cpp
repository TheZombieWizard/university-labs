#include "BigBinaryNum.h"

BigBinaryNum:: BigBinaryNum(string desired_number)
{
    unsigned int desired_size = desired_number.length();
    size = desired_size;
    number = new bool[256];
    
    unsigned int i = 0;
    for (; i < size; ++i)
        number[i] = desired_number[size - 1 - i] % 2;
    for (; i < 256; ++i)
        number[i] = 0;
}

BigBinaryNum:: BigBinaryNum()
{
    size = 1;
    number = new bool[256];
    
    for (unsigned int i = 0; i < 256; ++i)
        number[i] = 0;
}

BigBinaryNum:: ~BigBinaryNum(){}

BigBinaryNum:: BigBinaryNum(const BigBinaryNum &copying_bignum)
{
    if (copying_bignum.number)
    {
        size = copying_bignum.size;
        number = new bool[256];
        for (int i = 0; i < 256; ++i)
            number[i] = copying_bignum.number[i];
    }
}

BigBinaryNum:: BigBinaryNum(BigBinaryNum&& moving_bignum)
{
    size = moving_bignum.size;
    number = moving_bignum.number;
    moving_bignum.number = nullptr;
    moving_bignum.size = 0;
}

BigBinaryNum& BigBinaryNum:: operator=(const BigBinaryNum& copying_bignum)
{
    if (copying_bignum.number)
    {
        size = copying_bignum.size;
        for (int i = 0; i < 256; ++i)
            number[i] = copying_bignum.number[i];
    }

    return *this;
}

BigBinaryNum& BigBinaryNum:: operator=(BigBinaryNum&& moving_bignum)
{
    size = moving_bignum.size;
    number = moving_bignum.number;
    moving_bignum.number = nullptr;
    moving_bignum.size = 0;

    return *this;
}

bool& BigBinaryNum:: operator[](unsigned int index)
{
    if (index > size - 1)
        throw out_of_range("Exceeded the borders of vector");
    return *(number + size - 1 - index);
}

BigBinaryNum BigBinaryNum:: operator-(const BigBinaryNum& bignum)
{
    bool* number_copy = new bool[256];
    for (int i = 0; i < 256; ++i)
        number_copy[i] = this->number[i];
    
    for (int i = 0; i < 256; ++i)
    {
        if (bignum.number[i])
        {
            if (number_copy[i])
                number_copy[i] = 0;
            else
                for (int q = i + 1; q < 256; ++q)
                    if (number_copy[q] == 1)
                    {
                        number_copy[q] = 0;
                        for (int k = q - 1; k >= i; --k)
                            number_copy[k] = 1;
                        break;
                    }
        }
    }

    string new_number = "";
    int i = 255;
    for (; (i >= 0) && (!number_copy[i]); --i);
    for (; i >= 0; --i)
        new_number += '1' * number_copy[i] + '0' * number_copy[i];
    return BigBinaryNum(new_number);
}

bool BigBinaryNum:: operator>(const BigBinaryNum& bignum)
{
    for (int i = 255; i >= 0; --i)
    {
        if (bignum.number[i] < this->number[i])
            return true;
        else if (bignum.number[i] > this->number[i])
            return false;
    }
    return false;
}

int BigBinaryNum:: operator/(const BigBinaryNum& bignum)
{
    BigBinaryNum divided_num = *this;
    int number_of_full_divisions = 0;
    while (divided_num > bignum)
    {
        divided_num = divided_num - bignum;
        ++number_of_full_divisions;
    }
    return number_of_full_divisions;
}

BigBinaryNum BigBinaryNum:: operator%(const BigBinaryNum& bignum)
{
    BigBinaryNum divided_num = *this;
    while (divided_num > bignum)
        divided_num = divided_num - bignum;
    return divided_num;
}

void BigBinaryNum:: operator>(int offset)
{
    int i = 0;
    for (; i < 256 - offset; ++i)
        number[i] = number[i + offset];
    for (; i < 256; ++i)
        number[i] = 0;
}

void BigBinaryNum:: operator<(int offset)
{
    int i = 255;
    for (; i >= offset; --i)
        number[i] = number[i - offset];
    for (; i >= 0; --i)
        number[i] = 0;
}

char* BigBinaryNum:: bin2dec()
{
    char* numberdec = new char[256];
    for (int i = 0; i < 256; ++i)
        numberdec[i] = '0';
    
    for (int i = size - 1; i >= 0; --i)
    {
        for (int q = 255; q >= 0; --q)
            numberdec[q] = (numberdec[q] - '0') * 2 + '0';

        if (number[i] == 1)
            numberdec[255] += 1;
        
        for (int q = 255; q >= 0; --q)
            if (numberdec[q] > '9')
            {
                numberdec[q] -= 10;
                numberdec[q-1] += 1;
            }
    }

    int first_num_index = 0;
    for (; (numberdec[first_num_index] == '0') && (first_num_index < 256); ++first_num_index);
    if (first_num_index)
    {
        int i = 0;
        for (; i < 256 - first_num_index; ++i)
        {
            numberdec[i] = numberdec[first_num_index + i];
            numberdec[first_num_index + i] = '0';
        }
        numberdec[i] = '\0';
    }
    
    if (numberdec[0] == '\0')
    {
        numberdec[0] = '0';
        numberdec[1] = '\0';
    }

    return numberdec;
}

void BigBinaryNum:: resize(int desired_size)
{
    if ((desired_size >= 0) && (desired_size <= 256))
        size = desired_size;
}

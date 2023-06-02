#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int pow(int num, int power)
{
    int powered_num = 1;
    for (int i = 0; i < power; ++i)
        powered_num *= num;
    return powered_num;
}

int str2int(string str_num)
{
    int int_num = 0;

    for (int i = str_num.size() - 1, q = 0; i >= 0; --i, ++q)
    {
        int_num += (int(str_num[i]) - 48) * pow(10, q);
    }
    
    return int_num;
}

int main()
{
    int m = 0;
    int n = 0;
    vector<int> man;
    vector<int> woman;

    bool input_mode = 0;
    cout << "File(0) or Manual(1) input: ";
    cin >> input_mode;

    ifstream input_file("input_file.txt");

    if (!input_mode)
    {
        while(!input_file.eof())
        {
            string man_count;
            string woman_count;
            input_file >> man_count >> woman_count;
            m = str2int(man_count);
            n = str2int(woman_count);

            if (m < n)
            {
                cout << "NO" << endl;
            }
            else
            {
                for (int i = 0; i < m; ++i)
                {
                    string number = 0;
                    input_file >> number;
                    int num = str2int(number);
                    man.push_back(num);
                }

                for (int i = 0; i < n; ++i)
                {
                    string number = 0;
                    input_file >> number;
                    int num = str2int(number);
                    woman.push_back(num);
                }

                sort(man.begin(), man.end());
                sort(woman.begin(), woman.end());

                for (int i = 0; i < n; ++i)
                {
                    if (woman[woman.size()-1] < man[man.size()-1])
                    {
                        woman.pop_back();
                        man.pop_back();
                    }
                    else
                    {
                        cout << "NO" << endl;
                        break;
                    }
                }

                if (!woman.size())
                    cout << "YES" << endl;
            }
        }

        input_file.close();
    }
    else
    {
        cin >> m >> n;
        
        for (int i = 0; i < m; ++i)
        {
            int number = 0;
            cin >> number;
            man.push_back(number);
        }

        for (int i = 0; i < n; ++i)
        {
            int number = 0;
            cin >> number;
            woman.push_back(number);
        }

        if (man.size() < woman.size())
        {
            cout << "NO" << endl;
            return 0;
        }

        sort(man.begin(), man.end());
        sort(woman.begin(), woman.end());

        for (int i = 0; i < n; ++i)
        {
            if (woman[woman.size()-1] < man[man.size()-1])
            {
                woman.pop_back();
                man.pop_back();
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        if (!woman.size())
            cout << "YES" << endl;
    }
    return 0;
}
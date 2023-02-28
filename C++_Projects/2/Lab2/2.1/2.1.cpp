#include <iostream>

using namespace std;

int main()
{
    const int n = 10001;
    bool array[n] = {false};
    int num = 0;

    cout << "Enter numbers (to end enter -1):" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        array[num] = 1;
    }
    
    for (int i = 0; i < n; i++)
        if (!array[i])
            cout << i << " ";

    return 0;
}
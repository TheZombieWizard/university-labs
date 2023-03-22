#include "2.1.back.h"

int main()
{
    Vector vector;
    unsigned int MAX = 1e4;
    int num = 0;
    
    cout << "Enter numbers (to end enter -1):" << endl;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        vector.extend_length(num + 1);
        vector[num] = 1;
    }
    
    unsigned int index = 0;
    
    for (; index < vector.length(); index++)
        if (!vector[index])
            cout << index << " ";
    
    for (; index <= MAX; index++)
        cout << index << " ";

    return 0;
}
#include <iostream>
#include "1.2.back.h"

using namespace std;

int main()
{
    const int size = 1000;
    char text_array[size] = {'\0'};
    char separators[11] = {" ,.:;!?-()"};
    
    text_input(text_array, size);
    cout << endl << "Similar words:" << endl;
    analyze_similar_words(text_array, size, separators);

    return 0;
}
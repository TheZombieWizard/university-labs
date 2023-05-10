#include "3.4.back.h"

int main()
{
    string original_expression = "";
    
    while(true)
    {
        char symbol = '\0';
        cin.get(symbol);
        
        if (symbol == '\n')
            break;
        
        if (symbol != ' ')
            original_expression += symbol;
    }
    
    cout << compute_expressions_with_brackets(original_expression) << endl;

    return 0;
}
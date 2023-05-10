#include "3.4.back.h"

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

bool comparison_operators_exist(string expression)
{
    for (int i = 0; i < expression.size(); ++i)
        if (   (expression[i] == '>')
            || (expression[i] == '<')
            || (expression[i] == '=')
            || (expression[i] == '!')
            )
            return true;
    return false;
}

bool logical_and_exist(string expression)
{
    for (int i = 0; i < expression.size(); ++i)
        if (expression[i] == '&')
            return true;
    return false;
}

bool logical_or_exist(string expression)
{
    for (int i = 0; i < expression.size(); ++i)
        if (expression[i] == '|')
            return true;
    return false;
}

bool brackets_exist(string expression)
{
    for (int i = 0; i < expression.size(); ++i)
        if (expression[i] == '(')
            return true;
    return false;
}

string reduce_comparison_operations(string expression)
{
    string num1 = "";
    string num2 = "";
    bool calculation_finished = false;
    string modified_expression = "";
    string operation = "";
    
    for (int i = 0; i < expression.size(); ++i)
    {
        if (   (expression[i] == '>')
            || (expression[i] == '<')
            || (expression[i] == '=')
            || (expression[i] == '!'))
        {
            int num1_index = i-1;
            for (; (num1_index >= 0) && (expression[num1_index] >= 48) && (expression[num1_index] <= 57); --num1_index);
            ++num1_index;
            for (int q = num1_index; (q < i); ++q)
                num1 += expression[q];

            operation += expression[i];
            int num2_index = 0;
            if (expression[i+1] == '=')
            {
                operation += expression[i+1];
                for (num2_index = i+2; (expression[num2_index] >= 48) 
                                        && (expression[num2_index] <= 57) 
                                        && (num2_index < expression.size()); ++num2_index)            
                    num2 += expression[num2_index];
            }
            else
            {
                for (num2_index = i+1; (expression[num2_index] >= 48) 
                                        && (expression[num2_index] <= 57) 
                                        && (num2_index < expression.size()); ++num2_index)            
                    num2 += expression[num2_index];
            }


            for (int q = 0; q < num1_index; ++q)
                modified_expression += expression[q];

            modified_expression += char(compute_basic_expression(num1, operation, num2) + 48);

            for (int q = num2_index; q < expression.size(); ++q)
                modified_expression += expression[q];

            break;
        }
    }

    return modified_expression;
}

string reduce_logical_and(string expression)
{
    string num1 = "";
    string num2 = "";
    bool calculation_finished = false;
    string modified_expression = "";
    
    for (int i = 0; i < expression.size(); ++i)
    {
        if (expression[i] == '&')
        {
            int num1_index = i-1;
            for (; (num1_index >= 0) && (expression[num1_index] >= 48) && (expression[num1_index] <= 57); --num1_index);
            ++num1_index;
            for (int q = num1_index; (q < i); ++q)
                num1 += expression[q];
            
            int num2_index = 0;
            for (num2_index = i+2; (expression[num2_index] >= 48) 
                                    && (expression[num2_index] <= 57) 
                                    && (num2_index < expression.size()); ++num2_index)            
                num2 += expression[num2_index];


            for (int q = 0; q < num1_index; ++q)
                modified_expression += expression[q];

            modified_expression += char(compute_basic_expression(num1, "&&", num2) + 48);

            for (int q = num2_index; q < expression.size(); ++q)
                modified_expression += expression[q];

            break;
        }
    }

    return modified_expression;
}

string reduce_logical_or(string expression)
{
    string num1 = "";
    string num2 = "";
    bool calculation_finished = false;
    string modified_expression = "";
    
    for (int i = 0; i < expression.size(); ++i)
    {
        if (expression[i] == '|')
        {
            int num1_index = i-1;
            for (; (num1_index >= 0) && (expression[num1_index] >= 48) && (expression[num1_index] <= 57); --num1_index);
            ++num1_index;
            for (int q = num1_index; (q < i); ++q)
                num1 += expression[q];
            
            int num2_index = 0;
            for (num2_index = i+2; (expression[num2_index] >= 48) 
                                    && (expression[num2_index] <= 57) 
                                    && (num2_index < expression.size()); ++num2_index)            
                num2 += expression[num2_index];


            for (int q = 0; q < num1_index; ++q)
                modified_expression += expression[q];

            modified_expression += char(compute_basic_expression(num1, "||", num2) + 48);

            for (int q = num2_index; q < expression.size(); ++q)
                modified_expression += expression[q];

            break;
        }
    }

    return modified_expression;
}

string reduce_brackets(string expression)
{
    string modified_expression = "";
    bool start_analyzing = false;
    string brackets_expression = "";

    int i = 0;
    for (; i < expression.size(); ++i)
    {
        if (expression[i] == ')')
        {
            modified_expression += compute_advanced_expression(brackets_expression);
            ++i;
            break;
        }
        else if (expression[i] == '(')
        {
            if (start_analyzing)
                modified_expression += "(";
            brackets_expression = "";
            start_analyzing = true;
        }
        else if (start_analyzing)
            brackets_expression += expression[i];
        else
            modified_expression += expression[i];
        
    }

    for (; i < expression.size(); ++i)
        modified_expression += expression[i];

    return modified_expression;
}

int compute_basic_expression(string num1, string operation, string num2)
{
    if (operation == ">")
        return (str2int(num1) > str2int(num2));
    else if (operation == "<")
        return (str2int(num1) < str2int(num2));
    else if (operation == "==")
        return (str2int(num1) == str2int(num2));
    else if (operation == "!=")
        return (str2int(num1) != str2int(num2));
    else if (operation == ">=")
        return (str2int(num1) >= str2int(num2));
    else if (operation == "<=")
        return (str2int(num1) <= str2int(num2));
    else if (operation == "&&")
        return (str2int(num1) && str2int(num2));
    else if (operation == "||")
        return (str2int(num1) || str2int(num2));

    return 0;
}

string compute_advanced_expression(string expression)
{
    string modified_expression = "";
    
    bool calculation_in_progress = false;
    string num1 = "";
    for (int i = 0; i < expression.size(); ++i)
    {
        if ((expression[i] == '!') && (expression[i+1] != '='))
            calculation_in_progress = true;
        else if (calculation_in_progress && (expression[i] >= 48) && (expression[i] <= 57))
            num1 += expression[i];
        else if (calculation_in_progress)
        {
            modified_expression += char(!(str2int(num1)) + 48);
            calculation_in_progress = false;
        }
        
        if (!calculation_in_progress)
            modified_expression += expression[i];
    }
    
    if (calculation_in_progress)
    {
        modified_expression += char(!(str2int(num1)) + 48);
        calculation_in_progress = false;
    }

    while (comparison_operators_exist(modified_expression))
    {
        cout << modified_expression << endl;
        modified_expression = reduce_comparison_operations(modified_expression);
    }

    while (logical_and_exist(modified_expression))
    {
        cout << modified_expression << endl;
        modified_expression = reduce_logical_and(modified_expression);
    }

    while (logical_or_exist(modified_expression))
    {
        cout << modified_expression << endl;
        modified_expression = reduce_logical_or(modified_expression);
    }
    
    return modified_expression;
}

string compute_expressions_with_brackets(string expression)
{
    string modified_expression = expression;

    while (brackets_exist(modified_expression))
        modified_expression = reduce_brackets(modified_expression);

    modified_expression = compute_advanced_expression(modified_expression);

    return modified_expression;
}

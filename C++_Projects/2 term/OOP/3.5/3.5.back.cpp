#include "3.5.back.h"


void analyze_unnamed_constants(string file_path)
{
    map<string, vector<int>> unnamed_constants;
    ifstream input_file(file_path);
    string separators = " ,;:/*+-=!(){}";
    unsigned int line_count = 0;
    bool multi_comment_line = false;

    while (!input_file.eof())
    {
        string code_line = "";
        string constant = "";
        bool analyzing_constant = false;
        bool single_comment_line = false;
        short string_constant = 0;
        char last_symbol = '\0';
        ++line_count;

        while (!input_file.eof())
        {
            char symbol;
            input_file.get(symbol);

            if (symbol == '\n')
                break;

            if (!multi_comment_line && !single_comment_line)
                code_line += symbol;
            
            if (symbol == '\'')
            {
                if (!string_constant)
                    string_constant = 1;
                else if (string_constant == 1)
                    string_constant = 0;
            }
            else if (symbol == '\"')
            {
                if (!string_constant)
                    string_constant = 2;
                else if (string_constant == 2)
                    string_constant = 0;
            }

            if (symbol == '/' && last_symbol == '/' && !multi_comment_line && !string_constant)
            {
                code_line.pop_back();
                code_line.pop_back();
                single_comment_line = true;
            }
            else if (symbol == '*' && last_symbol == '/'  && !multi_comment_line && !string_constant)
            {
                code_line.pop_back();
                code_line.pop_back();
                multi_comment_line = true;
            }
            else if (symbol == '/' && last_symbol == '*' && !string_constant)
                multi_comment_line = false;
            
            last_symbol = symbol;
        }

        int c = code_line.size();
        if (c >= 1)
        {
            for (int i = 0; i < code_line.size(); ++i)
            {
                if ((code_line[i] == '\"') || (code_line[i] == '\''))  
                {
                    constant += code_line[i];
                    if (analyzing_constant && (code_line[i] == constant[0])) 
                    {
                        analyzing_constant = false;
                        if (!unnamed_constants[constant].size())
                            unnamed_constants[constant].resize(1);
                        unnamed_constants[constant][0] += 1;
                        unnamed_constants[constant].push_back(line_count);
                        constant = "";
                    }
                    else
                        analyzing_constant = true;
                }
                else if (analyzing_constant)
                    constant += code_line[i];
            }

            vector<string> splitted_code_line = split(code_line, separators);
            for (int i = 0; i < splitted_code_line.size(); ++i)
            {
                if (   isdigit(splitted_code_line[i][0]) 
                    || splitted_code_line[i][0] == '[' 
                    || splitted_code_line[i] == "true" 
                    || splitted_code_line[i] == "false")
                {
                    constant = splitted_code_line[i];
                    if (!unnamed_constants[constant].size())
                        unnamed_constants[constant].resize(1);
                    unnamed_constants[constant][0] += 1;
                    unnamed_constants[constant].push_back(line_count);
                }
            }
        }
    }

    input_file.close();

    map<string, vector<int>>::iterator iter;
    for (iter = unnamed_constants.begin(); iter != unnamed_constants.end(); ++iter)
    {
        cout << setw(30) << iter->first << "  count: " << iter->second[0] << " lines: ";
        for (int i = 1; i < iter->second.size(); ++i)
            cout << iter->second[i] << " ";
        cout << endl; 
    }
}

vector<string> split(string expression, string separators)
{
    vector<string> splitted_expression;
    string expression_part = "";
    bool separator_found = false;
    bool square_brackets = false;
    
    for (int i = 0; i < expression.size(); ++i)
    {
        if (expression[i] == ']')
        {
            expression_part += expression[i];
            square_brackets = false;
            splitted_expression.push_back(expression_part);
            expression_part = "";
            continue;
        }
        else if (expression[i] == '[')
            square_brackets = true;

        if (square_brackets)
            expression_part += expression[i];
        else
        {
            bool current_symbol_is_separator = false;
            for (int q = 0; q < separators.size(); ++q)
                if (expression[i] == separators[q])
                {
                    current_symbol_is_separator = true;
                    separator_found = true;
                    break;
                }

            if (current_symbol_is_separator)
                continue;
            
            if (separator_found)
            {
                separator_found = false;
                splitted_expression.push_back(expression_part);
                expression_part = "";
            }

            expression_part += expression[i];
        }
    }
    
    if (expression_part.size())
        splitted_expression.push_back(expression_part);

    return splitted_expression;
}

bool isdigit(char symbol)
{
    if ((symbol >= 48) && (symbol <= 57))
        return true;
    return false;
}
#include <iostream>

using namespace std;

void copy_word(char word1[], char word2[])
{
    for (int i = 0; word2[i]; i++)
        word1[i] = word2[i];
}

void add_word(char text[], char word[])
{
    int i = 0;
    for (; text[i]; i++);
    for (int q = 0; word[q]; i++, q++)
        text[i] = word[q];
    text[i] = ' ';
}

void clear_char(char text[], int size)
{
    for (int i = 0; i < size; i++)
        text[i] = '\0';
}

void sort_select(char array[])
{
    int size = 0;
    for (; array[size]; size++);
    for (int i = 0; array[i+1]; i++)
    {
        char min = array[i];
        int index_min = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < min)
                {
                    min = array[j];
                    index_min = j;
                }
        array[index_min] = array[i];
        array[i] = min;
    }
}

bool equal_words(char word1[], char word2[], int size)
{
    char c_word1[size] = {'\0'};
    char c_word2[size] = {'\0'};
    copy_word(c_word1, word1);
    copy_word(c_word2, word2);
    sort_select(c_word1);
    sort_select(c_word2);
    
    for (int i = 0; c_word1[i]; i++)
        if (c_word1[i] != c_word2[i])
            return false;
    return true;
}

bool is_separator(char ch, char separators[])
{
    for (int i = 0; separators[i]; i++)
            if (ch == separators[i])
                return true;
    return false;
}

void text_input(char text[], int size)
{
    cin.getline(text, size, '\n');
}

void text_output(char *text_pointer)
{
    for (; (*text_pointer); text_pointer++)
        cout << *text_pointer;
    cout << endl;
}

void analyze_similar_words(char text_array[], int size, char separators[])
{
    char similar_words_line[size] = {'\0'},
        temp_word[size] = {'\0'},
        current_word[size] = {'\0'};
    int similar_words_count = 1;

    for (int text_i = 0, temp_i = 0; text_i < size; text_i++)
    {
        if (!is_separator(text_array[text_i], separators))
        {
            temp_word[temp_i] = text_array[text_i];
            text_array[text_i] = ',';
            temp_i++;
        }
        else
        {
            if (temp_word[0] != '\0')
            {
                add_word(similar_words_line, temp_word);
                for (int curr_word_i = 0, start_text_i = text_i + 1, curr_text_i = text_i + 1;
                    curr_text_i < size; curr_text_i++)
                {
                    if (!is_separator(text_array[curr_text_i], separators) && (text_array[curr_text_i] != '\0'))
                    {
                        current_word[curr_word_i] = text_array[curr_text_i];
                        curr_word_i++;
                    }    
                    else
                    {
                        if (current_word[0] != '\0')
                            if (equal_words(temp_word, current_word, size))
                            {
                                add_word(similar_words_line, current_word);
                                similar_words_count++;
                                for (int i = start_text_i; i < curr_text_i; i++)
                                    text_array[i] = ',';
                            }
                        clear_char(current_word, size);
                        curr_word_i = 0;
                        start_text_i = curr_text_i;
                    }
                }
                if (similar_words_count > 1)
                    text_output(similar_words_line);
                similar_words_count = 1;
                clear_char(similar_words_line, size);
                clear_char(temp_word, size);
                temp_i = 0;
                clear_char(current_word, size);
            }
        }
    }
}
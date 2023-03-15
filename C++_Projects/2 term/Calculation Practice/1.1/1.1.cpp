#include "array_staff.cpp"

int main()
{
    const int N = 6;
    int inp_array[N][N] = {0},
        out_array[N][N] = {0};
    int *inp_arr_pointer = &inp_array[0][0],
        *out_arr_pointer = &out_array[0][0];

    enum input_modes { increasing_input, random_input };

    cout << "Input mode:" << endl
        << "(" << increasing_input << ") - increasing numbers" << endl
        << "(" << random_input << ") - random numbers" << endl;

    int input_mode = 0;
    cin >> input_mode;

    if (input_mode == increasing_input) increasing_creation(inp_arr_pointer, N * N);
    else if (input_mode == random_input) random_creation(inp_arr_pointer, N * N);
    else cout << "Wrong input";
    
    arr_output(inp_arr_pointer, N);
    snake_creation(inp_arr_pointer, out_arr_pointer, N);
    cout << endl;
    arr_output(out_arr_pointer, N);

    return 0;
}
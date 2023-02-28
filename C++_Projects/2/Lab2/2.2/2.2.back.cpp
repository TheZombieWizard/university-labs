using namespace std;

template <class type>
void random_creation(type *p_array, int size)
{
    for (int i = 0; i < size; i++, p_array++)
        *p_array = type(rand() % 7) + type(rand() % 43) / 100;
}

template <class type>
void random_creation(type **p_array, int N)
{
    for (int i = 0; i < N; i++)
        for (int q = 0; q < N; q++)
            p_array[i][q] = type(rand() % 7) + type(rand() % 43) / 100;
}

template <class type>
void array_output(type **p_array, int N)
{
    for (int i = 0; i < N; i++)
        for (int q = 0; q < N; q++)
            cout << p_array[i][q] << " ";
    cout << endl;
}

template <class type>
void array_output(type *p_array, int size)
{
    for (int n = 0; n < size; n++, p_array++)
        cout << *p_array << " ";
    cout << endl;
}

template <class type>
void find_c(type *arr_A, type vec_B[], int N)
{
    type *p_AA = new type[N*N]{};
    type i_element = 0;
    
    for (int i = 0; i < N*N; i++)
    {
        i_element = 0;
        for (int q = 0; q < N; q++)
            i_element += arr_A[q + N * (i / N)] * arr_A[q * N + i % N];
        p_AA[i] = i_element;
    }

    type *p_C = new type[N]{};
    for (int i = 0; i < N; i++)
    {
        i_element = 0;
        for (int q = 0; q < N; q++)
            i_element += vec_B[q] * p_AA[q + N * i];
        p_C[i] = i_element;
    }

    array_output(p_C, N);
}

template <class type>
void find_c(type **arr_A, type vec_B[], int N)
{
    type *p_AA = new type[N*N]{};
    type i_element = 0;
    
    for (int i = 0; i < N*N; i++)
    {
        i_element = 0;
        for (int q = 0; q < N; q++)
            i_element += arr_A[i / N][q] * arr_A[q][i % N];
        p_AA[i] = i_element;
    }

    type *p_C = new type[N]{};
    for (int i = 0; i < N; i++)
    {
        i_element = 0;
        for (int q = 0; q < N; q++)
            i_element += vec_B[q] * p_AA[q + N * i];
        p_C[i] = i_element;
    }

    array_output(p_C, N);
}
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
    type *pSqr = new type[N*N]{};
    
    for (int i = 0; i < N*N; i++)
    {
        for (int q = 0; q < N; q++)
            pSqr[i] += arr_A[q + N * (i / N)] * arr_A[q * N + i % N];
    }

    type *pC = new type[N]{};
    for (int i = 0; i < N; i++)
    {
        for (int q = 0; q < N; q++)
            pC[i] += vec_B[q] * pSqr[q + N * i];
    }

    delete [] pSqr;
    array_output(pC, N);
}

template <class type>
void find_c(type **arr_A, type vec_B[], int N)
{
    type *pSqr = new type[N*N]{};
    
    for (int i = 0; i < N*N; i++)
    {
        for (int q = 0; q < N; q++)
            pSqr[i] += arr_A[i / N][q] * arr_A[q][i % N];
    }

    type *pC = new type[N]{};
    for (int i = 0; i < N; i++)
    {
        for (int q = 0; q < N; q++)
            pC[i]  += vec_B[q] * pSqr[q + N * i];
    }
    delete [] pSqr;
    array_output(pC, N);
}
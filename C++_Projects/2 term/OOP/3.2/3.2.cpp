#include <iostream>
#include <vector>

using namespace std;

void task_2_1();
void task_2_2();

template <typename type>
void find_c(vector<type> arr_A, vector<type> vec_B, int N);

template <typename type>
void find_c(vector< vector<type> > arr_A, vector<type> vec_B, int N);

int main()
{
    //task_2_1();
    //task_2_2();
    
    return 0;
}

void task_2_1()
{
    vector<bool> vector;

    cout << "Enter numbers (enter -1 to stop the input):" << endl;
    
    while (true)
    {
        int num = 0;
        cin >> num;
        if (num == -1)
            break;
        if (vector.size() < (num + 1))
            vector.resize(num + 1);
        
        vector[num] = 1;
    }

    for (int i = 0; i <= 10000; ++i)
        if (!vector[i])
            cout << i << " ";
}

void task_2_2()
{
    srand(time(NULL));
    
    int N = 13;
    cout << "N: " << endl;
    cin >> N;

    vector< vector<float> > pA(N);
    for (int i = 0; i < N; ++i)
        pA[i] = vector<float>(N);
    
    cout << "Matrix A: " << endl;
    for (int i = 0; i < N; ++i)
        for (int q = 0; q < N; ++q)
            pA[i][q] = rand() % 4;
    
    for (int i = 0; i < N; ++i)
    {
        for (int q = 0; q < N; ++q)
            cout << pA[i][q] << " ";
        cout << endl;
    }

    /* 
    vector<float> pA(N*N);

    cout << "Matrix A: " << endl;
    for (int i = 0; i < N*N; ++i)
        pA[i] = rand() % 4;
    for (int i = 0, q = 0; i < N*N; ++i, ++q)
    {
        if (q == N)
        {
            q = 0;
            cout << endl;
        }
        cout << pA[i] << " ";
    }
    cout << endl;
    */

    vector<float> pB(N);
    cout << endl << "Vector B: " << endl;
    for (int i = 0; i < pB.size(); ++i)
        pB[i] = rand() % 4;
    for (int i = 0; i < pB.size(); ++i)
        cout << pB[i] << endl;
    cout << endl;

    find_c(pA, pB, N);
}

template <typename type>
void find_c(vector<type> arr_A, vector<type> vec_B, int N)
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
    cout << "Vector C: " << endl;
    for (int i = 0; i < N; ++i)
        cout << pC[i] << endl;
}

template <typename type>
void find_c(vector< vector<type> > arr_A, vector<type> vec_B, int N)
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
    cout << "Vector C: " << endl;
    for (int i = 0; i < N; ++i)
        cout << pC[i] << endl;
}
#include "2.2.back.h"

int main()
{
    int N = 13;
    cout << "N: " << endl;
    cin >> N;
    
    int *p_A = new int[N*N]{};
    int **pp_A = new int*[N]{};
    for (int i = 0; i < N; i++)
        pp_A[i] = p_A + N * i;
    int *p_B = new int[N]{};

    srand(time(NULL));
    random_creation(pp_A, N);
    array_output(pp_A, N);

    random_creation(p_B, N);
    array_output(p_B, N);

    find_c(pp_A, p_B, N);

    return 0;
}
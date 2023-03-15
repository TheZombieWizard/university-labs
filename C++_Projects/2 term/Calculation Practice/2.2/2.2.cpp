#include "2.2.back.h"

int main()
{
    int N = 13;
    cout << "N: " << endl;
    cin >> N;
    bool flag = 0;
    cin >> flag;
    if (flag){
        int *pA = new int[N*N]{};
    }else{
        int **pA = new int*[N]{};
        for (int i = 0; i < N; i++)
            pA[i] = NULL;
    }    
    
    int *pA = new int[N*N]{};
    int *pB = new int[N]{};

    srand(time(NULL));
    random_creation(pA, N);
    array_output(pA, N);

    random_creation(pB, N);
    array_output(pB, N);

    find_c(pA, pB, N);

    return 0;
}
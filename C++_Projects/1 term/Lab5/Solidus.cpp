using namespace std;

// ------------------------------  Creation (char) -----------------------------------------------
// A-Z = 65-90
// a-z = 97-122
void increasing_creation(char array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++)
    {
        if ((65 + i) == 91) i += 6;
        array[i] = char(65 + i);
    }
}

void decreasing_creation(char array[], int n)
{
    srand(time(NULL));
    for (int i = 0, q = 122; i < n ; i++, q--)
    {
        if (q == 96) q -= 6;
        array[i] = char(q);
    }
}

void random_creation(char array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++)
    {
        bool upper_case = rand() % 2;
        if (upper_case) 
            array[i] = char((rand() % 26) + 65);
        else
            array[i] = char((rand() % 26) + 97);
    }
}

// ------------------------------  Creation (template) -----------------------------------------------
template <class type>
void increasing_creation(type array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++)
        array[i] = type(i) + type(rand() % 10) / 100;
}

template <class type>
void decreasing_creation(type array[], int n)
{
    srand(time(NULL));
    for (int i = n - 1, q = 0; i >= 0 ; i--, q++)
        array[i] = type(q) + type(rand() % 10) / 100;
}

template <class type>
void random_creation(type array[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++)
        array[i] = type(rand() % 100) + type(rand() % 10) / 100;
}

// ------------------------------  Sort (template) -----------------------------------------------
template <class type>
void quick_sort(type array[], int left, int right)
{
    int i = left, 
        j = right; //присвоение параметрам счетчиков текущих левой и правой границ части
    type mid = array[(left + right)/2]; // сохранение в mid значения среднего элемента
    
    // повторять пока проходы слева и справа не перехлестнутся
    do 
    {
        //проход слева до первого попавшегося элемента больше среднего
        while (array[i] < mid) i++;
        //проход справа до первого попавшегося элемента меньше среднего
        while (array[j] > mid) j--;

        if (i <= j) // обмен местами найденных элементов
        {
            type temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++; j--;// переход к следующим для каждого прохода значениям
        }
    } while(i < j); // повторять пока проходы не перехлестнутся
    // рекурсивное повторение алгоритма для разделенных частей массива
    if (left < j ) quick_sort(array, left, j);
    if (i < right) quick_sort(array, i, right);
}

template <class type>
void sort_select(type array[], int size)
{
    // последовательный перебор всех элементов кроме последнего
    for (int i = 0; i < size - 1; i++)
    {
        type min = array[i];
        int index_min = i;
        // Поиск минимума в части массива от i+1 до конца
        for (int j = i + 1; j < size; j++)
            if (array[j] < min)
                {
                    min = array[j];
                    index_min = j;
                }
        // Обмен местами текущего элемента и найденного минимального
        array[index_min] = array[i];
        array[i] = min;
    }
} 

// ------------------------------  Sort comparison (template) -----------------------------------------------
template <class type>
void quick_sort_comparison_func(type array[], int left, int right, int& swaps_amount_ref, int& comparison_amount_ref)
{
    int i = left, 
        j = right; //присвоение параметрам счетчиков текущих левой и правой границ части
    type mid = array[(left + right)/2]; // сохранение в mid значения среднего элемента
    
    // повторять пока проходы слева и справа не перехлестнутся
    do 
    {
        //проход слева до первого попавшегося элемента больше среднего
        while (array[i] < mid) 
        {
            i++;
            comparison_amount_ref++;
        }
        //проход справа до первого попавшегося элемента меньше среднего
        while (array[j] > mid)
        {
            j--;
            comparison_amount_ref++;
        }

        comparison_amount_ref++;
        if (i <= j) // обмен местами найденных элементов
        {
            type temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            swaps_amount_ref++;
            i++; j--;// переход к следующим для каждого прохода значениям
        }
        comparison_amount_ref++;
    } while(i < j); // повторять пока проходы не перехлестнутся
    
    // рекурсивное повторение алгоритма для разделенных частей массива
    if (left < j ) 
    {
        comparison_amount_ref++;
        quick_sort_comparison_func(array, left, j, swaps_amount_ref, comparison_amount_ref);
    }
    if (i < right) 
    {
        comparison_amount_ref++;
        quick_sort_comparison_func(array, i, right, swaps_amount_ref, comparison_amount_ref);
    }
}

template <class type>
void quick_sort_comparison(type array[], int left, int right)
{
    int swaps_amount = 0,
        comparison_amount = 0;
    int& swaps_amount_ref = swaps_amount;
    int& comparison_amount_ref = comparison_amount;

    quick_sort_comparison_func(array, left, right, swaps_amount_ref, comparison_amount_ref);

    std::cout << "Кол-во сравнений: " << comparison_amount << std::endl;
    std::cout << "Кол-во перестановок: " << swaps_amount << std::endl;
}

template <class type>
void sort_select_comparison(type array[], int size)
{
    int swaps_amount = 0,
        comparison_amount = 0;
    // последовательный перебор всех элементов кроме последнего
    for (int i = 0; i < size - 1; i++)
    {
        type // min = array[i], 
            index_min = i;
        swaps_amount += 1;
        // Поиск минимума в части массива от i+1 до конца
        for (int j = i + 1; j < size; j++, comparison_amount++)
            if (array[j] < array[index_min])
                {
                    // min = array[j];
                    index_min = j;
                    swaps_amount += 1;
                }
        // Обмен местами текущего элемента и найденного минимального
        type min = array[index_min];
        array[index_min] = array[i];
        array[i] = min;
        swaps_amount += 3;
    }
    std::cout << "Кол-во сравнений: " << comparison_amount << std::endl;
    std::cout << "Кол-во перестановок: " << swaps_amount << std::endl;
} 

// ------------------------------  Creation (pointers) -----------------------------------------------
void increasing_creation(int* p_element, int n)
{
    srand(time(NULL));
    for (int i = 0; i <= n - 1; i++, p_element++)
        *p_element = i;
}

void decreasing_creation(int* p_element, int n)
{
    srand(time(NULL));
    for (int i = n - 1, q = 0; i >= 0 ; i--, q++, p_element++)
        *p_element = i;
}

void random_creation(int* p_element, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n ; i++, p_element++)
        *p_element = (rand() % 100);
}

// ------------------------------  Output (pointers) -----------------------------------------------
void array_output(int* p_element, int N, int M)
{
    for (int n = 0; n < N; n++)
    {  
        for (int m = 0; m < M; m++, p_element++)
            cout << *p_element << " ";
        cout << endl;
    }
}

// ------------------------------  Count (pointers) -----------------------------------------------
void count_lines_sums(int* p_element, int N, int M, int count[][2])
{
    for (int n = 0; n < N; n++)
    {
        count[n][0] = n;
        for (int m = 0; m < M; m++, p_element++)
            count[n][1] += *p_element;
    }
}

// ------------------------------  Sort (pointers) -----------------------------------------------
void sort_select(int* p_element, int N, int M, int count[][2])
{
    int count_values[N] = {0};
    for (int n = 0; n < N; n++)
    {
        count_values[n] = count[n][1];
    }
    
    sort_select(count_values, N);

    int mid_lines_sorted = 0;

    for (int n = 0; n < N; n++)
    {
        for (int m = n; m < M; m++)
            if (count_values[n] == count[m][1])
            {
                for (int i = 0; i < M; i++)
                {
                    int temp = *(p_element + n * M);
                    *(p_element + n * M) = *(p_element + m * M );
                    *(p_element + m * M ) = temp;
                    p_element++;
                }
                p_element -= M;    
            }
    }
} 
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

const int N = 13;
struct student_template
{
    char name[N];
    char surname[N];
    char sex[2];
    int age;
    int year;
    int grade;
};

void group_init(student_template group[])
{
    srand(time(NULL));
    
    // Записываем имя каждого студента
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
            group[i].name[j] = rand() % 26 + 97;
        group[i].name[N - 1] = '\0';
    }
    
    // Записываем фамилию каждого студента
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
            group[i].surname[j] = rand() % 26 + 97;
        group[i].surname[N - 1] = '\0';
    }

    // Указываем пол студентов
    for (int i = 0; i < N; i++)
    {
        if (rand() % 2) 
            group[i].sex[0] = 'M';
        else 
            group[i].sex[0] = 'W';
        group[i].sex[1] = '\0';
    }

    // Указываем курс каждого студента
    for (int i = 0; i < N; i++)
        group[i].year = rand() % 4 + 1; // От 1 до 4

    // Указываем возраст студентов
    for (int i = 0; i < N; i++)
        // По умолчанию 18 лет, дальше прибавка за счет курса и разброс +- 1 год (могли поступить в 17/18/19 лет)
        group[i].age = 18 + (group[i].year - 1) + (rand() % 3 - 1);

    // Устанавливаем успеваемость студентов
    for (int i = 0; i < N; i++)
        group[i].grade = rand() % 10 + 1;
}

void excellent_print(student_template group[], int n)
{
    int number_of_excellent = 0;
    for (int i = 0; i < N; i++)
        if ((group[i].year == n) && (group[i].grade >= 9))
            number_of_excellent++;
    cout << "Number of excellent students of the " << n << " learning year: "<<number_of_excellent << endl;
}

void group_print(student_template group[])
{
    cout << setw(N) << "Name" << "|" << setw(N) << "Surname" << "|" 
        << setw(5) << "sex" << "|" << setw(5) << "age" << "|" 
        << setw(5) << "year" << "|" << setw(5) << "grade" << "|" << endl;
    for (int i = 0; i < N; i++)
        cout << setw(N) << group[i].name << "|" << setw(N) << group[i].surname << "|" 
        << setw(5) << group[i].sex << "|" << setw(5) << group[i].age << "|" 
        << setw(5) << group[i].year << "|" << setw(5) << group[i].grade << "|" << endl;
}

void B7_6_1()
{    
    int n = 0;
    cout << "Курс, на котором нужно определить отличников (n): " << endl;
    cin >> n;

    student_template group[N];
    group_init(group);

    group_print(group);
    excellent_print(group, n);
}

union train_place
{
    unsigned int train_place;
    struct
    {
        unsigned int train_number : 10;
        unsigned char train_alpha : 8;
        unsigned int wagon_number : 6;
        unsigned int place_number : 7;
    };
};

// Функция-компаратор
bool compare_train_places(train_place &train_places, train_place &b)
{
    if (train_places.train_number < b.train_number) return true;
    if (train_places.train_number > b.train_number) return false;

    if (train_places.train_alpha < b.train_alpha) return true;
    if (train_places.train_alpha > b.train_alpha) return false;
    
    if (train_places.wagon_number < b.wagon_number) return true;
    if (train_places.wagon_number > b.wagon_number) return false;
    
    return train_places.place_number < b.place_number;
};

void train_places_init(train_place train_places[])
{
    srand(time(NULL));
    
    // Номер поезда
    for (int i = 0; i < N; i++)
        train_places[i].train_number = rand() % 1000 + 1;
    
    // Буква, дополняющая номер поезда
    for (int i = 0; i < N; i++)
        train_places[i].train_alpha = char((rand() % 26) + 65);

    // Номер вагона
    for (int i = 0; i < N; i++)
        train_places[i].wagon_number = rand() % 32 + 1;
    
    // Номер места в вагоне
    for (int i = 0; i < N; i++)
        train_places[i].place_number = rand() % 54 + 1;
}

void train_places_print_v1(train_place train_places[])
{
    cout << setw(15) << "Train Number" << "|" << setw(14) << "Wagon number" << "|" << setw(14) << "Place number" << "|" << endl;
    for (int i = 0; i < N; i++)
        cout << setw(14) << train_places[i].train_number << train_places[i].train_alpha << "|" 
        << setw(14) << train_places[i].wagon_number << "|" << setw(14) << train_places[i].place_number << "|" << endl;
        
}

void train_places_print_v2(train_place train_places[])
{
    cout << "Train place" << endl
        << "-----------" << endl;
    for (int i = 0; i < N; i++)
        cout << train_places[i].train_number << char(train_places[i].train_alpha) 
            << train_places[i].wagon_number << train_places[i].place_number << endl; 
}

void train_places_equal(train_place train_places[])
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if ((train_places[i].train_number == train_places[j].train_number) && 
                (train_places[i].train_alpha == train_places[j].train_alpha) &&
                (train_places[i].wagon_number == train_places[j].wagon_number) &&
                (train_places[i].place_number == train_places[j].place_number))
                    cout << train_places[i].train_number << char(train_places[i].train_alpha) 
                        << train_places[i].wagon_number << train_places[i].place_number << endl; 
}

void B7_6_2()
{
    const int N = 13;
    train_place train_places[N];
    train_places_init(train_places);
    train_places_print_v2(train_places);
    /**/
    train_places[0].train_number = train_places[7].train_number;
    train_places[0].train_alpha = train_places[7].train_alpha;
    train_places[0].wagon_number = train_places[7].wagon_number;
    train_places[0].place_number = train_places[7].place_number;

    train_places[3].train_number = train_places[5].train_number;
    train_places[3].train_alpha = train_places[5].train_alpha;
    train_places[3].wagon_number = train_places[5].wagon_number;
    train_places[3].place_number = train_places[5].place_number;
    /**/
    sort(train_places, train_places + N, compare_train_places);
    cout << endl;
    train_places_print_v2(train_places);

    cout << endl << "Equal train places: " << endl 
        << "-------------------" << endl;
    train_places_equal(train_places);
}

int main()
{
    for (int j = 0; j < 13; j++)
    {
        int n = 0;
        cout << endl << "Вариант 7B" << endl
            << "(1) - Задание 6.1 - Массивы структур" << endl
            << "(2) - Задание 6.2 - Использование структур с битовыми полями" << endl;
        cin >> n;
        cin.get();
        cout << "//////////////////////////////////////////////////////" << endl;
        switch (n)
        {
        case 1:
            B7_6_1();
            continue;
        case 2:
            B7_6_2();
            continue;
        default:
            cout << "Ah, crap, wrong input..." << endl;
        }
        cout << endl << "//////////////////////////////////////////////////////" << endl;
        return 0;
    }
}
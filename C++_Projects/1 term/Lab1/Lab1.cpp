#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

void B7_1_1() {
    // Вариант 7, часть B, задание 1.1
    int s, t;
    double x;
    cout << "Введите S, x, t: ";
    cin >> s >> x >> t;
    double y = (1 + pow(x, t)) / (log(pow(x, 3)) * sqrt(pow(x, s) + 1));
    cout << y;
} // (+)

void B7_1_2() {
    /*sqrt(pow(abs(R) - abs(x), 2) + pow(abs(y), 2)) <= R*/
    // Вариант 7, часть B, задание 1.2
    double R, x, y;
    cout << "Введите R, x, y: ";
    cin >> R >> x >> y;
    if (abs(x) <= R && abs(y) <= R) {
        if (x >= 0 && y <= 0) {
            if (y >= -sqrt(2*x*R - pow(x, 2)))
                { cout << "Yes";}
            else {cout << "No";}
        }
        else if (x <= 0 && y >= 0) {
            if (y <= sqrt(-2 * x * R - pow(x, 2)))
                { cout << "Yes";}
            else { cout << "No"; }
        }
        else {cout << "No";}
    }
    else {cout << "No";}
} // (+)

void B7_1_3() {
    double x1, x2, x3, x4;
    cout << "Введите x1, x2, x3, x4: ";
    cin >> x1 >> x2 >> x3 >> x4;
    bool operation_done = true;
    // double k;
    while (operation_done == true) {
        operation_done = false;
        // if (x2 > x1) { k = x1; x1 = x2; x2 = k; operation_done = true; }
        // if (x3 > x2) { k = x3; x3 = x2; x2 = k; operation_done = true; }
        // if (x4 > x3) { k = x4; x4 = x3; x3 = k; operation_done = true; }
        (x2 > x1) ? (swap(x2, x1), operation_done = true) : (1);
        (x3 > x2) ? (swap(x3, x2), operation_done = true) : (1);
        (x4 > x3) ? (swap(x4, x3), operation_done = true) : (1);
    }
    cout << "x1 = " << x1 << "; x2 = " << x2 << "; x3 = " << x3 << "; x4 = " << x4 << ";\n";
    cout << x1 << " >= " << x2 << " >= " << x3 << " >= " << x4;
} // (+-) Надо сделать второй вариант с операндом "?"

bool ferz(int x0, int y0, int x1, int y1) {
    // Проверка диагоналей
    if ((y1 - x1) == (y0 - x0)) { return true; }
    else if ((y1 + x1) == (y0 + x0)) { return true; }
    // Проверка вертикали
    else if (x1 == x0) { return true; }
    // Проверка горизонтали
    else if (y1 == y0) { return true; }
    else { return false; }
}
bool peshka(int x0, int y0, int x1, int y1) {
    if ((abs(x1 - x0) == 1) && ((y1 - y0) == 1)) { return true; }
    else { return false; }
}
void B7_1_4() {
    int ferzX, ferzY, peshkaX, peshkaY;
    cout << "Введите координаты ферзя: "; cin >> ferzX >> ferzY;
    cout << "Введите координаты пешки: "; cin >> peshkaX >> peshkaY;
    if (ferzX > 8 || ferzX < 0 || ferzY > 8 || ferzY < 0 || peshkaX > 8 || peshkaX < 0 || peshkaY > 8 || peshkaY < 0) {
        cout << "Однако. Вы уверены, что фигуры находятся на доске?";
    }
    else if ((ferzX == peshkaX) && (ferzY == peshkaY)) {
        cout << "Однако. Вы уверены, что фигуры не стоят в одно и том же месте?";
    }
    else {
        if (ferz(ferzX, ferzY, peshkaX, peshkaY)) {
            cout << "Ферзь бъёт пешку." << endl;
        }
        else {//if (ferz(ferzX, ferzY, peshkaX, peshkaY + 1) && (peshkaY + 1 <= 8)) {
            cout << "Ферзь может побить пешку на следующем ходу." << endl;
        }
        if (peshka(peshkaX, peshkaY, ferzX, ferzY)) {
            cout << "Пешка бьёт ферзя." << endl;
        }
    }
    //else if (ferz(ferzX, ferzY, peshkaX - 1, peshkaY + 1) || ferz(ferzX, ferzY, peshkaX + 1, peshkaY + 1)) {
    //    cout << "Пешка может побить ферзя на следующем ходу." << endl;
    //}
} // (+?)

bool CompareDotWithLine(long double lineX1, long double lineY1, long double lineX2, long double lineY2, long double dotX, long double dotY, string where) {
    if (where == "under") {
        long double tgA = (lineY2 - lineY1) / (lineX2 - lineX1);
        long double B = (lineY1 - tgA * lineX1);
        if (dotY <= tgA * dotX + B) { return true; }
        else { return false; }
    }
    else if (where == "upper") {
        long double tgA = (lineY2 - lineY1) / (lineX2 - lineX1);
        long double B = (lineY1 - tgA * lineX1);
        if (dotY >= tgA * dotX + B) { return true; }
        else { return false; }
        // return (dotY >= tgA * dotX + B) ? (true) : (false);
    }
    else {throw("Неудовлетворительный аргумент функции"); }
    
    // (where == "under") ? (long double tgA = (lineY2 - lineY1) / (lineX2 - lineX1), long double B = (lineY1 - tgA * lineX1)) : (1);
}
void B7_1_5() {
    long double x1, x2, x3, y1, y2, y3, x0, y0;
    cout << "Координаты 1 вершины треугольника: "; cin >> x1 >> y1;
    cout << "Координаты 2 вершины треугольника: "; cin >> x2 >> y2;
    cout << "Координаты 3 вершины треугольника: "; cin >> x3 >> y3;
    cout << "Координаты точки: "; cin >> x0 >> y0;
    
    // Делаем так, чтобы по оси Ox сначала шла точка x1, потом x2, и уже после x3
    bool operation_done = true;
    double k;
    while (operation_done == true) {
        operation_done = false;
        //if (x2 < x1) { k = x1; x1 = x2; x2 = k; k = y1; y1 = y2; y2 = k; operation_done = true; }
        //if (y2 < y3) { k = x3; x3 = x2; x2 = k; k = y3; y3 = y2; y2 = k; operation_done = true; }
        (x2 < x1) ? (k = x1, x1 = x2, x2 = k, k = y1, y1 = y2, y2 = k, operation_done = true) : (1);
        (y2 < y3) ? (k = x3, x3 = x2, x2 = k, k = y3, y3 = y2, y2 = k, operation_done = true) : (1);
    }
    
    cout << x1 << " " << y1 << " || " << x2 << " " << y2 << " || " << x3 << " " << y3 << endl;
    
    // Проверяем, находится ли точка в прямоугольнике, в который вписан наш треугольник
    if ((x0 < x1) || (x0 > x3) || (y0 > max(y1, max(y2, y3))) || (y0 < min(y1, min(y2, y3)))) {
        cout << "NO"; }
    else {
        if (CompareDotWithLine(x1, y1, x2, y2, x0, y0, "under")
            && CompareDotWithLine(x1, y1, x3, y3, x0, y0, "upper")
            && CompareDotWithLine(x3, y3, x2, y2, x0, y0, "upper")) {
            cout << "YES";
        }
        else { cout << "NO"; }
        
        /* cout << (CompareDotWithLine(x1, y1, x2, y2, x0, y0, "under")
            && CompareDotWithLine(x1, y1, x3, y3, x0, y0, "upper")
            && CompareDotWithLine(x3, y3, x2, y2, x0, y0, "upper")) ? ("YES") : ("NO"); */
    }
    
    /* cout << ((x0 < x1) || (x0 > x3) || (y0 > max(y1, max(y2, y3))) || (y0 < min(y1, min(y2, y3)))) ? ("NO") : (
        (CompareDotWithLine(x1, y1, x2, y2, x0, y0, "under")
            && CompareDotWithLine(x1, y1, x3, y3, x0, y0, "upper")
            && CompareDotWithLine(x3, y3, x2, y2, x0, y0, "upper")) ? ("YES") : ("NO") ) */
} // (+-) Надо сделать второй вариант с операндом "?"

int Int_to_Binary_only_print(int num) {
    int i = 32;
    while (i >= 0) {
        cout << ((num >> i) & 1);
        i--;
    }
    return 0;
}
void B7_1_6() {
    unsigned int num;
    cout << "Введите число: "; cin >> num;

    // Выводим число в двоичном виде (для проверки)
    Int_to_Binary_only_print(num);
    cout << endl;
    
    // Выводим значения отдельных битов
    cout << (num & 1) << endl;
    cout << ((num >> 1) & 1) << endl;
    cout << ((num >> 15) & 1) << endl;
    
    // Инвертируеем значения 15 и 7 битов
    num = num ^ 0b1000000010000000;
    cout << endl << (num) << endl;
    
    // Выводим изменённое число в двоичном виде (для проверки)
    Int_to_Binary_only_print(num);
} // (+)

int main() {
    setlocale(LC_ALL, "Russian");
    while (true) {
        int n;
        cout << "\nВариант 7B\n(1) - Задание 1.1 - Вычисление по формуле\n(2) - Задание 1.2 - Область на плоскости\n(3) - Задание 1.3 - Условный оператор\n(4) - Задание 1.4 - Шахматы\n(5) - Задание 1.5 - Точка в треугольнике\n(6) - Задание 1.6 - Побитовые операции\n";
        cin >> n;
        cout << "//////////////////////////////////////////////////////" << endl;
        if (n == 1) { B7_1_1(); }
        else if (n == 2) { B7_1_2(); }
        else if (n == 3) { B7_1_3(); }
        else if (n == 4) { B7_1_4(); }
        else if (n == 5) { B7_1_5(); }
        else if (n == 6) { B7_1_6(); }
        cout << endl << "//////////////////////////////////////////////////////" << endl;
    }
    return 0;
}
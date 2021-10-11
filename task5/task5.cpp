// task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4, A1, A2, B1, B2, C1, C2, x, y;
    cout << "1 vidrizok: " << endl; //введення координат кінців відрізків
    cout << "x1: ";
    cin >> x1;
    cout << "y1: ";
    cin >> y1;
    cout << "x2: ";
    cin >> x2;
    cout << "y2: ";
    cin >> y2;
    cout << "2 vidrizok: " << endl;
    cout << "x3: ";
    cin >> x3;
    cout << "y3: ";
    cin >> y3;
    cout << "x4: ";
    cin >> x4;
    cout << "y4: ";
    cin >> y4;
    A1 = y2 - y1; //обчислення коефіцієнтів рівнянь прямих
    A2 = y4 - y3;
    B1 = x1 - x2;
    B2 = x3 - x4;
    C1 = y1 * y2 - y2 * x1;
    C2 = y3 * x4 - y4 * x3;
    if ((A1 * B2 - A2 * B1) != 0) {   //перевірка умови паралельності прямих
        x = (C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1);
        y = (A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1);
        if (((x >= x1 && x <= x2) || (x <= x1 && x >= x2)) && ((y >= y1 && y <= y2) || (y <= y1 && y >= y2))) cout << "maut tochky peretynu";//перевірка умови, чи точка перетину належить відрізку
        else cout << "ne peretynautsa";
    }
    else {
        if ((A1 * C2 - C1 * A2) != 0) cout << "tochok peretynu nemae";//перевірка умови для відрізків,що лежать на одній прямій: накладаються або не мають спільних точок
        else {
            if (((x3 > x1) && (x3 < x2)) || ((x4 > x1) && (x4 < x2)) || ((x3 > x2) && (x3 < x1)) || ((x4 > x2) && (x4 < x1))) cout << "vidrizky naklalys";
            else cout << "peretynu nemae";
        }
    }
}


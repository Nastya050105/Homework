#include <iostream>
#include <algorithm>

using namespace std;

bool pers(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    long long v1, v2, v3, v4;

    v1 = (bx2 - bx1) * (ay1 - by1) - (by2 - by1) * (ax1 - bx1); // находим векторные произведения
    v2 = (bx2 - bx1) * (ay2 - by1) - (by2 - by1) * (ax2 - bx1);
    v3 = (ax2 - ax1) * (by1 - ay1) - (ay2 - ay1) * (bx1 - ax1);
    v4 = (ax2 - ax1) * (by2 - ay1) - (ay2 - ay1) * (bx2 - ax1);
    if (v1 * v2 == 0 && v3 * v4 == 0) // если лежат на одной прямой
        if (ay1 == by1) { // вертикальной
            if (ax1 > ax2) { swap(ax1, ax2); swap(ay1, ay2); }
            if (bx1 > bx2) { swap(bx1, bx2); swap(by1, by2); };
            return (bx1 - ax2) * (bx2 - ax1) <= 0; // условие пересечения на прямой
        }
        else { // или любой другой
            if (ay1 > ay2) { swap(ax1, ax2); swap(ay1, ay2); }
            if (by1 > by2) { swap(bx1, bx2); swap(by1, by2); }
            return (by1 - ay2) * (by2 - ay1) <= 0; // условие пересечения на прямой
        }
    return ((v1 * v2 <= 0) && (v3 * v4 <= 0)); // условие пересечения на плоскости
}

int main()
{
    int x[4], y[4];
    for (int z = 0; z < 4; z++) cin >> x[z] >> y[z]; // загружаем координаты
    if (pers(x[0], y[0], x[1], y[1], x[2], y[2], x[3], y[3])) { cout << "Yes"; return 0; } // есть точки
    cout << "No";
    return 0;
}
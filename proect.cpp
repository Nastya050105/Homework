#include <cstdlib>
#include <numeric>
#include <vector>
#include <iostream>

struct Point { int x, y; };
using Poly = std::vector<Point>;

unsigned long long get_area_x2(const Poly& poly)
{ // Вычисление удвоенной площади многоугольника
    long long a = 0;

    for (Poly::const_iterator itp = poly.end() - 1, it = poly.begin();
        it != poly.end();
        itp = it++)
        a += (long long)it->x * itp->y - (long long)itp->x * it->y;

    return std::abs(a);
}

unsigned count_boundary(const Poly& poly)
{ // Вычисление количества целочисленных точек на границе многоугольника
    unsigned n_boundary = 0;

    for (Poly::const_iterator itp = poly.end() - 1, it = poly.begin();
        it != poly.end();
        itp = it++)
        n_boundary += std::gcd(it->x - itp->x, it->y - itp->y);

    return n_boundary;
}

int main()
{
    unsigned n = 0;
    std::cin >> n;

    Poly poly(n);
    for (Point& p : poly)
        std::cin >> p.x >> p.y;

    unsigned long long area_x2 = get_area_x2(poly);
    // Удвоенная площадь многоугольника

    unsigned n_boundary = count_boundary(poly);
    // Количество целочисленных точек на границе

    unsigned long long n_inside = (area_x2 + 2 - n_boundary) / 2;
    // Из формулы Пика получаем количество точек внутри

    std::cout << n_inside << " " << n_boundary << std::endl;
}
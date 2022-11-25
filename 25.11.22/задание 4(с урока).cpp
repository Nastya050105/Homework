#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[])
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x2 < y1 && y2 < y1) && (x2 >= x1))
    {
        cout << "Вложенный " << x2 << " " << y2 << endl;
        return 0;
    }

    if (x2 == x1 && y1 == y2)
    {
        cout << "Совпадают " << x2 << " " << y2 << endl;
        return 0;
    }

    if (x2 < y1 && y2 > y1)
    {
        cout << "Peresekautsa " << x2 << " " << y1 << endl;
        return 0;
    }

    if (y2 > x1 && x2 < x1)
    {
        cout << "Peresekautsa " << x1 << " " << y2 << endl;
        return 0;
    }

    cout << "NE Peresekautsa " << endl;



    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const* argv[])
{
    double R, r, l, d; 
    cin >> R >> r >> l >> d;
    if (d + r >= R)
    {
        cout << 'YES';
        return 0;
    }
    if (sqrt(pow(R, 2) - pow(r, 2)) + (d - r) >= l)
    {
        cout << "YES";
        return 0;
    }
    else
    {
        cout << "NO";
        return 0;
    }

    return 0;
}
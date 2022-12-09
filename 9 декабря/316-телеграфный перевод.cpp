#include <string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char const* argv[])
{
    int zarpl, comissiya, ostatok, sotka;
    cin >> zarpl;
    sotka = zarpl / 107;
    ostatok = zarpl % 107;
    if (ostatok > 7)
    {
        cout << sotka * 100 + ostatok - 7 << " " << sotka * 7 + 7;
    }
    else
    {
        cout << sotka * 100 << " " << sotka * 7;
    }
    return 0;
}
#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    long n;
    int i = 0;
    cin >> n;

    if (n > 3)
    {
        i++;
    }

    while (n > 1)
    {
        i += n / 2;
        n = n / 2 + n % 2;
    }

    cout << i;
    return 0;
}
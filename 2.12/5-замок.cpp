#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    unsigned long long n, k;
    cin >> n >> k;
    unsigned long long i = n * (1 + k) * k/ 2 - (k + 1) * (k - 1);
    cout << i;

    return 0;
}
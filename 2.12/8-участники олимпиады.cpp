#include <iostream>

using namespace std;

int main()
{
    unsigned int n, m, k, c, t;
    cin >> n >> m >> k >> c ;

    if ((k * m * n - k * m - m * n - n * k) > 0)
    {
        t = c * k * m * n / (k * m * n - k * m - m * n - n * k);
    }
    else
    {
        cout << -1;
        return 0;
    }

    if (t > 0 && t % k == 0 && t % m == 0 && t % n == 0 && t / k + t / m + t / n + c == t)
    {
        cout << t;
    }
    else
    {
        cout << -1;
    }

    return 0;
}
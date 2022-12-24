#include <iostream>
using namespace std;
int main()
{
    int k, m, n;
    cin >> k >> m >> n;
    if (n <= k) m = 2 * m;
    else if (n * 2 % k == 0) m = m * (n * 2 / k);
    else m = m * (1 + (n * 2 / k));
    cout << m << endl;
}
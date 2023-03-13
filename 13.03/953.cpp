#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
bool isPrime(int n) {
    if (n <= 1) { // если число меньше или равно 1, то оно не является простым
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) { // перебираем возможные делители от 2 до корня из n
        if (n % i == 0) { // если n делится на i без остатка, то n не является простым
            return false;
        }
    }
    return true; // если ни один делитель не подошел, то n является простым
}
*/

int main() {
    int m, n;
    cin >> m >> n;

    double fraction = (double)m / n;
    vector<int> result;

    for (int i = 2; i <= n; i++) 
    {
        if (fraction == 0)
        {
            break;
        }
        if (fraction >= 1.0 / i)
        {
            result.push_back(i);
            fraction -= 1.0 / i;
        }
    }

    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i] << " ";
    }

    return 0;
}

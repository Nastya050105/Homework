#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    int c = 0;
    cin >> n >> k;
    vector <int> a(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    while (a.size() > 1)
    {
        c += k - 1;
        c = c % a.size();
        a.erase(a.begin() + c);
    }

    cout << a[0];
    return 0;
}
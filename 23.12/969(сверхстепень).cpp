#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 2 % m;
    for (int i = 1; i <= n; ++i) {
        ans = (ans * ans) % m;
    }
    cout << ans;
    return 0;
}
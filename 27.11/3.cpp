#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n +1; i++) {
        if (i == n)
        {
            cout << i + 1 << endl;
        }
    }
    return 0;
}
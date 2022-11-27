#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, c = 0;
    int summ = 0;
    cin >> n;
    string s;
    for (int i = 100; i < 1000; i++)
    {
        s = to_string(i);
        summ = (s[0] - 48) + (s[1] - 48) + (s[2] - 48);
        if (summ == n)
        {
            c++;
            continue;
        }
    }
    cout << c << endl;

    return 0;
}
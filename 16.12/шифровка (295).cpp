#include<iostream>
#include<cmath>
#include <string>


using namespace std;

int main() {
    string s, f, dop;
    getline(cin, s);
    getline(cin, f);
    int n{ 100 }, count{}, m;
    for (int i = 0; i <= 25; i++)
    {
        for (int j = 0; j < f.size(); j++)
        {
            if (f[j] + i > 90) dop += 64 + (f[j] + i) % 90;
            else dop += f[j] + i;
        }
        if (s.find(dop) != -1 || s == dop)
        {
            n = i;
            goto out;
        }
        dop = "";
    }

out:
    if (n == 100)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - n < 65) cout << char(90 - (64 - (s[i] - n)));
        else cout << char(s[i] - n);
    }
}

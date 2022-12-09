#include <string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, m;
    cin >> n;
    vector <int> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        arr.push_back(m);
    }

    sort(arr.begin(), arr.end());

    for (auto l : arr)
    {
        cout << l << " ";
    }

    return 0;
}



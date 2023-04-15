#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция проверки, является ли последовательность кодом Грея
bool isGrayCode(const vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int diff = v[i] ^ [v(i + 1) % n]; // XOR двух соседних элементов
        if ((diff & (diff - 1)) != 0) { // проверяем, что различаются только в одной цифре
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> v[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        swap(v[a], v[b]);
        if (isGrayCode(v)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}
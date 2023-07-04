#include <iostream>
#include <vector>

using namespace std;

int countWays(vector<vector<char>>& floor, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Инициализация базовых случаев
    dp[0][0] = 1;
    for (int i = 1; i < m; i++) {
        if (floor[0][i] == '.') {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        if (floor[i][0] == '.') {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // Заполнение динамической таблицы
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (floor[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> floor(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> floor[i][j];
        }
    }

    int ways = countWays(floor, n, m);

    cout << ways << endl;

    return 0;
}

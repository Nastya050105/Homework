#include <iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
    int m, n, a, b, p;
    scanf("%d %d %d %d %d", &m, &n, &a, &b, &p);
    vector<vector<int > > r, res;
    for (int i = 0; i < n; ++i) {
        vector<int> t(n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &t[j]);
            t[j] %= p;
        }
        r.push_back(t);
    }
    res = r;
    for (int k = 0; k < m - 1; ++k) {
        vector<vector<int>  > temp;
        for (int i = 0; i < n; ++i) {
            vector<int> t(n);
            for (int j = 0; j < n; ++j) {
                scanf("%d", &t[j]);
            }
            temp.push_back(t);
        }
        for (int i = 0; i < r.size(); ++i) {
            for (int j = 0; j < r[i].size(); ++j) {
                int s = 0;
                for (int h = 0; h < n; ++h)
                    s += r[i][h] * temp[h][j];
                res[i][j] = s % p;
            }
        }
        r = res;
    }
    printf("%d ", res[a - 1][b - 1]);
    return 0;
}
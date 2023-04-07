#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& adjMatrix, vector<bool>& visited, int peak, int& count)
{
    visited[peak] = true;
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        if (adjMatrix[peak][i] == 1 && !visited[i])
        {
            count++;
            dfs(adjMatrix, visited, i, count);
        }
    }
}

int main()
{
    int N, S;
    cin >> N >> S;

    vector<vector<int>> adjMatrix(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    S--;

    vector<bool> visited(N, false);
    int count = 0;
    dfs(adjMatrix, visited, S, count);
    cout << count << endl;
    return 0;
}
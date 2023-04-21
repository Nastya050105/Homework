#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); 

int main() {
    int n, m;
    cin >> n;

    vector<int> cost(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    cin >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--; 
        adj[u].push_back({ v, cost[u] }); 
        adj[v].push_back({ u, cost[v] }); 
    }

    vector<int> dist(n, INF);
    dist[0] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({ 0, 0 }); 

    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (w > dist[u])
        {
            continue; 
        }

        for (auto& edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v }); 
            }
        }
    }

    if (dist[n - 1] == INF)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dist[n - 1] << "\n";
    }

    return 0;
}
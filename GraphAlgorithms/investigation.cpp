#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;
const long long MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    vector<long long> dist(n + 1, INF);
    vector<long long> ways(n + 1, 0);
    vector<int> minFlights(n + 1, INT_MAX);
    vector<int> maxFlights(n + 1, 0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[1] = 0;
    ways[1] = 1;
    minFlights[1] = 0;
    maxFlights[1] = 0;

    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [currCost, u] = pq.top();
        pq.pop();

        if (currCost > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w)
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<long long>> dist(n + 1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    pq.push({0, 1});
    dist[1].push_back(0);

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u].size() > k || (dist[u].size() == k && d > dist[u].back()))
            continue;

        for (auto [v, w] : adj[u])
        {
            long long newDist = d + w;
            if (dist[v].size() < k)
            {
                dist[v].push_back(newDist);
                pq.push({newDist, v});
                sort(dist[v].begin(), dist[v].end());
            }
            else if (newDist < dist[v].back())
            {
                dist[v].pop_back();
                dist[v].push_back(newDist);
                pq.push({newDist, v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }

    for (auto val : dist[n])
        cout << val << " ";
    cout << endl;

    return 0;
}

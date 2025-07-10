#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

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

    vector<vector<long long>> dist(2, vector<long long>(n + 1, LLONG_MAX));
    dist[0][1] = 0;
    dist[1][1] = 0;
    int used = 0;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> q;
    q.push({0, 1, 0});
    while (!q.empty())
    {
        auto [cost, node, used] = q.top();
        q.pop();
        if (dist[used][node] < cost)
        {
            continue;
        }
        for (auto [neigh, price] : adj[node])
        {
            // not use coupon
            if (dist[used][neigh] > dist[used][node] + price)
            {
                dist[used][neigh] = dist[used][node] + price;
                q.push({dist[used][neigh], neigh, used});
            }
            // use coupon only if not used before
            if (used == 0 && (dist[1][neigh] > dist[used][node] + (price / 2)))
            {
                dist[1][neigh] = dist[used][node] + (price / 2);
                q.push({dist[1][neigh], neigh, 1});
            }
        }
    }

    cout << dist[1][n] << endl;
    return 0;
}

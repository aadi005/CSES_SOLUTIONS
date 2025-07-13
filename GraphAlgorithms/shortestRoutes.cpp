#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjLst(n + 1, vector<pair<int, int>>());

    for (int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        adjLst[a].push_back({b, c});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    vector<long long> dist(n + 1, LLONG_MAX);
    q.push({0, 1});
    dist[1] = 0;

    while (!q.empty())
    {
        auto [cost, node] = q.top();
        q.pop();
        if (cost > dist[node])
        {
            continue;
        }
        for (auto [neigh, time] : adjLst[node])
        {
            if (dist[neigh] > cost + time)
            {
                dist[neigh] = cost + time;
                q.push({dist[neigh], neigh});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
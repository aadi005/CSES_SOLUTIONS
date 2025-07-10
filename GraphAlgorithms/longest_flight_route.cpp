#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    vector<int> topo;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neigh : adj[node])
        {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }

    vector<int> dist(n + 1, INT_MIN);
    vector<int> par(n + 1, -1);
    dist[1] = 1;

    for (int node : topo)
    {
        if (dist[node] == INT_MIN)
            continue;

        for (int neigh : adj[node])
        {
            if (dist[neigh] < dist[node] + 1)
            {
                dist[neigh] = dist[node] + 1;
                par[neigh] = node;
            }
        }
    }

    if (dist[n] == INT_MIN)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    for (int curr = n; curr != -1; curr = par[curr])
    {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

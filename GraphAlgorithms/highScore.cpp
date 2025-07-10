#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

const int MAX_N = 2501;
const int MAX_M = 5001;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Edge
{
    int from, to;
    ll weight;
} edges[MAX_M];

int n, m;
ll dist[MAX_N];
bool visited[MAX_N], visitedRev[MAX_N];
vector<int> graph[MAX_N], reverseGraph[MAX_N];

void dfs(int node)
{
    visited[node] = true;
    for (int next : graph[node])
    {
        if (!visited[next])
            dfs(next);
    }
}

void dfsReverse(int node)
{
    visitedRev[node] = true;
    for (int next : reverseGraph[node])
    {
        if (!visitedRev[next])
            dfsReverse(next);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges[i] = {u, v, -w};
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }

    dfs(1);
    dfsReverse(n);

    fill(dist + 2, dist + n + 1, INF);

    bool updated = true;
    for (int i = 0; i < n && updated; i++)
    {
        updated = false;
        for (int j = 0; j < m; j++)
        {
            int u = edges[j].from;
            int v = edges[j].to;
            ll w = edges[j].weight;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                updated = true;

                if (i == n - 1 && visited[v] && visitedRev[v])
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -dist[n] << endl;
    return 0;
}
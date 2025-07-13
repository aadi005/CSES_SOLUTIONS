#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int parent[MAX_N];

int start = -1, endNode = -1;

bool dfs(int node, int par)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (neighbor == par)
            continue;
        if (visited[neighbor])
        {
            start = neighbor;
            endNode = node;
            return true;
        }
        parent[neighbor] = node;
        if (dfs(neighbor, node))
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
                break;
        }
    }

    if (start == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = endNode; v != start; v = parent[v])
        {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        cout << cycle.size() << "\n";
        for (int x : cycle)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

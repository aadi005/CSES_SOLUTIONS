#include <iostream>
#include <vector>

using namespace std;
const int maxN = 2e5 + 1, logN = 20;

int n, q;
vector<int> parent(maxN), depth(maxN), compID(maxN), cycleLen(maxN);
vector<int> ds(maxN, -1);
vector<vector<int>> graph(maxN, vector<int>());
int p[logN][maxN];
vector<int> cycleRoots;
vector<bool> visited(maxN, false);

int find(int u)
{
    if (ds[u] < 0)
    {
        return u;
    }
    return ds[u] = find(ds[u]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return false;
    }
    if (ds[u] < ds[v])
    {
        swap(u, v);
    }
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

void dfs(int u, int cid)
{
    visited[u] = true;
    compID[u] = cid;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            depth[v] = depth[u] + 1;
            dfs(v, cid);
        }
        else
        {
            cycleLen[u] = depth[u] + 1;
        }
        cycleLen[u] = max(cycleLen[u], cycleLen[v]);
    }
}

void init()
{
    for (int i = 1; i < logN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
}

int moveUp(int u, int k)
{
    for (int i = logN - 1; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            u = p[i][u];
        }
    }
    return u;
}

int query(int a, int b)
{
    if (a == b)
    {
        return 0;
    }

    if (compID[a] != compID[b])
    {
        return -1;
    }

    if (cycleLen[a])
    {
        if (!cycleLen[b])
        {
            return -1;
        }
        int len = cycleLen[a];
        return (depth[a] - depth[b] + len) % len;
    }

    if (!cycleLen[b])
    {
        if (depth[a] <= depth[b])
        {
            return -1;
        }
        int dist = depth[a] - depth[b];
        return moveUp(a, dist) == b ? dist : -1;
    }

    int root = a;
    for (int i = logN - 1; i >= 0; i--)
    {
        int up = p[i][root];
        if (!cycleLen[up])
        {
            root = up;
        }
    }
    root = p[0][root];
    return (depth[a] - depth[root]) + query(root, b);
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {

        cin >> p[0][i];
        graph[p[0][i]].push_back(i);
        if (!merge(i, p[0][i]))
        {
            cycleRoots.push_back(p[0][i]);
        }
    }

    init();
    int id = 1;
    for (int root : cycleRoots)
    {
        dfs(root, id++);
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }

    return 0;
}

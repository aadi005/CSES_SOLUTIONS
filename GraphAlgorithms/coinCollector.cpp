#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m, numComponents;
vector<ll> coins;
vector<vector<int>> graph, reverseGraph, condensedGraph;
vector<bool> visited;
vector<int> order, componentNodes, rootComponent;
vector<ll> componentCoins, maxCoinsFrom;

void dfs1(int node)
{
    visited[node] = true;
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs1(neighbor);
        }
    }
    order.push_back(node);
}

void dfs2(int node)
{
    visited[node] = true;
    componentNodes.push_back(node);
    for (int neighbor : reverseGraph[node])
    {
        if (!visited[neighbor])
        {
            dfs2(neighbor);
        }
    }
}

void dfs3(int comp)
{
    visited[comp] = true;
    maxCoinsFrom[comp] = componentCoins[comp];
    for (int nextComp : condensedGraph[comp])
    {
        if (!visited[nextComp])
        {
            dfs3(nextComp);
        }
        maxCoinsFrom[comp] = max(maxCoinsFrom[comp], componentCoins[comp] + maxCoinsFrom[nextComp]);
    }
}

int main()
{
    cin >> n >> m;
    coins.resize(n + 1);
    graph.resize(n + 1);
    reverseGraph.resize(n + 1);
    visited.resize(n + 1, false);
    rootComponent.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }

    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }

    reverse(order.begin(), order.end());
    fill(visited.begin(), visited.end(), false);

    componentCoins.push_back(0); // dummy for 1-based indexing
    for (int node : order)
    {
        if (!visited[node])
        {
            dfs2(node);
            numComponents++;
            ll total = 0;
            for (int x : componentNodes)
            {
                total += coins[x];
                rootComponent[x] = numComponents;
            }
            componentCoins.push_back(total);
            componentNodes.clear();
        }
    }

    condensedGraph.resize(numComponents + 1);
    for (int u = 1; u <= n; u++)
    {
        for (int v : graph[u])
        {
            int cu = rootComponent[u];
            int cv = rootComponent[v];
            if (cu != cv)
            {
                condensedGraph[cu].push_back(cv);
            }
        }
    }

    visited.assign(numComponents + 1, false);
    maxCoinsFrom.resize(numComponents + 1, 0);

    for (int i = 1; i <= numComponents; i++)
    {
        if (!visited[i])
        {
            dfs3(i);
        }
    }

    ll answer = 0;
    for (int i = 1; i <= numComponents; i++)
    {
        answer = max(answer, maxCoinsFrom[i]);
    }

    cout << answer << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAX_N = 501;
const int MAX_M = 1001;
const int INF = 0x3f3f3f3f;

int n, m;
int parent[MAX_N];
int capacity[MAX_N][MAX_N];
bool used[MAX_M];

vector<vector<int>> residualGraph(MAX_N);
vector<pair<int, int>> edgeList[MAX_N];
vector<int> path;

int bfs(int source = 1, int sink = n)
{
    fill(parent + 1, parent + n + 1, -1);
    parent[source] = -2;

    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty())
    {
        int node = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int neighbor : residualGraph[node])
        {
            if (parent[neighbor] == -1 && capacity[node][neighbor])
            {
                parent[neighbor] = node;
                int newFlow = min(flow, capacity[node][neighbor]);
                if (neighbor == sink)
                    return newFlow;
                q.push({neighbor, newFlow});
            }
        }
    }

    return 0;
}

void dfs(int node = 1)
{
    path.push_back(node);
    if (node == n)
        return;

    for (auto [next, id] : edgeList[node])
    {
        if (capacity[node][next] == 0 && !used[id])
        {
            used[id] = true;
            dfs(next);
            return;
        }
    }
}

int maxFlow(int source = 1, int sink = n)
{
    int totalFlow = 0, newFlow;

    while ((newFlow = bfs(source, sink)))
    {
        totalFlow += newFlow;
        int curr = sink;
        while (curr != source)
        {
            int prev = parent[curr];
            capacity[prev][curr] -= newFlow;
            capacity[curr][prev] += newFlow;
            curr = prev;
        }
    }

    return totalFlow;
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        edgeList[u].push_back({v, i});
        residualGraph[u].push_back(v);
        residualGraph[v].push_back(u);
        capacity[u][v]++;
    }

    int maxDays = maxFlow();
    printf("%d\n", maxDays);

    for (int i = 0; i < maxDays; i++)
    {
        path.clear();
        dfs();
        printf("%lu\n", path.size());
        for (int j = 0; j < path.size(); j++)
        {
            printf("%d%c", path[j], (j == path.size() - 1 ? '\n' : ' '));
        }
    }

    return 0;
}

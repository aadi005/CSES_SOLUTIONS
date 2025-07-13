#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<long long>> flowMatrix;
vector<vector<int>> adjMat;
vector<int> par;

long long bfs()
{
    queue<pair<int, long long>> q;
    q.push({1, LLONG_MAX});
    fill(par.begin(), par.end(), -1);
    par[1] = -2;

    while (!q.empty())
    {
        auto [node, currFlow] = q.front();
        q.pop();

        for (int next : adjMat[node])
        {
            if (par[next] == -1 && flowMatrix[node][next] > 0)
            {
                par[next] = node;
                long long newFlow = min(currFlow, flowMatrix[node][next]);
                if (next == n)
                {
                    return newFlow;
                }
                q.push({next, newFlow});
            }
        }
    }
    return 0;
}

void markReachable(vector<bool> &reachable)
{
    queue<int> q;
    q.push(1);
    reachable[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int next : adjMat[node])
        {
            if (!reachable[next] && flowMatrix[node][next] > 0)
            {
                reachable[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    flowMatrix.resize(n + 1, vector<long long>(n + 1, 0));
    adjMat.resize(n + 1);
    par.resize(n + 1, -1);
    vector<pair<int, int>> originalEdges;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adjMat[a].push_back(b);
        adjMat[b].push_back(a);

        flowMatrix[a][b] += 1;
        flowMatrix[b][a] += 1;

        originalEdges.push_back({a, b});
    }

    long long nextFlow = bfs();
    while (nextFlow > 0)
    {
        int curr = n;
        while (curr != 1)
        {
            int prev = par[curr];
            flowMatrix[prev][curr] -= nextFlow;
            flowMatrix[curr][prev] += nextFlow;
            curr = prev;
        }

        nextFlow = bfs();
    }

    vector<bool> reachable(n + 1, false);
    markReachable(reachable);

    vector<pair<int, int>> cutEdges;
    for (auto [a, b] : originalEdges)
    {
        if (reachable[a] && !reachable[b])
        {
            cutEdges.push_back({a, b});
        }
        else if (reachable[b] && !reachable[a])
        {
            cutEdges.push_back({b, a});
        }
    }

    cout << cutEdges.size() << "\n";
    for (auto [a, b] : cutEdges)
    {
        cout << a << " " << b << "\n";
    }

    return 0;
}

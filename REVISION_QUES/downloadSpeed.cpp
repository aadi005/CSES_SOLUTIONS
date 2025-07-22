// Endmons-Karp Algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// https://cses.fi/problemset/task/1694/ - Download Speed
// Hint - 1. Find Max flow of data

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
                long long newFlow = min(currFlow, flowMatrix[node][next]);
                par[next] = node;
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

int main()
{
    cin >> n >> m;
    flowMatrix.resize(n + 1, vector<long long>(n + 1, 0));
    adjMat.resize(n + 1, vector<int>());
    par.resize(n + 1, -1);

    for (int i = 0, a, b; i < m; i++)
    {
        long long c;
        cin >> a >> b >> c;
        if (flowMatrix[a][b] == 0)
        {
            adjMat[a].push_back(b);
            adjMat[b].push_back(a);
        }

        flowMatrix[a][b] += c;
    }

    long long ans = 0;
    long long nextFlow = bfs();
    while (nextFlow > 0)
    {
        ans += nextFlow;
        int curr = n;
        while (curr != 1)
        {
            flowMatrix[par[curr]][curr] -= nextFlow;
            flowMatrix[curr][par[curr]] += nextFlow;
            curr = par[curr];
        }

        nextFlow = bfs();
    }

    cout << ans << endl;
}

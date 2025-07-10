#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    unordered_set<int> shops;

    for (int i = 0; i < k; i++)
    {
        int j;
        cin >> j;
        shops.insert(j);
    }

    vector<vector<int>> adjMat(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjMat[a].push_back(b);
        adjMat[b].push_back(a);
    }
    queue<int> q;
    vector<int> source(n + 1, -1);
    vector<int> dist(n + 1, INT_MAX);
    vector<int> source2(n + 1, -1);
    vector<int> dist2(n + 1, INT_MAX);
    for (int i : shops)
    {
        source[i] = i;
        dist[i] = 0;
        q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i : adjMat[u])
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = dist[u] + 1;
                source[i] = source[u];
                q.push(i);
            }
            else
            {
                if (source[i] != source[u] && dist2[i] > dist[u] + 1)
                {
                    dist2[i] = dist[u] + 1;
                    source2[i] = source[u];
                    q.push(i);
                }
                else if (dist2[u] != INT_MAX && dist2[i] > dist2[u] + 1)
                {
                    dist2[i] = dist2[u] + 1;
                    source2[i] = source2[u];
                    q.push(i);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (shops.find(i) != shops.end())
        {
            int minDist = INT_MAX;
            for (int j : adjMat[i])
            {
                if (source[j] != i && dist[j] != INT_MAX)
                {
                    minDist = min(minDist, dist[j] + 1);
                }
                if (source2[j] != i && dist2[j] != INT_MAX)
                {
                    minDist = min(minDist, dist2[j] + 1);
                }
            }
            if (minDist == INT_MAX)
            {
                minDist = -1;
            }
            cout << minDist << " ";
        }
        else
        {
            if (dist[i] == INT_MAX)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << dist[i] << " ";
            }
        }
    }
    cout << endl;

    return 0;
}
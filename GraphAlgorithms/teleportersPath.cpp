#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int> &ans, vector<vector<pair<int, int>>> &adjMat, int i, vector<bool> &vis)
{

    while (!adjMat[i].empty())
    {
        auto [k, edge] = adjMat[i].back();
        adjMat[i].pop_back();
        vis[edge] = true;
        dfs(ans, adjMat, k, vis);
    }

    ans.push_back(i);
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjMat(n + 1, vector<pair<int, int>>());
    vector<int> in(n + 1, 0), out(n + 1, 0);
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adjMat[a].push_back({b, i});
        out[a]++;
        in[b]++;
    }

    int numOfOddDegrees = 0;
    for (int i = 1; i <= n; i++)
    {
        if (out[i] - in[i] == 1)
        {
            if (i != 1)
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        else if (in[i] - out[i] == 1)
        {
            if (i != n)
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        else if (in[i] != out[i])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    if (out[1] - in[1] != 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if (in[n] - out[n] != 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<bool> vis(m, false);
    vector<int> ans;
    dfs(ans, adjMat, 1, vis);
    for (bool k : vis)
    {
        if (!k)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int k : ans)
    {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}

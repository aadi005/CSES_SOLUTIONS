#include <iostream>
#include <vector>

using namespace std;

int endNode = -1;
bool dfs(vector<vector<int>> &adjLst, vector<int> &par, vector<bool> &vis, vector<bool> &pathVis, int i)
{

    vis[i] = true;
    pathVis[i] = true;
    for (int k : adjLst[i])
    {
        if (k == i)
        {
            continue;
        }
        if (pathVis[k])
        {
            par[k] = i;
            endNode = k;
            return true;
        }
        if (!vis[k])
        {
            par[k] = i;
            if (dfs(adjLst, par, vis, pathVis, k))
            {
                return true;
            }
        }
    }
    pathVis[i] = false;
    return false;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjLst(n + 1, vector<int>());
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        adjLst[a].push_back(b);
    }
    vector<int> par(n + 1, -1);
    vector<bool> vis(n + 1, false);
    vector<bool> pathVis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        if (dfs(adjLst, par, vis, pathVis, i))
        {
            // print loop
            int curr = endNode;
            vector<int> ans;
            ans.push_back(curr);
            curr = par[curr];
            while (curr != endNode)
            {
                ans.push_back(curr);
                curr = par[curr];
            }
            ans.push_back(curr);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for (int k : ans)
            {
                cout << k << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}

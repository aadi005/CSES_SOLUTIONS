#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void dfs(int i, vector<bool> &vis, vector<vector<int>> &adjLst)
{
    vis[i] = true;
    for (int k : adjLst[i])
    {
        if (!vis[k])
        {
            dfs(k, vis, adjLst);
        }
    }
    return;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjLst(n + 1, vector<int>());
    vector<vector<int>> revLst(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjLst[a].push_back(b);
        revLst[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    dfs(1, vis, adjLst);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }
    fill(vis.begin(), vis.end(), false);
    dfs(1, vis, revLst);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}

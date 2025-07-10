#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjLst(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjLst[a].push_back(b);
        adjLst[b].push_back(a);
    }
    vector<bool> vis(n + 1, false);
    vector<int> par(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    queue<int> q;
    q.push(1);
    bool found = false;
    vis[1] = true;
    while (!q.empty() && !found)
    {
        int sz = q.size();
        for (int i = 0; i < sz && !found; i++)
        {
            int node = q.front();
            q.pop();
            for (int k : adjLst[node])
            {
                if (!vis[k])
                {
                    par[k] = node;
                    vis[k] = true;
                    q.push(k);
                    if (k == n)
                    {
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    vector<int> ans;

    int curr = n;
    while (par[curr] != curr)
    {
        ans.push_back(curr);
        curr = par[curr];
    }
    ans.push_back(1);
    if (ans.size() == 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
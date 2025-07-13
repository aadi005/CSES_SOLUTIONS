#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;

int var_id(int x)
{
    int id = abs(x) * 2;
    if (x > 0)
        id++;
    return id;
}

void dfs1(stack<int> &st, vector<bool> &vis, int i, vector<vector<int>> &adjLst)
{

    vis[i] = true;

    for (int k : adjLst[i])
    {
        if (!vis[k])
        {
            dfs1(st, vis, k, adjLst);
        }
    }

    st.push(i);
    return;
}

void dfs2(vector<int> &scc, vector<bool> &vis, vector<vector<int>> &adjLst, int i, int p)
{

    vis[i] = true;
    scc[i] = p;

    for (int k : adjLst[i])
    {
        if (!vis[k])
        {
            dfs2(scc, vis, adjLst, k, p);
        }
    }
    return;
}

int main()
{

    cin >> n >> m;
    vector<vector<int>> adjLst(2 * (m + 1), vector<int>());
    vector<vector<int>> revLst(2 * (m + 1), vector<int>());
    for (int i = 0; i < n; i++)
    {
        char c1, c2;
        int a, b;
        cin >> c1 >> a >> c2 >> b;

        if (c1 == '-')
            a = -a;
        if (c2 == '-')
            b = -b;

        int a_id = var_id(a);
        int b_id = var_id(b);

        adjLst[a_id ^ 1].push_back(b_id);
        revLst[b_id].push_back(a_id ^ 1);

        adjLst[b_id ^ 1].push_back(a_id);
        revLst[a_id].push_back(b_id ^ 1);
    }

    stack<int> st;
    vector<bool> vis(2 * (m + 1), false);
    for (int i = 1; i <= ((2 * m) + 1); i++)
    {
        if (vis[i])
        {
            continue;
        }
        dfs1(st, vis, i, adjLst);
    }

    fill(vis.begin(), vis.end(), false);
    int k = 0;
    vector<int> scc(2 * (m + 1));
    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if (!vis[i])
        {
            k++;
            dfs2(scc, vis, revLst, i, k);
        }
    }

    vector<char> ans(m + 1, '#');

    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == '#')
        {
            if (scc[2 * i] == scc[(2 * i) + 1])
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            if (scc[2 * i] < scc[(2 * i) + 1])
            {
                ans[i] = '+';
            }
            else
            {
                ans[i] = '-';
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

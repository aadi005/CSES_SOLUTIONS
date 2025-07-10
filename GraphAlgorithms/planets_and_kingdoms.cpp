#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs1(int i, vector<vector<int>> &adjLst, vector<bool> &vis, stack<int> &st)
{
    vis[i] = true;
    for (int k : adjLst[i])
    {
        if (!vis[k])
        {
            dfs1(k, adjLst, vis, st);
        }
    }
    st.push(i);
}

void dfs2(int i, vector<vector<int>> &adjLst, vector<bool> &vis, vector<int> &ans, int j)
{
    vis[i] = true;
    ans[i] = j;
    for (int k : adjLst[i])
    {
        if (!vis[k])
        {
            dfs2(k, adjLst, vis, ans, j);
        }
    }
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

    stack<int> st;
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i, adjLst, vis, st);
        }
    }

    fill(vis.begin(), vis.end(), false);

    int k = 0;
    vector<int> ans(n + 1, -1);
    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if (!vis[i])
        {
            k++;
            dfs2(i, revLst, vis, ans, k);
        }
    }
    cout << k << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
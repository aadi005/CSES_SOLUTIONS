#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjLst(n + 1, vector<int>());
    vector<int> inDegree(n + 1, 0);
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        inDegree[b]++;
        adjLst[a].push_back(b);
    }

    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int course = q.front();
        q.pop();
        ans.push_back(course);
        for (int k : adjLst[course])
        {
            inDegree[k]--;
            if (inDegree[k] == 0)
            {
                q.push(k);
            }
        }
    }

    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int k : ans)
    {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}

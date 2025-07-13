#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void recurse(vector<vector<int>> &adjMat, vector<bool> &found, priority_queue<int, vector<int>, greater<int>> &q)
{
    if (q.empty())
    {
        return;
    }
    int i = q.top();
    q.pop();
    found[i] = true;
    for (int k : adjMat[i])
    {
        if (!found[k])
        {
            q.push(k);
        }
    }
    recurse(adjMat, found, q);
    cout << i << " ";
    return;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjMat(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adjMat[b].push_back(a);
    }
    vector<bool> found(n + 1, false);
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= n; i++)
    {
        if (!found[i])
        {
            q.push(i);
            recurse(adjMat, found, q);
        }
    }

    cout << endl;
}
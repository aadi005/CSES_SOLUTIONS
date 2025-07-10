#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &adjMat, vector<int> &colour, int i)
{
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        int sz = q.size();
        for (int j = 0; j < sz; j++)
        {
            int node = q.front();
            q.pop();
            int currCol = 1 - colour[node];
            for (int k : adjMat[node])
            {
                if (colour[k] == -1)
                {

                    colour[k] = currCol;
                    q.push(k);
                }
                else if (colour[k] != currCol)
                {
                    return false;
                }
            }
        }
    }
    return true;
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

        adjMat[a].push_back(b);
        adjMat[b].push_back(a);
    }

    vector<int> colour(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (colour[i] == -1)
        {
            colour[i] = 0;
            if (!bfs(adjMat, colour, i))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << colour[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}

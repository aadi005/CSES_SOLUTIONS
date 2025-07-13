#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> adjMat(n + 1, vector<long long>(n + 1, LLONG_MAX));

    for (int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        adjMat[a][b] = min(adjMat[a][b], 1LL * c);
        adjMat[b][a] = min(adjMat[b][a], 1LL * c);
    }

    for (int i = 1; i <= n; i++)
    {
        adjMat[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (adjMat[j][i] == LLONG_MAX || adjMat[i][k] == LLONG_MAX)
                {
                    continue;
                }
                adjMat[j][k] = min(adjMat[j][k], adjMat[j][i] + adjMat[i][k]);
            }
        }
    }

    for (int i = 0, a, b; i < q; i++)
    {
        cin >> a >> b;
        if (adjMat[a][b] == LLONG_MAX)
        {
            cout << -1 << endl;
            continue;
        }
        cout << adjMat[a][b] << endl;
    }
    return 0;
}
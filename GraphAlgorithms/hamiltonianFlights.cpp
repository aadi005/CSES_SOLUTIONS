#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjMat(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjMat[a].push_back(b);
    }

    vector<vector<int>> dp(n + 1, vector<int>(1 << n, 0));
    dp[1][1 << 0] = 1;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((!(mask & (1 << (i - 1)))) || dp[i][mask] == 0)
            {
                continue;
            }

            for (int j : adjMat[i])
            {
                if (!(mask & (1 << (j - 1))))
                {
                    int nextMask = mask | (1 << (j - 1));
                    dp[j][nextMask] += dp[i][mask];
                    dp[j][nextMask] %= MOD;
                }
            }
        }
    }

    cout << dp[n][(1 << n) - 1] << endl;
    return 0;
}

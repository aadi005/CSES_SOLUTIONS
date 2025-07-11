#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int maxN = 11;
const int maxM = 1001;
const ll MOD = 1e9 + 7;

int n, m;
ll dp[maxN][maxM][1 << maxN];

int main()
{
    cin >> n >> m;
    dp[n][0][0] = 1;

    for (int col = 1; col <= m; col++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            dp[0][col][mask << 1] = dp[n][col - 1][mask];
        }

        for (int row = 1; row <= n; row++)
        {
            int x = 1 << (row - 1);
            int y = 1 << row;

            for (int mask = 0; mask < (1 << (n + 1)); mask++)
            {
                dp[row - 1][col][mask] %= MOD;

                if ((mask & x) && (mask & y))
                {
                    continue;
                }

                if (mask & x)
                {
                    dp[row][col][mask ^ x] += dp[row - 1][col][mask];
                }
                else if (mask & y)
                {
                    dp[row][col][mask ^ y] += dp[row - 1][col][mask];
                }
                else
                {
                    dp[row][col][mask ^ x] += dp[row - 1][col][mask];
                    dp[row][col][mask ^ y] += dp[row - 1][col][mask];
                }
            }
        }
    }

    cout << dp[n][m][0] % MOD << endl;
    return 0;
}

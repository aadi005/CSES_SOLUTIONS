#include <iostream>
#include <vector>
int MOD = 1e9 + 7;
using namespace std;

int modInv2()
{
    return (MOD + 1) / 2;
}
int main()
{

    int n;
    cin >> n;

    int sum = (n * (n + 1)) / 2;
    if ((sum & 1) == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
            {
                dp[i][j] += dp[i - 1][j - i];
            }
            dp[i][j] %= MOD;
        }
    }

    cout << (dp[n][sum] * 1LL * modInv2()) % MOD << endl;

    return 0;
}

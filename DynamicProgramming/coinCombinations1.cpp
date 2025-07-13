#include <iostream>
#include <vector>

using namespace std;
int MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++)
    {
        if (dp[i] == 0)
        {
            continue;
        }
        for (int coin : coins)
        {
            if (i + coin <= m)
            {
                dp[i + coin] = (dp[i + coin] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
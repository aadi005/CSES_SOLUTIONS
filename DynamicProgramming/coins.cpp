#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << (dp[m] == INT_MAX ? -1 : dp[m]) << endl;
    return 0;
}
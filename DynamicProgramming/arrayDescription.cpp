#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(m + 2, 0));

    if (arr[0] == 0)
    {
        for (long long j = 1; j <= m; j++)
        {
            dp[0][j] = 1;
        }
    }
    else
    {
        dp[0][arr[0]] = 1;
    }

    for (long long i = 1; i < n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            if (arr[i] == 0 || arr[i] == j)
            {
                dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD);
            }
        }
    }

    long long ans = 0;
    for (long long j = 1; j <= m; j++)
    {
        ans = (ans + dp[n - 1][j]) % MOD;
    }

    cout << ans << endl;
    return 0;
}

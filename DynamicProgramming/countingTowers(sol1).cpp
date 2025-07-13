#include <iostream>
#include <vector>

using namespace std;
long long MOD = 1e9 + 7;

int main()
{

    vector<long long> dp(3, 0);
    dp[1] = 2;
    dp[2] = 8;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k + 1 > dp.size())
        {
            int prev = dp.size();
            dp.resize(k + 1, 0);
            for (int i = prev; i <= k; i++)
            {
                dp[i] = (((6 * dp[i - 1]) % MOD) - ((7 * dp[i - 2]) % MOD) + MOD) % MOD;
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}

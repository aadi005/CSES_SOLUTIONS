#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int N = 1 << n;

    vector<pair<int, long long>> dp(N, {n + 1, 0});
    dp[0] = {1, 0};

    for (int mask = 1; mask < N; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                int prev = mask ^ (1 << i);
                auto [rides, weight] = dp[prev];

                if (weight + w[i] <= x)
                {
                    dp[mask] = min(dp[mask], {rides, weight + w[i]});
                }
                else
                {
                    dp[mask] = min(dp[mask], {rides + 1, w[i]});
                }
            }
        }
    }

    cout << dp[N - 1].first << endl;
    return 0;
}

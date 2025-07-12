#include <iostream>
#include <vector>

using namespace std;
int n;
vector<long long> arr;
vector<long long> preSum;
long long sum(int l, int r)
{
    if (l == 0)
    {
        return preSum[r];
    }
    return preSum[r] - preSum[l - 1];
}

int main()
{

    cin >> n;
    arr.resize(n);
    preSum.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
        {
            preSum[i] = arr[i];
        }
        else
        {
            preSum[i] = preSum[i - 1] + arr[i];
        }
    }
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
    }

    for (int len = 2; len <= n; len++)
    {
        for (int l = 0; l <= n - len; l++)
        {
            int r = l + len - 1;
            dp[l][r] = max(
                arr[l] + sum(l + 1, r) - dp[l + 1][r],
                arr[r] + sum(l, r - 1) - dp[l][r - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}

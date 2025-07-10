#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(10);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int curr = i;
        dp[i % 10] = INT_MAX;
        while (curr != 0)
        {
            int digit = curr % 10;
            curr = curr / 10;
            if (digit == 0)
            {
                continue;
            }
            dp[i % 10] = min(dp[i % 10], dp[(i - digit) % 10] + 1);
        }
    }

    cout << dp[n % 10] << endl;
    return 0;
}

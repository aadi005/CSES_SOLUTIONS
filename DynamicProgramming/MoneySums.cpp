#include <iostream>
#include <vector>

using namespace std;

const int maxX = 1e5;

int main()
{
    int n;
    cin >> n;

    vector<bool> dp(maxX + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = maxX - x; j >= 0; j--)
        {
            if (dp[j])
            {
                dp[j + x] = true;
            }
        }
    }

    int cnt = 0, last = 0;
    for (int i = 1; i <= maxX; i++)
    {
        if (dp[i])
        {
            cnt++;
            last = i;
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= maxX; i++)
    {
        if (dp[i])
        {
            cout << i << (i == last ? '\n' : ' ');
        }
    }

    return 0;
}

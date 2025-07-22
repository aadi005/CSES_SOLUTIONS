#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<int, 3>> projects(n);

    for (int i = 0; i < n; i++)
    {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    sort(projects.begin(), projects.end());

    vector<int> starts(n);
    for (int i = 0; i < n; i++)
    {
        starts[i] = projects[i][0];
    }
    vector<long long> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int end = projects[i][1];
        int reward = projects[i][2];

        int next = lower_bound(starts.begin(), starts.end(), end + 1) - starts.begin();

        dp[i] = max(dp[i + 1], (long long)reward + dp[next]);
    }

    cout << dp[0] << endl;
    return 0;
}

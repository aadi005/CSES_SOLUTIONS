#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr1;
vector<int> arr2;

int main()
{

    int n1, n2;
    cin >> n1 >> n2;
    arr1.resize(n1);
    arr2.resize(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    vector<vector<int>> dp(n1, vector<int>(n2, 0));
    for (int i = 0; i < n2; i++)
    {
        if (arr1[0] == arr2[i])
        {
            dp[0][i] = 1;
        }
        else
        {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for (int i = 1; i < n1; i++)
    {
        if (arr1[i] == arr2[0])
        {
            dp[i][0] = 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
        }
        for (int j = 1; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    int n = dp[n1 - 1][n2 - 1];

    vector<int> ans;
    int i = n1 - 1;
    int j = n2 - 1;
    while (ans.size() != n)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << n << endl;
    for (int k : ans)
    {
        cout << k << " ";
    }
    cout << endl;

    return 0;
}

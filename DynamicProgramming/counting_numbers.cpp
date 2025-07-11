#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;
vector<vector<vector<vector<long long>>>> dp;

vector<int> toArr(long long x)
{
    vector<int> ans;
    if (x == 0)
    {
        return {0};
    }

    while (x != 0)
    {
        ans.push_back(x % 10);
        x = x / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

long long helper(int index, int prev, int trail, int bound)
{

    if (index == arr.size())
    {
        return 1;
    }
    if (dp[index][prev][trail][bound] != -1)
    {
        return dp[index][prev][trail][bound];
    }

    int limit = bound == 1 ? arr[index] : 9;
    long long res = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (trail != 1 && i == prev)
        {
            continue;
        }

        int newBound = ((bound == 1) && (i == limit)) ? 1 : 0;
        int newTrail = ((trail == 1) && (i == 0)) ? 1 : 0;

        res += helper(index + 1, i, newTrail, newBound);
    }
    return dp[index][prev][trail][bound] = res;
}

int main()
{

    long long n, m;
    cin >> n >> m;

    dp.resize(20, vector<vector<vector<long long>>>(11, vector<vector<long long>>(2, vector<long long>(2, -1))));

    arr = toArr(m);
    long long big = helper(0, 10, 1, 1);
    dp.assign(20, vector<vector<vector<long long>>>(11, vector<vector<long long>>(2, vector<long long>(2, -1))));
    arr = toArr(n - 1);
    long long small = helper(0, 10, 1, 1);
    cout << big - small << endl;
    return 0;
}

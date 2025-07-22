#include <iostream>
#include <vector>
#include <unordered_map>

// https://cses.fi/problemset/task/3421 Distict Value Subsequences
// Hint - 1. In the array if a number appears n times, you have (n+1) choices to choose it or not
//        2. Exclude empty subsequence

using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    long long ans = 1;
    for (auto [val, count] : mp)
    {
        ans = (ans * (count + 1));
        ans %= MOD;
    }

    ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;

    return 0;
}

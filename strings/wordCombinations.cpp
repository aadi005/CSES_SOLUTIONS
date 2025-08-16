#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long MOD = 1e9 + 7;

long long helper(const string &s, const vector<string> &dict, int i, vector<int> &dp)
{
    if (i == s.size())
        return 1;
    if (dp[i] != -1)
        return dp[i];

    int ans = 0;
    for (const string &w : dict)
    {
        if (i + w.size() <= s.size() && s.compare(i, w.size(), w) == 0)
        {
            ans += helper(s, dict, i + w.size(), dp);
            ans %= MOD;
        }
    }
    return dp[i] = ans;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<string> dict;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (s.find(temp) != string::npos)
        {
            dict.push_back(temp);
        }
    }

    vector<int> dp(s.size(), -1);
    cout << helper(s, dict, 0, dp) << "\n";
}

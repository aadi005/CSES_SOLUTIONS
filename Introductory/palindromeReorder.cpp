#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{

    string s;
    cin >> s;
    unordered_map<char, int> map;
    for (char c : s)
    {
        map[c]++;
    }
    int n = s.size();
    vector<char> ans(n);
    int j = 0;
    int cntOdd = 0;
    for (auto [c, i] : map)
    {
        if (i & 1)
        {
            cntOdd++;
            if (cntOdd > 1)
            {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            ans[n / 2] = c;
        }

        for (int k = 0; k < (i / 2); k++)
        {
            ans[j] = c;
            ans[n - j - 1] = c;
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

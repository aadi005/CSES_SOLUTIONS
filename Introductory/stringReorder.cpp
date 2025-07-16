#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'A']++;
    }

    for (int f : freq)
    {
        if (f > (n + 1) / 2)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    string res = "";
    char last = '#';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (freq[j] == 0 || j + 'A' == last)
            {
                continue;
            }

            freq[j]--;
            bool can_use = true;

            int max_freq = 0;
            for (int f : freq)
            {
                max_freq = max(max_freq, f);
            }

            if (max_freq > (n - i) / 2)
            {
                can_use = false;
            }

            if (can_use)
            {
                res += (char)(j + 'A');
                last = (char)(j + 'A');
                break;
            }

            freq[j]++;
        }
    }

    cout << res << endl;
    return 0;
}

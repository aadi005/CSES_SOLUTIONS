#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    string p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<int> pi(m);
    pi[0] = 0;
    for (int i = 1; i < m; i++)
    {
        int l = pi[i - 1];
        while (l > 0 && p[i] != p[l])
        {
            l = pi[l - 1];
        }
        if (p[i] == p[l])
        {
            l++;
        }
        pi[i] = l;
    }

    int ans = 0;

    int i = 0;
    int j = 0;
    while (i < n)
    {

        if (s[i] == p[j])
        {
            i++;
            j++;
            if (j == m)
            {
                ans++;
                j = pi[j - 1];
            }
        }
        else if (j != 0)
        {
            j = pi[j - 1];
        }
    }
}

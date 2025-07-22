#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> groups;
    int len = sqrt(n), r = 0, c = 0, cnt = 0;

    vector<int> temp;
    for (int i = 1; i <= n; i++)
    {
        if (cnt > len)
        {
            groups.push_back(temp);
            temp.clear();
            cnt = 0;
        }
        temp.push_back(i);
        cnt++;
    }

    if (!temp.empty())
    {
        groups.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        int j = k % (n - i);

        while (j)
        {
            if (c + j < groups[r].size())
            {
                c += j;
                j = 0;
            }
            else
            {
                j -= groups[r].size() - c;
                c = 0;
                r++;
            }
            if (r >= groups.size())
            {
                r = 0;
            }
        }

        while (c >= groups[r].size())
        {
            c = 0;
            r++;
            if (r >= groups.size())
            {
                r = 0;
            }
        }

        cout << groups[r][c] << " ";

        if (i != n - 1)
        {
            groups[r].erase(groups[r].begin() + c);
            while (c >= groups[r].size())
            {
                c = 0;
                r++;
                if (r >= groups.size())
                {
                    r = 0;
                }
            }
        }
    }
    return 0;
}

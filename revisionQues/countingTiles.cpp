#include <iostream>
#include <vector>

// https://cses.fi/problemset/task/2181/ - Counting Tilings
// Hint - 1. For every column, you can represent it's states as a bit Mask, and there will be (1<<n) total states
//        2. For every state, there are only specific states possible that the next column will take

using namespace std;
int n, m;
int MOD = 1e9 + 7;
void preCompute(int row, int mask, int currMask, vector<vector<int>> &nextMasks)
{
    if (row == n)
    {
        nextMasks[mask].push_back(currMask);
        return;
    }
    if (mask & (1 << row))
    {
        preCompute(row + 1, mask, currMask, nextMasks);
        return;
    }
    preCompute(row + 1, mask, (currMask | (1 << row)), nextMasks);
    if (((mask & (1 << (row + 1))) == 0) && row != n - 1)
    {
        preCompute(row + 2, mask, currMask, nextMasks);
    }
    return;
}

int main()
{
    cin >> n >> m;
    int mask = (1 << n) - 1;

    vector<int> prev(mask + 1, 0);
    vector<vector<int>> nextMasks(mask + 1, vector<int>());
    for (int i = 0; i <= mask; i++)
    {
        preCompute(0, i, 0, nextMasks);
    }
    prev[0] = 1;
    for (int col = m - 1; col >= 0; col--)
    {
        vector<int> curr(mask + 1, 0);
        for (int i = 0; i <= mask; i++)
        {
            for (int k : nextMasks[i])
            {
                curr[i] += prev[k];
                curr[i] %= MOD;
            }
        }
        prev = curr;
    }

    cout << prev[0] << endl;
    return 0;
}

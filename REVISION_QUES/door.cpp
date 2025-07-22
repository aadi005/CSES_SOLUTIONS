#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> timeToCross(vector<int> &arrival, vector<int> &state)
{
    int n = arrival.size();
    vector<int> ans(n, -1);

    queue<int> entry, exit;
    int t = 0;
    int i = 0;
    int prevUsed = -1;

    while (i < n || !entry.empty() || !exit.empty())
    {
        while (i < n && arrival[i] <= t)
        {
            if (state[i] == 0)
            {
                entry.push(i);
            }
            else
            {
                exit.push(i);
            }
            i++;
        }

        if (!exit.empty() && (prevUsed == 1 || prevUsed == -1 || entry.empty()))
        {
            int idx = exit.front();
            exit.pop();
            ans[idx] = t;
            prevUsed = 1;
        }
        else if (!entry.empty())
        {
            int idx = entry.front();
            entry.pop();
            ans[idx] = t;
            prevUsed = 0;
        }
        else
        {
            prevUsed = -1;
        }

        t++;
    }

    return ans;
}

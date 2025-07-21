#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <algorithm>
using namespace std;

typedef array<int, 3> Interval;

vector<int> bit;
vector<vector<int>> result;
vector<Interval> intervals;
set<int> coords;
map<int, int> compress;
int n;

void update(int idx, int delta)
{
    while (idx < (int)bit.size())
    {
        bit[idx] += delta;
        idx += idx & -idx;
    }
}

int query(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main()
{
    cin >> n;
    intervals.resize(n);
    result.assign(2, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        intervals[i] = {a, b, i};
        coords.insert(a);
        coords.insert(b);
    }

    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b)
         {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0]; });

    int id = 1;
    for (int x : coords)
    {
        compress[x] = id++;
    }

    bit.assign(2 * n + 2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int r = compress[intervals[i][1]];
        int idx = intervals[i][2];

        result[0][idx] = query(r);
        update(r, 1);
    }

    bit.assign(2 * n + 2, 0);
    for (int i = 0; i < n; i++)
    {
        int r = compress[intervals[i][1]];
        int idx = intervals[i][2];

        result[1][idx] = i - query(r - 1);
        update(r, 1);
    }

    for (int row = 0; row < 2; row++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << (result[row][i] ? 1 : 0) << (i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}

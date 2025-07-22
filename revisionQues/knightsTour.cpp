#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// Warnsdroff's Rule

vector<pair<int, int>> dir = {
    {2, -1},
    {-2, 1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {2, 1},
    {1, 2},
    {-1, 2}};

int convert(int i, int j)
{
    return (8 * i) + j;
}

bool isValid(int x, int y)
{
    return (x >= 0) && (y >= 0) && (x < 8) && (y < 8);
}

bool dfs(vector<bool> &pathVis, int i, int j, int n, vector<vector<int>> &ans)
{
    n++;
    ans[i][j] = n;
    if (n == 64)
    {
        return true;
    }
    pathVis[convert(i, j)] = true;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    for (auto [dx, dy] : dir)
    {
        int x = dx + i;
        int y = dy + j;

        if (isValid(x, y) && !pathVis[convert(x, y)])
        {
            int cnt = 0;
            for (auto [dnx, dny] : dir)
            {

                int nx = x + dnx;
                int ny = y + dny;
                if (isValid(nx, ny) && !pathVis[convert(nx, ny)])
                {
                    cnt++;
                }
            }
            q.push(make_tuple(cnt, x, y));
        }
    }
    while (!q.empty())
    {
        auto [cnt, x, y] = q.top();
        q.pop();
        if (dfs(pathVis, x, y, n, ans))
        {
            return true;
        }
    }

    pathVis[convert(i, j)] = false;
    return false;
}

int main()
{

    int n, m;
    cin >> m >> n;
    n--;
    m--;
    vector<vector<int>> ans(8, vector<int>(8, 0));

    // pos = i*8 + j

    vector<bool> pathVis(64, false);

    dfs(pathVis, n, m, 0, ans);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

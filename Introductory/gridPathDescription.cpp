#include <iostream>
#include <vector>
using namespace std;

const int N = 7;
const int PATH_LEN = 48;
const int GRID = N + 2;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int path[PATH_LEN];
bool vis[GRID][GRID];

int dfs(int idx, int r, int c)
{
    if ((vis[r][c - 1] && vis[r][c + 1]) && !vis[r - 1][c] && !vis[r + 1][c])
    {
        return 0;
    }
    if ((vis[r - 1][c] && vis[r + 1][c]) && !vis[r][c - 1] && !vis[r][c + 1])
    {
        return 0;
    }

    if (r == 7 && c == 1)
    {
        return idx == PATH_LEN;
    }

    if (idx == PATH_LEN)
    {
        return 0;
    }

    vis[r][c] = true;
    int total = 0;

    if (path[idx] < 4)
    {
        int nr = r + dr[path[idx]];
        int nc = c + dc[path[idx]];
        if (!vis[nr][nc])
        {
            total += dfs(idx + 1, nr, nc);
        }
    }
    else
    {
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (!vis[nr][nc])
            {
                total += dfs(idx + 1, nr, nc);
            }
        }
    }

    vis[r][c] = false;
    return total;
}

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < PATH_LEN; i++)
    {
        char ch = s[i];
        if (ch == 'U')
            path[i] = 0;
        else if (ch == 'R')
            path[i] = 1;
        else if (ch == 'D')
            path[i] = 2;
        else if (ch == 'L')
            path[i] = 3;
        else
            path[i] = 4;
    }

    for (int i = 0; i < GRID; i++)
    {
        vis[0][i] = vis[GRID - 1][i] = true;
        vis[i][0] = vis[i][GRID - 1] = true;
    }

    cout << dfs(0, 1, 1) << endl;
    return 0;
}

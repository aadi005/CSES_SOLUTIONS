#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;

int isValid(int i, int j)
{
    return ((j >= 0) && (i >= 0) && (i < n) && (j < n));
}

int main()
{

    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));

    vector<pair<int, int>> dir = {{2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};
    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 0;

    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();

        for (auto [dx, dy] : dir)
        {
            int x = dx + a;
            int y = dy + b;
            if (isValid(x, y) && grid[x][y] == -1)
            {
                grid[x][y] = grid[a][b] + 1;
                q.push({x, y});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

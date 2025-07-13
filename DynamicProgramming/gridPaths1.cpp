#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mem;
int MOD = 1e9 + 7;

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                grid[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                grid[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (j != 0)
            {
                left = grid[i][j - 1];
            }
            if (i != 0)
            {
                up = grid[i - 1][j];
            }
            grid[i][j] = (up + left) % MOD;
        }
    }
    cout << grid[n - 1][n - 1] << endl;
    return 0;
}

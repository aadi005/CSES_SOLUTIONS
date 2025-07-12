#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    string result;
    result += grid[0][0];

    for (int step = 1; step < 2 * n - 1; step++)
    {
        int sz = q.size();
        char nextMin = 'Z' + 1;
        vector<pair<int, int>> candidates;

        for (int i = 0; i < sz; i++)
        {
            auto [x, y] = q.front();
            q.pop();

            if (x + 1 < n)
            {
                char ch = grid[x + 1][y];
                if (ch < nextMin)
                {
                    nextMin = ch;
                }
            }
            if (y + 1 < n)
            {
                char ch = grid[x][y + 1];
                if (ch < nextMin)
                {
                    nextMin = ch;
                }
            }
            candidates.push_back({x, y});
        }

        for (auto [x, y] : candidates)
        {
            if (x + 1 < n && grid[x + 1][y] == nextMin && !visited[x + 1][y])
            {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }
            if (y + 1 < n && grid[x][y + 1] == nextMin && !visited[x][y + 1])
            {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
        }

        result += nextMin;
    }

    cout << result << endl;
    return 0;
}

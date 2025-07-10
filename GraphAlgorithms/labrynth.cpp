#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

bool isValid(int i, int j, int m, int n)
{
    return ((i >= 0) && (j >= 0) && (i < m) && (j < n));
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    pair<int, int> start;
    pair<int, int> end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start.first = i;
                start.second = j;
            }
            else if (grid[i][j] == 'B')
            {
                end.first = i;
                end.second = j;
            }
        }
    }

    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            parent[i][j] = {i, j};
        }
    }
    queue<pair<int, int>> q;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    int dist = 0;
    q.push(start);
    dis[start.first][start.second] = 0;
    bool found = false;
    while (!q.empty() && !found)
    {
        dist++;
        int sz = q.size();
        for (int i = 0; i < sz && !found; i++)
        {
            auto [a, b] = q.front();
            q.pop();

            if (dis[a][b] == INT_MAX)
            {
                continue;
            }

            for (auto [dx, dy] : dir)
            {

                int x = a + dx;
                int y = b + dy;
                if (isValid(x, y, n, m))
                {
                    if (grid[x][y] == '.' && dis[x][y] > dis[a][b] + 1)
                    {
                        dis[x][y] = dis[a][b] + 1;
                        parent[x][y] = {a, b};
                        q.push({x, y});
                    }
                    else if (grid[x][y] == 'B' && dis[x][y] > dis[a][b] + 1)
                    {
                        dis[x][y] = dis[a][b] + 1;
                        parent[x][y] = {a, b};
                        q.push({x, y});
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    string ans = "";
    pair<int, int> curr = end;
    while (parent[curr.first][curr.second] != curr)
    {
        auto p = parent[curr.first][curr.second];
        if (p.first == curr.first - 1)
            ans += 'D';
        else if (p.first == curr.first + 1)
            ans += 'U';
        else if (p.second == curr.second - 1)
            ans += 'R';
        else if (p.second == curr.second + 1)
            ans += 'L';
        curr = p;
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }
}
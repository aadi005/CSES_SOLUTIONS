#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m;
vector<string> grid;
vector<vector<int>> monsterTime;
vector<vector<int>> playerTime;
vector<vector<pair<int, int>>> parent;

vector<tuple<int, int, char>> directions = {
    {0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};

bool isBorder(int x, int y)
{
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
}

void bfsMonsters(queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy, _] : directions)
        {
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny) && monsterTime[nx][ny] > monsterTime[x][y] + 1)
            {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool bfsPlayer(pair<int, int> start, pair<int, int> &exitPos)
{
    queue<pair<int, int>> q;
    q.push(start);
    playerTime[start.first][start.second] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (isBorder(x, y)) // Found escape
        {
            exitPos = {x, y};
            return true;
        }

        for (auto [dx, dy, _] : directions)
        {
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny) && playerTime[nx][ny] == INF)
            {
                int newTime = playerTime[x][y] + 1;
                if (newTime < monsterTime[nx][ny])
                {
                    playerTime[nx][ny] = newTime;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }

    return false;
}

string reconstructPath(pair<int, int> start, pair<int, int> end)
{
    string path = "";
    pair<int, int> curr = end;

    while (curr != start)
    {
        auto [px, py] = parent[curr.first][curr.second];
        for (auto [dx, dy, ch] : directions)
        {
            if (px + dx == curr.first && py + dy == curr.second)
            {
                path.push_back(ch);
                break;
            }
        }
        curr = parent[curr.first][curr.second];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    monsterTime.assign(n, vector<int>(m, INF));
    playerTime.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start;
    queue<pair<int, int>> monsterQ;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
                start = {i, j};
            else if (grid[i][j] == 'M')
            {
                monsterQ.push({i, j});
                monsterTime[i][j] = 0;
            }
        }
    }

    bfsMonsters(monsterQ);

    pair<int, int> exitPos;
    if (bfsPlayer(start, exitPos))
    {
        string path = reconstructPath(start, exitPos);
        cout << "YES\n"
             << path.size() << "\n"
             << path << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}

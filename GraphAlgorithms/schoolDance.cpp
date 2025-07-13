#include <iostream>
#include <vector>

using namespace std;
int n, m, k;
vector<vector<int>> potentialPairs;
vector<int> matchedWith;
vector<bool> vis;

int dfs(int boy)
{
    if (vis[boy])
    {
        return false;
    }

    vis[boy] = true;

    for (int girl : potentialPairs[boy])
    {
        if (matchedWith[girl] == 0 || dfs(matchedWith[girl]))
        {
            matchedWith[girl] = boy;
            return true;
        }
    }
    return false;
}

int main()
{

    cin >> n >> m >> k;
    potentialPairs.resize(n + 1, vector<int>());
    matchedWith.resize(m + 1, 0);
    vis.resize(n + 1, false);
    for (int i = 0, a, b; i < k; i++)
    {
        cin >> a >> b;
        potentialPairs[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        fill(vis.begin(), vis.end(), false);
        dfs(i);
    }

    int totalPairs = 0;
    vector<pair<int, int>> pairs;
    for (int i = 1; i <= m; i++)
    {
        if (matchedWith[i] != 0)
        {
            totalPairs++;
            pairs.push_back({matchedWith[i], i});
        }
    }

    cout << totalPairs << endl;
    for (auto [boy, girl] : pairs)
    {
        cout << boy << " " << girl << endl;
    }
    return 0;
}

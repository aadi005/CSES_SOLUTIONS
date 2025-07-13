#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
const long long inf = 6e12;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, long long>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<long long> dist(n + 1, 0);
    vector<int> par(n + 1, -1);
    int x = -1;

    for (int i = 1; i <= n; i++)
    {
        x = -1;
        for (auto [a, b, c] : edges)
        {
            if (dist[b] > dist[a] + c)
            {
                dist[b] = dist[a] + c;
                par[b] = a;
                x = b;
            }
        }
    }

    if (x == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            x = par[x];

        vector<int> cycle;
        int curr = x;
        do
        {
            cycle.push_back(curr);
            curr = par[curr];
        } while (curr != x);
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }

    return 0;
}

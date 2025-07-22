#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// https://cses.fi/problemset/task/1692 - De Brujien Sequence
// Hint - 1. Make a graph with bitSequences of length n-1 as nodes, and make edges between nodes by adding 0 or 1
//        2, Find Hamiltonian Path

int N;
vector<vector<int>> G;
stack<int> S;
string ans;

void build()
{
    int nodes = 1 << (N - 1);
    G.resize(nodes);
    for (int u = 0; u < nodes; u++)
    {
        int v0 = (u << 1) & (nodes - 1);
        int v1 = v0 | 1;
        G[u].push_back(v0);
        G[u].push_back(v1);
    }
}

void dfs()
{
    S.push(0);
    while (!S.empty())
    {
        int u = S.top();
        if (!G[u].empty())
        {
            int v = G[u].back();
            G[u].pop_back();
            S.push(v);
        }
        else
        {
            ans += char((u & 1) + '0');
            S.pop();
        }
    }

    for (int i = 0; i < N - 2; i++)
    {
        ans += '0';
    }
}

int main()
{
    cin >> N;
    if (N == 1)
    {
        cout << "01" << endl;
        return 0;
    }

    build();
    dfs();
    cout << ans << endl;
    return 0;
}

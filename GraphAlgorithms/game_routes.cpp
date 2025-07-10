#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

vector<int> mem;

int recurse(vector<vector<int>> &adjLst, int i)
{
    if (i >= adjLst.size())
    {
        return 0;
    }
    if (i == adjLst.size() - 1)
    {
        return 1;
    }
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int sum = 0;
    for (int k : adjLst[i])
    {
        sum += recurse(adjLst, k);
        sum %= MOD;
    }

    return mem[i] = sum;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjLst(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjLst[a].push_back(b);
    }
    mem.resize(n + 1, -1);
    cout << recurse(adjLst, 1) << endl;
    return 0;
}
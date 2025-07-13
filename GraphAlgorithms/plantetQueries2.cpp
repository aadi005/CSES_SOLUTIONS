#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
const int LOG = 31;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> up(n + 1, vector<int>(LOG));

    for (int i = 1; i <= n; i++)
    {
        cin >> up[i][0];
    }

    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

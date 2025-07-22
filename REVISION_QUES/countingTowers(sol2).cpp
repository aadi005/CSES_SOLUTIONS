#include <iostream>
using namespace std;
using ll = long long;
const int M = 1000000007;
const int N = 1000001;

ll towers[N][2];
// https://cses.fi/problemset/task/2413/
// hint - 1. At each point the tiles can be joint or disjoint
//        2. Draw the possible cases of the block on prev height if curr blocks or joint or disjoint

int main()
{
    towers[1][1] = 1;
    towers[1][0] = 1;

    for (int i = 2; i < N; ++i)
    {
        towers[i][1] = (4 * towers[i - 1][1] + towers[i - 1][0]) % M;
        towers[i][0] = (towers[i - 1][1] + 2 * towers[i - 1][0]) % M;
    }

    int t;
    cin >> t;
    for (int ti = 0; ti < t; ++ti)
    {
        int n;
        cin >> n;
        cout << (towers[n][0] + towers[n][1]) % M << "\n";
    }
}

#include <iostream>
#include <vector>
using namespace std;

int ways = 0;
vector<string> board(8);
bool col[8], diag1[15], diag2[15];

void solve(int row)
{
    if (row == 8)
    {
        ways++;
        return;
    }

    for (int c = 0; c < 8; c++)
    {
        if (board[row][c] == '*')
        {
            continue;
        }
        if (col[c] || diag1[row - c + 7] || diag2[row + c])
        {
            continue;
        }

        col[c] = diag1[row - c + 7] = diag2[row + c] = true;
        solve(row + 1);
        col[c] = diag1[row - c + 7] = diag2[row + c] = false;
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }

    solve(0);
    cout << ways << endl;
    return 0;
}

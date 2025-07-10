#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        long long maxCoord = max(x, y);
        long long maxSquare = maxCoord * maxCoord;
        if (x == y)
        {
            cout << maxSquare - maxCoord + 1 << endl;
            continue;
        }
        if ((maxCoord & 1) == 0)
        {

            if (x < y)
            {
                cout << maxSquare - maxCoord - (maxCoord - x) + 1 << endl;
            }
            else
            {
                cout << maxSquare - y + 1 << endl;
            }
        }
        else
        {
            if (x < y)
            {
                cout << maxSquare - x + 1 << endl;
            }
            else
            {
                cout << maxSquare - maxCoord - (maxCoord - y) + 1 << endl;
            }
        }
    }
    return 0;
}
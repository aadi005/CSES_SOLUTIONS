#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, a, b, draws;
    while (t--)
    {

        cin >> n >> a >> b;
        if (a + b > n)
        {
            cout << "NO" << endl;
            continue;
        }
        else if (a + b > 0 && (a == 0 || b == 0))
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        draws = n - a - b;
        int sz = n - draws;
        for (int i = b + 1; i <= sz; i++)
        {
            cout << i << " ";
        }
        for (int i = 1; i <= b; i++)
        {
            cout << i << " ";
        }
        for (int i = sz + 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
    }

    return 0;
}

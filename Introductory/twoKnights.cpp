#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++)
    {
        long long totalWays = (1LL * k * k) * (k * k - 1) / 2;
        long long attackWays = 0;

        if (k > 2)
        {
            attackWays = 4LL * (k - 1) * (k - 2);
        }

        cout << totalWays - attackWays << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

// https://cses.fi/problemset/task/1754 - Coin Piles
// LOGIC - 1.At every turn, you take out exactly 3 coins, so total should be divisible by 3
//         2.In an extreme case, you keep taking 1 coin from first pile and 2 coins from 2nd pile, therefer (max<=2*min)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        long long total = a + b;
        long long mi = min(a, b);
        long long ma = max(a, b);

        if (total % 3 == 0 && mi * 2 >= ma)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

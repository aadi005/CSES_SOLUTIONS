#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if ((n & 1) == 0)
        {
            n = n >> 1;
        }
        else
        {
            n = 3 * n + 1;
        }
    }
    cout << 1 << endl;
    return 0;
}
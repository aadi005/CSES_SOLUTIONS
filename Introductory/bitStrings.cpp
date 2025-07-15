#include <iostream>
#include <vector>

using namespace std;
long long MOD = 1e9 + 7;

int main()
{

    long long n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans << 1;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    long long prev;
    cin >> prev;
    for (int i = 1; i < n; ++i)
    {
        long long curr;
        cin >> curr;
        ans += max((long long)0, prev - curr);
        prev = max(prev, curr);
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    long long n;
    long long ans;
    cin >> n;
    long long sum = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        long long x;
        cin >> x;
        sum += x;
    }
    ans = (n * (n + 1)) / 2 - sum;
    cout << (int)ans << endl;
    return 0;
}
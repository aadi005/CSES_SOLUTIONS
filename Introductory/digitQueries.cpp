#include <iostream>
#include <vector>
#include <string>
using namespace std;

char findDigit(long long k)
{
    long long d = 1;
    long long count = 9;
    long long base = 1;

    while (k > d * count)
    {
        k -= d * count;
        d++;
        count *= 10;
        base *= 10;
    }

    long long offset = (k - 1) / d;
    long long number = base + offset;
    string s = to_string(number);

    return s[(k - 1) % d];
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        long long k;
        cin >> k;
        cout << findDigit(k) << '\n';
    }
    return 0;
}

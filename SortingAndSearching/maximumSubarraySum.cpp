#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{

    int n;
    cin >> n;
    long long sum = 0;
    long long maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        sum += a;
        maxi = max(sum, maxi);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << maxi << endl;
    return 0;
}

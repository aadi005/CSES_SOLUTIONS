#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());
    int left = 0, right = n - 1;
    int rides = 0;
    while (left <= right)
    {
        if (weights[left] + weights[right] <= x)
        {
            left++;
        }
        right--;
        rides++;
    }
    cout << rides << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (arr[l].first + arr[r].first == x)
        {
            cout << arr[l].second + 1 << " " << arr[r].second + 1 << endl;
            return 0;
        }
        else if (arr[l].first + arr[r].first < x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
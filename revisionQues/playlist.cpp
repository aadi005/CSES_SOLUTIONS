#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
    }

    vector<int> lastSeen(n, -1);
    int left = 0, ans = 0;
    for (int right = 0; right < n; right++)
    {
        if (lastSeen[arr[right]] >= left)
        {
            left = lastSeen[arr[right]] + 1;
        }
        lastSeen[arr[right]] = right;
        ans = max(ans, right - left + 1);
    }

    cout << ans << endl;
    return 0;
}

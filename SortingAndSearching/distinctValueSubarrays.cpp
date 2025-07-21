#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
    {
        cin >> x;
    }

    unordered_set<int> s;
    long long ans = 0;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
        while (s.count(arr[r]))
        {
            s.erase(arr[l]);
            l++;
        }
        s.insert(arr[r]);
        ans += (r - l + 1);
    }

    cout << ans << endl;
    return 0;
}

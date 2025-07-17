#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_set<int> st;

    int ans = 0;

    for (int k : arr)
    {
        if (st.find(k - 1) == st.end())
        {
            ans++;
        }
        st.insert(k);
    }

    cout << ans << endl;
}

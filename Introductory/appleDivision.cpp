#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<long long> arr(n);
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    unordered_set<long long> st;
    st.insert(0);

    for (int i = 0; i < n; i++)
    {
        unordered_set<long long> temp;
        for (long long k : st)
        {
            temp.insert(k);
            temp.insert(k + arr[i]);
        }
        st = temp;
    }

    long long mini = LLONG_MAX;
    for (long long k : st)
    {
        mini = min(mini, abs((total - (2 * k))));
    }
    cout << mini << endl;
    return 0;
}

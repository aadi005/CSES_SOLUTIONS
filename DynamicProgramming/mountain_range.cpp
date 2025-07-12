#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> seg;
vector<int> a;

void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
        return seg[ind];
    if (high < l || low > r)
        return INT_MIN;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}

void update(int ind, int low, int high, int pos, int val)
{
    if (low == high)
    {
        seg[ind] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (pos <= mid)
        update(2 * ind + 1, low, mid, pos, val);
    else
        update(2 * ind + 2, mid + 1, high, pos, val);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> L(n, -1), R(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && h[st.top()] <= h[i])
        {
            R[st.top()] = i;
            st.pop();
        }
        if (!st.empty())
        {
            L[i] = st.top();
        }
        st.push(i);
    }

    vector<pair<int, int>> height_index;
    for (int i = 0; i < n; i++)
        height_index.push_back({h[i], i});
    sort(height_index.begin(), height_index.end());

    vector<int> dp(n, 1);
    a.assign(n, 0);
    seg.assign(4 * n, 0);

    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && height_index[j].first == height_index[i].first)
        {
            int idx = height_index[j].second;
            int l = L[idx] + 1;
            int r = R[idx] - 1;
            if (l <= r)
                dp[idx] = 1 + query(0, 0, n - 1, l, r);
            j++;
        }
        for (int k = i; k < j; k++)
        {
            int idx = height_index[k].second;
            update(0, 0, n - 1, idx, dp[idx]);
        }
        i = j;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}

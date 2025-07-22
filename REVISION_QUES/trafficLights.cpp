#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

struct Light
{
    int pos, id;
};

int main()
{
    int x, n;
    cin >> x >> n;

    set<int> st;
    vector<Light> lights(n + 2);
    vector<int> ans(n);
    int maxGap = 0;

    st.insert(0);
    st.insert(x);

    lights[0] = {0, 0};
    lights[n + 1] = {x, 1};

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        lights[i + 1] = {a, i + 2};
        st.insert(a);
    }

    sort(lights.begin(), lights.end(), [](Light a, Light b)
         { return a.pos < b.pos; });

    for (int i = 1; i < n + 2; i++)
    {
        maxGap = max(maxGap, lights[i].pos - lights[i - 1].pos);
    }

    sort(lights.begin(), lights.end(), [](Light a, Light b)
         { return a.id > b.id; });

    for (int i = 0; i < n; i++)
    {
        ans[n - i - 1] = maxGap;

        auto it = st.find(lights[i].pos);
        auto nextIt = next(it);
        auto prevIt = prev(it);

        maxGap = max(maxGap, *nextIt - *prevIt);
        st.erase(it);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}

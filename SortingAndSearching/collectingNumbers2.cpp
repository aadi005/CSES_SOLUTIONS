#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, q;

int countBreaks(vector<int> &pos)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> q;
    vector<int> arr(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = countBreaks(pos);

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        set<int> s;

        for (int val : {arr[a], arr[b]})
        {
            for (int d = -1; d <= 1; d++)
            {
                int x = val + d;
                if (x >= 1 && x < n)
                {
                    s.insert(x);
                }
            }
        }

        for (int x : s)
        {
            if (pos[x] > pos[x + 1])
            {
                rounds--;
            }
        }

        swap(arr[a], arr[b]);
        pos[arr[a]] = a;
        pos[arr[b]] = b;

        for (int x : s)
        {
            if (pos[x] > pos[x + 1])
            {
                rounds++;
            }
        }

        cout << rounds << endl;
    }

    return 0;
}

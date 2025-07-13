#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    multiset<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        auto it = s.lower_bound(x);
        it++;
        if (it != s.end())
        {
            s.erase(it);
        }
    }

    cout << s.size() << endl;
    return 0;
}
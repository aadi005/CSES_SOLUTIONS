#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cubes(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cubes[i];
    }

    multiset<int> towers;

    for (int x : cubes)
    {
        auto it = towers.upper_bound(x);
        if (it != towers.end())
        {
            towers.erase(it);
        }
        towers.insert(x);
    }

    cout << towers.size() << endl;
    return 0;
}

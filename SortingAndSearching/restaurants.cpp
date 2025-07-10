#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> restaurants;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        restaurants.push_back({a, 1});
        restaurants.push_back({b, -1});
    }
    sort(restaurants.begin(), restaurants.end());
    vector<int> result(n, 1);
    int ans = 0;
    int current = 0;
    for (auto [a, b] : restaurants)
    {
        current += b;
        ans = max(ans, current);
    }
    cout << ans << endl;
    return 0;
}
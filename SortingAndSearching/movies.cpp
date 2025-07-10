#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), [](auto &a, auto &b)
         { return a.second < b.second; });
    int count = 0, lastEnd = 0;
    for (auto &[start, end] : movies)
    {
        if (start >= lastEnd)
        {
            count++;
            lastEnd = end;
        }
    }
    cout << count << endl;
    return 0;
}

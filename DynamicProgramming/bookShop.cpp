#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, budget;
    cin >> n >> budget;

    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        books[i].second = a;
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        books[i].first = a;
    }
    vector<int> prev(budget + 1, 0);
    for (int i = books[0].second; i <= budget; i++)
    {
        prev[i] = books[0].first;
    }

    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(budget + 1, 0);
        for (int j = 0; j <= budget; j++)
        {
            int take = 0;
            if (j >= books[i].second)
            {
                take = prev[j - books[i].second] + books[i].first;
            }
            // not take
            int notTake = prev[j];

            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    cout << prev[budget] << endl;
    return 0;
}

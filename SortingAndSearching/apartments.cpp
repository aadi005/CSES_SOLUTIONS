#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> applicants(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> applicants[i];
    }
    vector<int> apartments(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> apartments[i];
    }
    int ans = 0;
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    int i = 0, j = 0;
    while (i < n && j < k)
    {
        if (abs(applicants[i] - apartments[j]) <= x)
        {
            ans++;
            i++;
            j++;
        }
        else
        {
            if (applicants[i] < apartments[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
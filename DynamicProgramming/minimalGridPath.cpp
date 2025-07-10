#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> prev(n);

    for (int i = 0; i < n; ++i)
    {
        vector<string> curr(n);
        for (int j = 0; j < n; ++j)
        {
            char c;
            cin >> c;

            if (i == 0 && j == 0)
                curr[j] = string(1, c);
            else if (i == 0)
                curr[j] = curr[j - 1] + c;
            else if (j == 0)
                curr[j] = prev[j] + c;
            else
                curr[j] = min(prev[j], curr[j - 1]) + c;
        }
        prev = move(curr);
    }

    cout << prev[n - 1] << endl;
    return 0;
}
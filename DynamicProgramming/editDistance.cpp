#include <iostream>
#include <vector>

using namespace std;

int main()
{

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<int> prev(n2 + 1, 0);
    for (int i = 0; i <= n2; i++)
    {
        prev[i] = i;
    }

    for (int i = 1; i <= n1; i++)
    {
        vector<int> curr(n2 + 1, 0);
        curr[0] = i;
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = min(prev[j], min(curr[j - 1], prev[j - 1])) + 1;
            }
        }
        prev = curr;
    }

    cout << prev[n2] << endl;

    return 0;
}

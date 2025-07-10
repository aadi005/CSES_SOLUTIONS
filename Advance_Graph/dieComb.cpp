#include <iostream>
#include <vector>

using namespace std;
int MOD = 1e9 + 7;

int main()
{

    int n;
    cin >> n;
    vector<int> tab(n + 1, 0);
    tab[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 && i >= j; j++)
        {
            tab[i] += tab[i - j];
            tab[i] %= MOD;
        }
    }
    cout << tab[n] << endl;
    return 0;
}
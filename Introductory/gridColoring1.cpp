#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<char> odd = {'A', 'B'};
    vector<char> even = {'C', 'D'};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            int k = i + j;

            if (k & 1)
            {
                for (char c : odd)
                {
                    if (c != ch)
                    {
                        ch = c;
                        break;
                    }
                }
            }
            else
            {
                for (char c : even)
                {
                    if (c != ch)
                    {
                        ch = c;
                        break;
                    }
                }
            }
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}

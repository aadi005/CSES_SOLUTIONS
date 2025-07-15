#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    set<string> unique_perms;

    do
    {
        unique_perms.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << unique_perms.size() << endl;
    for (const string &perm : unique_perms)
    {
        cout << perm << endl;
    }

    return 0;
}

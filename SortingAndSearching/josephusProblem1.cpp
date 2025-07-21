#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n;
    cin >> n;

    list<int> children;
    for (int i = 1; i <= n; i++)
    {
        children.push_back(i);
    }

    auto it = children.begin();
    while (!children.empty())
    {
        it++;
        if (it == children.end())
        {
            it = children.begin();
        }

        cout << *it << " ";
        it = children.erase(it);
        if (it == children.end())
        {
            it = children.begin();
        }
    }

    cout << endl;
    return 0;
}

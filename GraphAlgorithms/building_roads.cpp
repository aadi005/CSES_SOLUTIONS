#include <iostream>
#include <vector>

using namespace std;

class edgeClass
{
private:
    vector<int> sze;
    vector<int> par;
    int sz;

public:
    edgeClass(int n)
    {

        sze.resize(n + 1, 1);
        par.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
        sz = n;
    }

    int getPar(int i)
    {
        if (par[i] == i)
        {
            return i;
        }

        return par[i] = getPar(par[i]);
    }

    void setPar(int i, int j)
    {
        par[getPar(i)] = getPar(j);
    }

    int getSize(int i)
    {
        return sze[getPar(i)];
    }

    void insert(int i, int j)
    {
        if (getPar(i) == getPar(j))
        {
            return;
        }
        if (getSize(i) > getSize(j))
        {

            sze[getPar(i)] += sze[getPar(j)];
            setPar(j, i);
        }
        else
        {
            sze[getPar(j)] += sze[getPar(i)];
            setPar(i, j);
        }
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    edgeClass *ec = new edgeClass(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ec->insert(a, b);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (ec->getPar(i) == i)
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
    return 0;
}
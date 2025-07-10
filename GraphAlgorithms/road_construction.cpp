#include <iostream>
#include <vector>

using namespace std;

class edgeClass
{
private:
    vector<int> sze;
    vector<int> par;
    int sz;
    int numComp;
    int maxSize = 1;

public:
    edgeClass(int n)
    {
        sze.resize(n + 1, 1);
        par.resize(n + 1);
        sz = n;
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
        numComp = n;
    }

    int getPar(int x)
    {
        if (par[x] == x)
        {
            return x;
        }

        return par[x] = getPar(par[x]);
    }

    void setPar(int x, int y)
    {
        par[getPar(x)] = getPar(y);
    }

    int getSize(int x)
    {
        return sze[getPar(x)];
    }

    void insert(int x, int y)
    {
        if (getPar(x) == getPar(y))
        {
            return;
        }
        if (getSize(x) > getSize(y))
        {
            sze[getPar(x)] += getSize(y);
            setPar(y, x);
            numComp--;
            maxSize = max(maxSize, getSize(x));
        }
        else
        {
            sze[getPar(y)] += getSize(x);
            setPar(x, y);
            numComp--;
            maxSize = max(maxSize, getSize(y));
        }
    }
    int getMax()
    {
        return maxSize;
    }
    int getComps()
    {
        return numComp;
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    edgeClass *ec = new edgeClass(n);
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        ec->insert(a, b);
        cout << ec->getComps() << " " << ec->getMax() << endl;
    }
}

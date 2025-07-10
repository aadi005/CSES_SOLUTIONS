#include <iostream>
#include <vector>

using namespace std;

class edgeClas
{
private:
    vector<int> par;
    vector<int> sze;
    int sz;

public:
    edgeClas(int n)
    {
        par.resize(n);
        sze.resize(n, 1);
        sz = n;
        for (int i = 0; i < sz; i++)
        {
            par[i] = i;
        }
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
        if (getSize(i) > getSize(j))
        {
            sze[getPar(i)] += getSize(j);
            par[getPar(j)] = getPar(i);
        }
        else
        {
            sze[getPar(j)] += getSize(i);
            par[getPar(i)] = getPar(j);
        }
    }
};

int convert(int i, int j, int m)
{
    return (i * m) + j;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    // ind = i*m + j
    edgeClas *ec = new edgeClas(m * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '#')
            {
                continue;
            }
            if (j != 0)
            {
                if (grid[i][j - 1] == '.')
                {
                    ec->insert(convert(i, j, m), convert(i, j - 1, m));
                }
            }
            if (i != 0)
            {
                if (grid[i - 1][j] == '.')
                {
                    ec->insert(convert(i, j, m), convert(i - 1, j, m));
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && (ec->getPar(convert(i, j, m)) == convert(i, j, m)))
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
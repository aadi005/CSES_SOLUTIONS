#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

class edgeClass
{
private:
    vector<long long> parent;
    vector<long long> size;
    long long currSz;

public:
    edgeClass(long long sz)
    {
        currSz = sz;
        parent.resize(sz);
        size.resize(sz);
        for (long long i = 0; i < sz; i++)
        {
            parent[i] = i;
        }
    }

    long long getPar(long long i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return parent[i] = getPar(parent[i]);
    }

    void setPar(long long k, long long par)
    {
        parent[getPar(k)] = getPar(par);
    }

    long long getSize(long long i)
    {
        return size[getPar(i)];
    }

    void addSize(long long src, long long dest)
    {
        size[getPar(src)] += size[getPar(dest)];
    }

    void insert(long long src, long long dest)
    {

        if (getSize(src) > getSize(dest))
        {
            addSize(src, dest);
            setPar(dest, src);
        }
        else
        {
            addSize(dest, src);
            setPar(src, dest);
        }
    }

    long long comps()
    {
        long long ans = 0;
        for (long long i = 0; i < currSz; i++)
        {

            if (parent[i] == i)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{

    long long n, m;
    cin >> n >> m;
    vector<tuple<long long, long long, long long>> edges(m);
    for (long long i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        edges[i] = make_tuple(c, a, b);
    }
    sort(edges.begin(), edges.end());

    edgeClass *ec = new edgeClass(n);
    long long ans = 0;
    for (auto [a, b, c] : edges)
    {

        if (ec->getPar(b - 1) == ec->getPar(c - 1))
        {
            continue;
        }
        else
        {
            ans += a;
            ec->insert(b - 1, c - 1);
        }
    }

    long long comp = ec->comps();

    if (comp > 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
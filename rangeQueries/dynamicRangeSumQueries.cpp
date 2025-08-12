#include <iostream>
#include <vector>

class FenwickTree
{
private:
    std::vector<long long> arr;
    long long n;

public:
    FenwickTree(long long n)
        : n(n)
    {
        arr.resize(n + 1, 0);
    }
    void update(long long i, long long k)
    {
        while (i <= n)
        {
            arr[i] += k;
            i = i + (i & (-i));
        }
    }
    long long query(long long i)
    {
        long long ans = 0;
        while (i > 0)
        {
            ans += arr[i];
            i = i - (i & (-i));
        }
        return ans;
    }
};

int main()
{

    long long n, q;
    std::cin >> n >> q;
    FenwickTree *ft = new FenwickTree(n);

    for (long long i = 1; i <= n; i++)
    {
        long long a;
        std::cin >> a;
        ft->update(i, a);
    }

    while (q--)
    {
        long long val, a, b;
        std::cin >> val >> a >> b;
        if (val == 1)
        {
            long long og = ft->query(a) - ft->query(a - 1);
            long long upd = b - og;
            ft->update(a, upd);
        }
        else
        {
            std::cout << ft->query(b) - ft->query(a - 1) << std::endl;
        }
    }
    return 0;
}

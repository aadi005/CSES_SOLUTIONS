#include <iostream>
#include <vector>
#include <unordered_map>

// used the logic od fendwick tree and compressed_indexes

using namespace std;
int MOD = 1e9 + 7;
class fendWichTree
{
private:
    int size;
    vector<long long> tree;

public:
    fendWichTree(int n)
    {
        tree.resize(n + 2, 0);
        size = n + 2;
    }

    int fetch(int x)
    {
        int res = 0;
        while (x > 0)
        {

            res = (res + tree[x]) % MOD;
            x = x - (x & (-x));
        }
        return res;
    }

    void update(int x, long long val)
    {
        while (x < size)
        {
            tree[x] = (tree[x] + val) % MOD;
            x = x + (x & (-x));
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> sorted(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    }

    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> compressed;
    int i = 1;
    for (int j = 0; j < n; j++)
    {
        if (j == 0 || sorted[j] != sorted[j - 1])
        {
            compressed[sorted[j]] = i;
            i++;
        }
    }

    fendWichTree *ft = new fendWichTree(compressed.size());
    long long total = 0;
    for (int k : arr)
    {
        int compIndex = compressed[k];
        long long prev = ft->fetch(compIndex - 1);
        ft->update(compIndex, (prev + 1) % MOD);
        total = (total + (prev + 1)) % MOD;
    }
    cout << total << endl;
    return 0;
}

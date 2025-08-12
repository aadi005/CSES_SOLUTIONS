#include <iostream>
#include <vector>

int main()
{

    int n, q;
    std::cin >> n >> q;
    std::vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> prefixSum[i];
        prefixSum[i] += prefixSum[i - 1];
    }

    while (q--)
    {
        int a, b;
        std::cin >> a >> b;
        long long ans = prefixSum[b];
        if (a != 0)
        {
            ans -= prefixSum[a - 1];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

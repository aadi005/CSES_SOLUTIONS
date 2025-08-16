#include <iostream>
#include <vector>
#include <climits>

int main()
{

    int n, q;
    std::cin >> n >> q;
    std::vector<int> prefix(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> prefix[i];
        if (i != 0)
        {
            prefix[i] = prefix[i] ^ prefix[i - 1];
        }
    }

    while (q--)
    {
        int n, m;
        std::cin >> n >> m;
        n--;
        m--;
        int ans = prefix[m];
        if (n != 0)
        {
            ans = ans ^ prefix[n - 1];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
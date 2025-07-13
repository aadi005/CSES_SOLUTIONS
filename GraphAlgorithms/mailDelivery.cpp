#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pii;
const int MAX_N = 1e5 + 1;
const int MAX_M = 2e5 + 1;

int n, m;
int degree[MAX_N];
bool tourExists, visited[MAX_M];
vector<pii> graph[MAX_N];
vector<int> eulerTour;
stack<int> stk;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }

    tourExists = true;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            tourExists = false;
            break;
        }
    }

    if (!tourExists)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    stk.push(1);
    while (!stk.empty())
    {
        int curr = stk.top();
        if (degree[curr])
        {
            while (!graph[curr].empty())
            {
                int next = graph[curr].back().first;
                int edgeId = graph[curr].back().second;
                graph[curr].pop_back();

                if (!visited[edgeId])
                {
                    visited[edgeId] = true;
                    degree[curr]--;
                    degree[next]--;
                    stk.push(next);
                    break;
                }
            }
        }
        else
        {
            eulerTour.push_back(curr);
            stk.pop();
        }
    }

    if ((int)eulerTour.size() != m + 1)
    {
        printf("IMPOSSIBLE\n");
    }
    else
    {
        for (int i = 0; i <= m; i++)
        {
            printf("%d%c", eulerTour[i], (i == m ? '\n' : ' '));
        }
    }
}

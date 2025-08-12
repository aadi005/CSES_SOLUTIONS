#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Node
{
public:
    int val;
    int li;
    int ri;
    Node *left;
    Node *right;

    Node(int val)
        : val(val)
    {
    }

    Node(int l, int r)
        : li(l), ri(r)
    {
    }

    Node(int l, int r, int val)
        : li(l), ri(r), val(val)
    {
    }
};

class SegmentTree
{
private:
    Node *par;
    Node *createST(std::vector<int> &arr, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        else if (l == r)
        {
            return (new Node(l, r, arr[l]));
        }

        Node *curr = new Node(l, r);
        int mid = l + ((r - l) / 2);
        curr->left = createST(arr, l, mid);
        curr->right = createST(arr, mid + 1, r);

        curr->val = std::min(curr->left ? curr->left->val : INT_MAX, curr->right ? curr->right->val : INT_MAX);
        if (curr->val == INT_MAX)
        {
            return (new Node(l, r, arr[l]));
        }
        return curr;
    }

    int getVal(Node *curr, int left, int right)
    {
        if (right < left)
        {
            return -1;
        }
        if (curr == NULL)
        {
            return INT_MAX;
        }
        int li = curr->li;
        int ri = curr->ri;
        if (right < li || left > ri)
        {
            return INT_MAX;
        }
        else if (left <= li && right >= ri)
        {
            return curr->val;
        }

        return std::min(getVal(curr->left, left, right), getVal(curr->right, left, right));
    }

public:
    SegmentTree(std::vector<int> &arr)
    {
        int l = 0;
        int r = arr.size() - 1;
        par = createST(arr, l, r);
    }

    int query(int l, int r)
    {

        int ans = getVal(par, l, r);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr(n + 1);
    arr[0] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> arr[i];
    }

    SegmentTree *st = new SegmentTree(arr);
    while (q--)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << st->query(a, b) << std::endl;
    }
    return 0;
}

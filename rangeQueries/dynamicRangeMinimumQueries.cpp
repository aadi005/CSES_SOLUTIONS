#include <iostream>
#include <vector>
#include <climits>
class Node
{
public:
    Node *left;
    Node *right;
    int li;
    int ri;
    int val;
    Node(int l, int r, int val)
        : li(l), ri(r), val(val)
    {
    }
    Node(int val)
        : val(val)
    {
    }
    Node(int l, int r)
        : li(l), ri(r)
    {
    }
};

class SegmentTree
{
private:
    Node *par;
    Node *createTree(int l, int r, std::vector<int> &arr)
    {
        if (l > r)
        {
            return nullptr;
        }
        else if (l == r)
        {
            return new Node(l, r, arr[l]);
        }

        Node *curr = new Node(l, r);
        int mid = l + (r - l) / 2;
        Node *left = createTree(l, mid, arr);
        Node *right = createTree(mid + 1, r, arr);

        curr->left = left;
        curr->right = right;
        if (left && right)
        {
            curr->val = std::min(left->val, right->val);
        }
        else if (left)
        {
            curr->val = left->val;
        }
        else
        {
            curr->val = right->val;
        }

        return curr;
    }

    void updateVal(Node *curr, int &index, int &val)
    {
        if (curr == NULL || index < curr->li || index > curr->ri)
        {
            return;
        }
        if (curr->li == curr->ri && curr->li == index)
        {
            curr->val = val;
            return;
        }
        Node *left = curr->left;
        Node *right = curr->right;

        updateVal(left, index, val);
        updateVal(right, index, val);

        if (left && right)
        {
            curr->val = std::min(left->val, right->val);
        }
        else if (left)
        {
            curr->val = left->val;
        }
        else
        {
            curr->val = right->val;
        }
        return;
    }

    int retVal(int &l, int &r, Node *curr)
    {
        if (l > r)
        {
            return INT_MAX;
        }
        if (curr == NULL || r < curr->li || l > curr->ri)
        {
            return INT_MAX;
        }
        else if (r >= curr->ri && l <= curr->li)
        {
            return curr->val;
        }
        else
        {
            int le = retVal(l, r, curr->left);
            int re = retVal(l, r, curr->right);
            return std::min(le, re);
        }
    }

public:
    SegmentTree(std::vector<int> arr)
    {
        int l = 0;
        int r = arr.size() - 1;
        par = createTree(l, r, arr);
    }

    void update(int index, int val)
    {
        updateVal(par, index, val);
    }

    int query(int l, int r)
    {
        return retVal(l, r, par);
    }
};

int main()
{

    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    SegmentTree *st = new SegmentTree(arr);
    while (q--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == 1)
        {
            b--;
            st->update(b, c);
        }
        else
        {
            b--;
            c--;
            int ans = st->query(b, c);
            std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;
        }
    }
    return 0;
}

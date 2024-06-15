# include <iostream>
# include <vector>

using namespace std;

bool isAVL = true;
long long r;

struct Tree
{
    int value = -1;
    int parent = -1;
    int left = -1;
    int right = -1;
    int deep = 0;
};


bool bts(vector<Tree>& tree, long long x, long long min, long long max)
{
    if (x == -1) return true;

    if (tree[x].value >= max || tree[x].value <= min) return false;

    return bts(tree, tree[x].left, min, tree[x].value) && bts(tree, tree[x].right, tree[x].value, max);

}

int deep_search(vector<Tree>& tree, long long x)
{
    if (isAVL == false) return 0;
    if (x == -1) return 0;

    int leftHeight = deep_search(tree, tree[x].left);
    int rightHeight = deep_search(tree, tree[x].right);

    if (abs(leftHeight - rightHeight) > 1)
        isAVL = false;

    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n; cin >> n >> r;

    vector<Tree> tree(n + 1);
    tree[r].value = r;

    for (long long i = 0; i < n; ++i)
    {
        long long left, right;
        cin >> left >> right;
        tree[i].value = i;
        tree[i].left = left;
        tree[i].right = right;
        if (left != -1)
            tree[left].parent = i;
        if (right != -1)
            tree[right].parent = i;
    }

    deep_search(tree, r);

    if (isAVL && bts(tree, r, -1e15, 1e15))
    {
        cout << 1;
    }
    else
        cout << 0;

    return 0;
}
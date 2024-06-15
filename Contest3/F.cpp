#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9;

struct TreeNode
{
    long long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(long long x)
    {
        val = x;
        left = nullptr; right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, long long val)
{
    if (!root)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);

    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

long long next(TreeNode* root, long long x) {
    long long ans = -1;
    while (root)
    {
        if (root->val >= x)
        {
            ans = root->val;
            root = root->left;
        }
        else
            root = root->right;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    TreeNode* root = nullptr;
    long long lastRes = -1;

    char op;
    long long val;
    for (int i = 0; i < n; ++i) {
        cin >> op >> val;

        if (op == '+')
        {
            if (lastRes != -1)
                val = (val + lastRes) % MOD;

            root = insert(root, val);
            lastRes = -1;
        }

        else if (op == '?')
        {
            lastRes = next(root, val);
            cout << lastRes << "\n";
        }
    }

    return 0;
}
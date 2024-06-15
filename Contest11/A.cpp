#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> depths;
vector<int> parents;
vector<vector<int>> tree;
vector<vector<int>> dp;
int n;

void dfs(int node, int parent, int dep) {
    parents[node] = parent;
    depths[node] = dep;

    for (int u : tree[node]) {
        if (u != parent)
            dfs(u, node, dep + 1);
    }
}

void prep() {
    int LOG = log2(n) + 1;
    dp.resize(n, vector<int>(LOG));

    for (int i = 0; i < n; ++i) {
        dp[i][0] = parents[i];
    }

    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int lca(int v, int u) {
    if (depths[v] > depths[u])
        swap(v, u);

    int LOG = log2(n) + 1;
    for (int i = LOG - 1; i >= 0; --i) {
        if (depths[u] - (1 << i) >= depths[v]) {
            u = dp[u][i];
        }
    }

    if (v == u)
        return v;

    for (int i = LOG - 1; i >= 0; --i) {
        if (dp[v][i] != dp[u][i]) {
            v = dp[v][i];
            u = dp[u][i];
        }
    }

    return parents[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    tree.resize(n);
    depths.resize(n);
    parents.resize(n, -1);

    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }


    dfs(0, -1, 0);
    parents[0] = 0;
    prep();

    int m; cin >> m;
    while (m--) {
        int v, u; cin >> v >> u;
        cout << lca(v, u) << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct Edge {
    int to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
};

vector<int> depths;
vector<int> parents;
vector<vector<Edge>> tree;
vector<vector<int>> dp;
vector<vector<int>> minCost;
int n;

void dfs(int node, int parent, int dep) {
    parents[node] = parent;
    depths[node] = dep;
    for (const auto& edge : tree[node]) {
        int u = edge.to;
        if (u != parent) {
            dfs(u, node, dep + 1);
        }
    }
}

void prep() {
    int LOG = log(n) + 1;
    dp.resize(n, vector<int>(LOG));
    minCost.resize(n, vector<int>(LOG, INT_MAX));

    for (int i = 0; i < n; ++i) {
        dp[i][0] = parents[i];
        for (const auto& edge : tree[i]) {
            if (edge.to == parents[i])
                minCost[i][0] = edge.cost;
        }
    }

    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
                minCost[i][j] = min(minCost[i][j - 1],
                    minCost[dp[i][j - 1]][j - 1]);
            }
        }
    }
}

int query(int v, int u) {
    if (depths[v] > depths[u])
        swap(v, u);

    int LOG = log(n) + 1;
    int min_weight = INT_MAX;

    for (int i = LOG - 1; i >= 0; --i) {
        if (depths[u] - depths[v] >= (1 << i)) {
            min_weight = min(min_weight, minCost[u][i]);
            u = dp[u][i];
        }
    }

    if (u == v)
        return min_weight;

    for (int i = LOG - 1; i >= 0; --i) {
        if (dp[v][i] != dp[u][i]) {
            min_weight = min({ min_weight, minCost[v][i], minCost[u][i] });
            v = dp[v][i];
            u = dp[u][i];
        }
    }

    min_weight = min({ min_weight, minCost[v][0], minCost[u][0] });
    return min_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    tree.resize(n);

    for (int i = 1; i < n; ++i) {
        int x, w; cin >> x >> w;
        tree[i].emplace_back(x, w);
        tree[x].emplace_back(i, w);
    }

    depths.resize(n);
    parents.resize(n, -1);

    dfs(0, -1, 0);
    parents[0] = 0;
    prep();

    int m; cin >> m;
    while (m--) {
        int v, u;
        cin >> v >> u;
        cout << query(v, u) << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10e5;
const int LOGMAX = 20;

int n, l;
vector<int> tree[MAX];
int tcin[MAX], tcout[MAX];
int timer;
int up[MAX][LOGMAX];

void dfs(int v, int p = -1)
{
    tcin[v] = ++timer;
    up[v][0] = p == -1 ? v : p;

    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int to : tree[v])
    {
        if (to != p)
            dfs(to, v);
    }
    tcout[v] = ++timer;
}

bool upper(int a, int b)
{
    return tcin[a] <= tcin[b] && tcout[a] >= tcout[b];
}

int lca(int a, int b)
{
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;

    for (int i = l; i >= 0; --i)
        if (!upper(up[a][i], b))
            a = up[a][i];

    return up[a][0];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    l = 1;
    while ((1 << l) <= n) ++l;

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    dfs(0);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        int res = lca(u, v);
        cout << res << '\n';
    };

    return 0;
}
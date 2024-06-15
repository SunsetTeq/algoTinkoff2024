# include <iostream>
# include <vector>

using namespace std;

int n, m;
bool cycle = false;

vector<vector<int>> g;
vector<int> used;

void dfs(int v);

int main()
{
    cin >> n >> m;
    g.resize(n);
    used.resize(n, 0);

    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    for (int v = 0; v < n; ++v)
    {
        if (!used[v])
        {
            dfs(v);
            if (cycle) break;
        }
    }

    cycle == false ? cout << 0 : cout << 1;
    return 0;
}

void dfs(int v) {
    if (cycle) return;

    used[v] = 1;

    for (int u : g[v])
    {
        if (used[u] == 1)
        {
            cycle = true;
            return;
        }
        else if (used[u] == 0)
            dfs(u);
        if (cycle) return;
    }
    used[v] = 2;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<int> perm;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;

    g.resize(n);
    perm.resize(n);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> perm[i];
        perm[i]--;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[perm[i]] = i; // ������� ������ � ������������
    }

    bool isTopSort = true;
    for (int v = 0; v < n && isTopSort; v++)
    {
        for (int u : g[v])
        {
            if (pos[v] > pos[u])
            {
                isTopSort = false;
                break;
            }
        }
    }

    if (isTopSort)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
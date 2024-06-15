#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 30001, inf = 1e9;
vector< pair<int, int> > g[maxn];
int n;

vector<int> dijkstra(int s) {
    vector<int> d(n, inf);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //greater<pair<int ,int>> ��� ����������, ������� ������ ���� �� ��������;
    q.push({ 0, s });
    while (!q.empty()) {
        auto qTop = q.top();
        auto curDist = qTop.first, v = qTop.second;
        q.pop();
        if (curDist > d[v])
            continue;
        for (auto gV : g[v]) {
            auto u = gV.first, w = gV.second;
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push({ d[u], u });
            }
        }
    }
    return d;
}

int main() {
    int m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }


    vector<int> distances = dijkstra(0);

    for (int i = 0; i < n; ++i) {
        cout << distances[i] << " ";
    }
    return 0;
}
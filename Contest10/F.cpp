#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<vector<vector<int>>> g;

int dijkstra(int w) {
    vector<bool> used(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, 1 });  // �������, �����

    while (!q.empty()) {
        auto qTop = q.top();
        int curTime = qTop.first, v = qTop.second;
        q.pop();

        if (used[v]) continue;
        used[v] = true;

        if (curTime > 1440) {
            return 0;
        }

        if (v == n) {
            return curTime;
        }

        for (auto& u : g[v]) {  // 0 �������, � ������� ����, 1 ����� ��� ���, 2 ���
            if (u[2] >= w && !used[u[0]]) {
                int tmp = curTime + u[1];
                if (tmp <= 1440) {
                    q.push(make_pair(tmp, u[0]));
                }
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    if (n == 1) {
        cout << 10000000;
        return 0;
    }

    g.resize(n + 1);

    set<int> uniqW;

    for (int i = 0; i < m; ++i) {
        int u, v, t, w;
        cin >> u >> v >> t >> w;
        int newW = (w - 3000000) / 100; // �������� ��� ������, ����� ������ ����������� ������
        if (newW <= 0) {
            continue;
        }

        g[u].push_back({ v, t, newW });
        g[v].push_back({ u, t, newW });
        uniqW.insert(newW);
    }

    vector<int> uniqWec(uniqW.begin(), uniqW.end());

    int l = 0;
    int r = uniqW.size() - 1;
    int maxW = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int minTime = dijkstra(uniqWec[m]);

        if (minTime == 0) {
            r = m - 1;
        }
        else {
            l = m + 1;
            maxW = max(maxW, uniqWec[m]);
        }
    }

    cout << maxW;

    return 0;
}

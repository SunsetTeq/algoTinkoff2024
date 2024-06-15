#include<iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
const long long INF = 1e18;
vector<vector<pair<int, long long>>> g;


vector<long long> dijkstra(int s) {
    vector<long long> d(n, INF);
    d[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<> > q;
    q.push({ 0, s });

    while (!q.empty()) {
        auto qTop = q.top();
        auto curDist = qTop.first;
        auto v = qTop.second;
        q.pop();
        if (curDist > d[v]) continue;
        for (auto& adj : g[v]) {
            auto u = adj.first;
            auto w = adj.second;
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push({ d[u], u });
            }
        }
    }
    return d;
}

long long myMin(long long a, long long b, long long c) {
    long long curMin = min(a, b);
    return min(curMin, c);
}

int main() {
    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    int a, b, c; cin >> a >> b >> c;
    a--; b--; c--;
    vector<long long> distFromA = dijkstra(a);
    vector<long long> distFromB = dijkstra(b);
    vector<long long> distFromC = dijkstra(c);

    long long res = INF;
    for (int i = 0; i < n; i++) {
        long long distAtoI = distFromA[i];
        long long distBtoI = distFromB[i];
        long long distCtoI = distFromC[i];

        if (distFromA[i] != INF || distFromB[i] != INF || distFromC[i] != INF) {
            long long minDist = myMin(distAtoI, distBtoI, distCtoI);
            if (minDist == distAtoI) {
                res = min(res, 2 * minDist + distBtoI + distCtoI);
            }
            if (minDist == distBtoI) {
                res = min(res, 2 * minDist + distAtoI + distCtoI);
            }
            if (minDist == distCtoI) {
                res = min(res, 2 * minDist + distAtoI + distBtoI);
            }
        }
        else continue;
    }

    res != INF ? cout << res : cout << -1;
    return 0;
}
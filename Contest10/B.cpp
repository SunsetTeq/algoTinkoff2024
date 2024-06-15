#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> p;
vector<long long> siz;

long long get(long long v) {
    return (v == p[v]) ? v : (p[v] = get(p[v]));
}

void unite(long long a, long long b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        p[b] = a;
        siz[a] += siz[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, pair<long long, long long>>> g; 
    p.resize(n);

    siz.resize(n, 1);
    for (long long i = 0; i < n; ++i)
        p[i] = i;

    for (long long i = 0; i < m; ++i) {
        long long u, v, w;
        cin >> u >> v >> w;
        g.push_back({ w, {u - 1, v - 1} }); 
    }

    sort(g.begin(), g.end());

    long long res = 0;

    for (long long i = 0; i < m; ++i) {
        long long a = g[i].second.first, b = g[i].second.second, l = g[i].first;
        if (get(a) != get(b)) {
            res += l;
            unite(a, b);
        }
    }

    cout << res;

    return 0;
}
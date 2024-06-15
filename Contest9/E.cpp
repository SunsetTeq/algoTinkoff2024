﻿#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

struct Cord {
    long long x, y1, y2, type;
};

vector<Cord>cords;
vector<long long>settt;
vector<long long>tree;; vector<long long>lazy;

void pull(int i, int l, int r) {
    if (lazy[i]) tree[i] = settt[r] - settt[l];
    else tree[i] = (l + 1 == r ? 0 : tree[i * 2] + tree[i * 2 + 1]);
}

void update(long long qL, long long qR, long long val, long long i, int tL, int tR) {
    if (qR <= tL || qL >= tR) return;
    if (tL >= qL && tR <= qR) {
        lazy[i] += val;
        pull(i, tL, tR);
        return;
    }
    int m = (tL + tR) / 2;
    update(qL, qR, val, i * 2, tL, m);
    update(qL, qR, val, i * 2 + 1, m, tR);
    pull(i, tL, tR);

}


int main() {
    int n; cin >> n;
    while (n--) {
        long long x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        x2++;
        y1--;
        cords.push_back({ x1, y1 , y2, 1 });
        cords.push_back({ x2, y1, y2, -1 });
        settt.push_back(y1); settt.push_back(y2);
    }

    long long mx = 0;

    sort(settt.begin(), settt.end());
    settt.erase(unique(settt.begin(), settt.end()), settt.end());
    long long m = settt.size();

    sort(cords.begin(), cords.end(), [](const Cord& a, const Cord& b) {
        if (a.x != b.x) return a.x < b.x;
        else return a.type > b.type; });


    lazy.resize(settt.size() * 4 + 5);
    tree.resize(settt.size() * 4 + 5);
    long long result = 0, lastEl = cords[0].x;
    for (auto& event : cords) {
        result += tree[1] * (event.x - lastEl);
        long long checker1 = lower_bound(settt.begin(), settt.end(), event.y1) - settt.begin();
        long long checker2 = lower_bound(settt.begin(), settt.end(), event.y2) - settt.begin();
        update(checker1, checker2, event.type, 1, 0, m - 1);
        lastEl = event.x;
    }

    cout << result;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>

using namespace std;

class SegmentTree {
private:
    vector<pair<long long, long long>> tree;
    long long n;

    void push(long long v, long long vl, long long vr) {
        long long& prom = tree[v].second;
        if (prom != 0) {
            tree[v].first += prom;
            if (vl != vr) {
                tree[v * 2 + 1].second += prom;
                tree[v * 2 + 2].second += prom;
            }
            prom = 0;
        }
    }

    void updateRangeUtil(long long v, long long left, long long right, long long qLeft, long long qRight, long long update) {
        push(v, left, right);

        if (left > right || left > qRight || right < qLeft)
            return;

        if (left >= qLeft && right <= qRight) {
            tree[v].second += update;
            push(v, left, right);
            return;
        }

        long long mid = left + (right - left) / 2;
        updateRangeUtil(v * 2 + 1, left, mid, qLeft, qRight, update);
        updateRangeUtil(v * 2 + 2, mid + 1, right, qLeft, qRight, update);

        tree[v].first = min(tree[v * 2 + 1].first, tree[v * 2 + 2].first);
    }

    long long getMinUtil(long long left, long long right, long long qleft, long long qright, long long v) {
        push(v, left, right);

        if (left > right || left > qright || right < qleft)
            return LLONG_MAX;

        if (left >= qleft && right <= qright)
            return tree[v].first;

        long long mid = left + (right - left) / 2;
        long long leftVal = getMinUtil(left, mid, qleft, qright, 2 * v + 1);
        long long rightVal = getMinUtil(mid + 1, right, qleft, qright, 2 * v + 2);

        return min(leftVal, rightVal);
    }

public:
    SegmentTree(long long size) {
        n = size;
        tree.resize(4 * n, { 0, 0 });
    }

    void update(long long l, long long r, long long value) {
        updateRangeUtil(0, 0, n - 1, l, r - 1, value);
    }

    long long query(long long l, long long r) {
        return getMinUtil(0, n - 1, l, r - 1, 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m; cin >> n >> m;

    SegmentTree st(n);

    while (m--) {
        long long op; cin >> op;
        if (op == 1) {
            long long ql, qr; long long update;
            cin >> ql >> qr >> update;
            st.update(ql, qr, update);
        }
        else if (op == 2) {
            long long ql, qr;
            cin >> ql >> qr;
            cout << st.query(ql, qr) << "\n";
        }
    }

    return 0;
}
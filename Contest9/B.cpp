#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>

using namespace std;

struct Info {
    long long sum = 0;
    long long padd = 0;
    long long pset = -1;
};

class SegmentTree {
private:
    vector<Info> tree;
    long long n;

    void push(long long v, long long vl, long long vr) {
        if (tree[v].pset != -1) {
            tree[v].sum = tree[v].pset * (vr - vl + 1);
            if (vl != vr) {
                tree[v * 2 + 1].pset = tree[v].pset;
                tree[v * 2 + 2].pset = tree[v].pset;
                tree[v * 2 + 1].padd = 0;
                tree[v * 2 + 2].padd = 0;
            }
            tree[v].pset = -1;
        }
        if (tree[v].padd) {
            tree[v].sum += tree[v].padd * (vr - vl + 1);
            if (vl != vr) {
                if (tree[v * 2 + 1].pset != -1) {
                    tree[v * 2 + 1].pset += tree[v].padd;
                }
                else {
                    tree[v * 2 + 1].padd += tree[v].padd;
                }

                if (tree[v * 2 + 2].pset != -1) {
                    tree[v * 2 + 2].pset += tree[v].padd;
                }
                else {
                    tree[v * 2 + 2].padd += tree[v].padd;
                }
            }
            tree[v].padd = 0;
        }
    }


    void updateAddUtil(long long v, long long left, long long right, long long qLeft, long long qRight, long long update) {
        push(v, left, right);

        if (left > right || left > qRight || right < qLeft)
            return;

        if (left >= qLeft && right <= qRight) {
            tree[v].padd += update;
            push(v, left, right);
            return;
        }

        long long mid = left + (right - left) / 2;
        updateAddUtil(v * 2 + 1, left, mid, qLeft, qRight, update);
        updateAddUtil(v * 2 + 2, mid + 1, right, qLeft, qRight, update);

        tree[v].sum = tree[v * 2 + 1].sum + tree[v * 2 + 2].sum;
    }


    void updateSetUtil(long long v, long long left, long long right, long long qLeft, long long qRight, long long update) {
        push(v, left, right);

        if (left > right || left > qRight || right < qLeft)
            return;

        if (left >= qLeft && right <= qRight) {
            tree[v].pset = update;
            tree[v].padd = 0;
            push(v, left, right);
            return;
        }

        long long mid = left + (right - left) / 2;
        updateSetUtil(v * 2 + 1, left, mid, qLeft, qRight, update);
        updateSetUtil(v * 2 + 2, mid + 1, right, qLeft, qRight, update);

        tree[v].sum = tree[v * 2 + 1].sum + tree[v * 2 + 2].sum;
    }

    long long getSumUtil(long long left, long long right, long long qleft, long long qright, long long v) {

        if (left > right || left > qright || right < qleft)
            return 0;

        push(v, left, right);

        if (left >= qleft && right <= qright)
            return tree[v].sum;

        long long mid = left + (right - left) / 2;
        long long leftVal = getSumUtil(left, mid, qleft, qright, 2 * v + 1);
        long long rightVal = getSumUtil(mid + 1, right, qleft, qright, 2 * v + 2);
        return leftVal + rightVal;
    }


public:
    SegmentTree(long long size) {
        n = size;
        tree.resize(4 * n, Info());
    }

    void updateAdd(long long l, long long r, long long value) {
        updateAddUtil(0, 0, n - 1, l, r - 1, value);
    }

    void updateSet(long long l, long long r, long long value) {
        updateSetUtil(0, 0, n - 1, l, r - 1, value);
    }

    long long query(long long l, long long r) {
        return getSumUtil(0, n - 1, l, r - 1, 0);
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
            st.updateSet(ql, qr, update);
        }
        else if (op == 2) {
            long long ql, qr; long long update;
            cin >> ql >> qr >> update;
            st.updateAdd(ql, qr, update);
        }
        else {
            long long ql, qr;
            cin >> ql >> qr;
            cout << st.query(ql, qr) << "\n";
        }
    }

    return 0;
}
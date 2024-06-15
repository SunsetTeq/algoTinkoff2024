#include <iostream>
#include <vector>
# include <algorithm>
using namespace std;

class SegmentTree {
private:
    vector<pair<long long, long long>> tree;
    long long n;

    long long getMid(long long l, long long r) { return l + (r - l) / 2; }

    pair<long long, long long>combine(pair<long long, long long>x1, pair<long long, long long>x2) {
        if (x1.first < x2.first)
            return x1;
        else if (x2.first < x1.first)
            return x2;
        else return { x1.first, x1.second + x2.second };
    }

    pair<long long, long long > getMin(long long tLeft, long long tRight, long long reqLeft, long long reqRight, long long vertex) {
        if (reqLeft <= tLeft && reqRight > tRight) // [reqLeft, reqRight)
            return tree[vertex];
        if (tRight < reqLeft || tLeft >= reqRight) 
            return { 1e9, 0 };
        long long mid = getMid(tLeft, tRight);
        return combine(getMin(tLeft, mid, reqLeft, reqRight, 2 * vertex + 1), getMin(mid + 1, tRight, reqLeft, reqRight, 2 * vertex + 2));
    }

    void update(long long tLeft, long long tRight, long long posUpdateElement, long long newValue, long long vertex) {
        if (posUpdateElement < tLeft || posUpdateElement > tRight) {         
            return;
        }

        if (tLeft == tRight) {
            tree[vertex] = { newValue, 1 };
            return;
        }

        long long mid = getMid(tLeft, tRight);
        if (posUpdateElement <= mid) {
            update(tLeft, mid, posUpdateElement, newValue, vertex * 2 + 1);
        }
        else {
            update(mid + 1, tRight, posUpdateElement, newValue, vertex * 2 + 2);
        }

        tree[vertex] = combine(tree[vertex * 2 + 1], tree[vertex * 2 + 2]);
    }

    void buildTree(const vector<long long>& arr, long long tLeft, long long tRight, long long vertex) {
        if (tLeft == tRight) {
            tree[vertex] = { arr[tLeft], 1 };
            return;
        }
        long long mid = getMid(tLeft, tRight);
        buildTree(arr, tLeft, mid, vertex * 2 + 1);
        buildTree(arr, mid + 1, tRight, vertex * 2 + 2);
        tree[vertex] = combine(tree[vertex * 2 + 1], tree[vertex * 2 + 2]);
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        long long max_size = 4 * n;
        tree.resize(max_size);
        buildTree(arr, 0, n - 1, 0);
    }

    pair<long long, long long> query(long long reqLeft, long long reqRight) { 
        return getMin(0, n - 1, reqLeft, reqRight, 0);
    }

    void modifity(vector<long long>& arr, long long vertex, long long new_val) {
        if (vertex < 0 || vertex > n - 1)
            return;
        arr[vertex] = new_val;
        update(0, n - 1, vertex, new_val, 0);
    }
};

int main() {
    long long n, t; cin >> n >> t;
    vector<long long>arr(n);
    for (long long i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree tree(arr);

    for (int j = 0; j < t; ++j) {
        long long op; cin >> op;
        if (op == 1) {
            long long posUpdateElement, newValue;
            cin >> posUpdateElement >> newValue;
            tree.modifity(arr, posUpdateElement, newValue);
        }
        else if (op == 2) {
            long long reqLeft, reqRight; cin >> reqLeft >> reqRight;
            pair<long long, long long> res = tree.query(reqLeft, reqRight);
            cout << res.first << " " << res.second << "\n";
        }
    }
    return 0;
}
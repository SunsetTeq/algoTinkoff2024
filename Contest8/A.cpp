#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    long long n;

    long long getMid(long long l, long long r) { return l + (r - l) / 2; }

    long long getSum(long long tLeft, long long tRight, long long reqLeft, long long reqRight, long long vertex) {
        if (reqLeft <= tLeft && reqRight > tRight) 
            return tree[vertex];
        if (tRight < reqLeft || tLeft >= reqRight) 
            return 0;
        long long mid = getMid(tLeft, tRight);
        return getSum(tLeft, mid, reqLeft, reqRight, 2 * vertex + 1) +
            getSum(mid + 1, tRight, reqLeft, reqRight, 2 * vertex + 2);
    }

    void update(long long tLeft, long long tRight, long long posUpdateElement, long long newValue, long long vertex) {
        if (posUpdateElement < tLeft || posUpdateElement > tRight)
            return;
        tree[vertex] += newValue;
        if (tRight != tLeft) {
            long long mid = getMid(tLeft, tRight);
            update(tLeft, mid, posUpdateElement, newValue, vertex * 2 + 1);
            update(mid + 1, tRight, posUpdateElement, newValue, vertex * 2 + 2);
        }
    }

    long long constructSTUtil(const vector<long long>& arr, long long tLeft, long long tRight, long long vertex) {
        if (tLeft == tRight) {
            tree[vertex] = arr[tLeft];
            return arr[tLeft];
        }
        long long mid = getMid(tLeft, tRight);
        tree[vertex] = constructSTUtil(arr, tLeft, mid, vertex * 2 + 1) +
            constructSTUtil(arr, mid + 1, tRight, vertex * 2 + 2);
        return tree[vertex];
    }

public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        long long max_size = 4 * n;
        tree.resize(max_size);
        constructSTUtil(arr, 0, n - 1, 0);
    }

    long long query(long long reqLeft, long long reqRight) { 
        return getSum(0, n - 1, reqLeft, reqRight, 0);
    }

    void modifity(vector<long long>& arr, long long i, long long new_val) {
        if (i < 0 || i > n - 1)
            return;
        long long diff = new_val - arr[i];
        arr[i] = new_val;
        update(0, n - 1, i, diff, 0);
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
            cout << tree.query(reqLeft, reqRight) << "\n";
        }
    }
    return 0;
}
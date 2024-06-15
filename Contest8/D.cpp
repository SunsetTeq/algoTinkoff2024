#include <iostream>
#include <vector>
using namespace std;

class SegmentTreeKOne {
private:
    vector<long long> tree;
    long long n;

    long long getMid(long long l, long long r) { return l + (r - l) / 2; }

    long long kOne(long long tLeft, long long tRight, long long vertex, long long l, long long k) {
        if (tree[vertex] < k || tRight < l)
            return -1;
        if (tRight == tLeft)
            return tLeft;

        long long mid = getMid(tLeft, tRight);

        long long left = kOne(tLeft, mid, vertex * 2 + 1, l, k);
        if (left != -1) return left;
        return kOne(mid + 1, tRight, vertex * 2 + 2, l, k);
    }

    void update(long long tLeft, long long tRight, long long posUpdateElement, long long vertex, long long newValue) {
        if (posUpdateElement < tLeft || posUpdateElement > tRight) {
            return;
        }

        if (tLeft == tRight) {
            tree[vertex] = newValue;
            return;
        }

        long long mid = getMid(tLeft, tRight);
        if (posUpdateElement <= mid) {
            update(tLeft, mid, posUpdateElement, vertex * 2 + 1, newValue);
        }
        else {
            update(mid + 1, tRight, posUpdateElement, vertex * 2 + 2, newValue);
        }
        tree[vertex] = max(tree[vertex * 2 + 1], tree[vertex * 2 + 2]);
    }

    void buildTree(const vector<long long>& arr, long long tLeft, long long tRight, long long vertex) {
        if (tLeft == tRight) {
            tree[vertex] = arr[tLeft];
            return;
        }
        long long mid = getMid(tLeft, tRight);
        buildTree(arr, tLeft, mid, vertex * 2 + 1);
        buildTree(arr, mid + 1, tRight, vertex * 2 + 2);
        tree[vertex] = max(tree[vertex * 2 + 1], tree[vertex * 2 + 2]);
    }

public:
    SegmentTreeKOne(const vector<long long>& arr) {
        n = arr.size();
        long long max_size = 4 * n;
        tree.resize(max_size);
        buildTree(arr, 0, n - 1, 0);
    }

    long long query(long long l, long long k) {
        return kOne(0, n - 1, 0, l, k);
    }

    void modifity(long long posUpdateElement, long long newValue) {
        if (posUpdateElement < 0 || posUpdateElement > n - 1)
            return;
        update(0, n - 1, posUpdateElement, 0, newValue);
    }
};

int main() {
    long long n, t; cin >> n >> t;
    vector<long long>arr(n);
    for (long long i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTreeKOne tree(arr);

    for (int j = 0; j < t; ++j) {
        long long op; cin >> op;
        if (op == 1) {
            long long posUpdateElement, newValue;
            cin >> posUpdateElement >> newValue;
            tree.modifity(posUpdateElement, newValue);
        }
        else if (op == 2) {
            long long l, k; cin >> k >> l;
            cout << tree.query(l, k) << "\n";
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class SegmentTreeKOne {
private:
    vector<long long> tree;
    long long n;

    long long getMid(long long l, long long r) { return l + (r - l) / 2; }

    long long kOne(long long tLeft, long long tRight, long long k, long long vertex) {
        if (k > tree[vertex])
            return -1;
        if (tRight == tLeft)
            return tLeft;
        long long mid = getMid(tLeft, tRight);
        if (tree[vertex * 2 + 1] >= k)
            return kOne(tLeft, mid, k, vertex * 2 + 1);
        else
            return kOne(mid + 1, tRight, k - tree[vertex * 2 + 1], vertex * 2 + 2);
    }

    void update(long long tLeft, long long tRight, long long posUpdateElement, long long vertex) {
        if (posUpdateElement < tLeft || posUpdateElement > tRight) {
            return;
        }

        if (tLeft == tRight) {
            tree[vertex] == 1 ? tree[vertex] = 0 : tree[vertex] = 1;
            return;
        }

        long long mid = getMid(tLeft, tRight);
        if (posUpdateElement <= mid) {
            update(tLeft, mid, posUpdateElement, vertex * 2 + 1);
        }
        else {
            update(mid + 1, tRight, posUpdateElement, vertex * 2 + 2);
        }
        tree[vertex] = tree[vertex * 2 + 1] + tree[vertex * 2 + 2];
    }

    long long buildTree(const vector<long long>& arr, long long tLeft, long long tRight, long long vertex) {
        if (tLeft == tRight) {
            tree[vertex] = arr[tLeft];
            return arr[tLeft];
        }
        long long mid = getMid(tLeft, tRight);
        buildTree(arr, tLeft, mid, vertex * 2 + 1);
        buildTree(arr, mid + 1, tRight, vertex * 2 + 2);
        tree[vertex] = tree[vertex * 2 + 1] + tree[vertex * 2 + 2];
        return tree[vertex];
    }

public:
    SegmentTreeKOne(const vector<long long>& arr) {
        n = arr.size();
        long long max_size = 4 * n;
        tree.resize(max_size);
        buildTree(arr, 0, n - 1, 0);
    }

    long long query(long long k) {
        return kOne(0, n - 1, k, 0);
    }

    void modifity(vector<long long>& arr, long long vertex) {
        if (vertex < 0 || vertex > n - 1)
            return;
        arr[vertex] == 1 ? arr[vertex] = 0 : arr[vertex] = 1;
        update(0, n - 1, vertex, 0);
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
            long long posUpdateElement;
            cin >> posUpdateElement;
            tree.modifity(arr, posUpdateElement);
        }
        else if (op == 2) {
            long long k; cin >> k;
            cout << tree.query(k + 1) << "\n";
        }
    }
    return 0;
}
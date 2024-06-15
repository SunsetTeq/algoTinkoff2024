#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) : n(size), tree(4 * size + 5, 0) {}

    void update(int idx, int increment) {
        idx++;
        for (; idx < tree.size(); idx += idx & -idx) {
            tree[idx] += increment;
        }
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    int query(int idx) {
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> temp = a;
    sort(temp.begin(), temp.end());
    unordered_map<long long, int> rank;
    int mx = 0;

    for (auto& value : temp) {
        if (rank.find(value) == rank.end()) {
            rank[value] = mx++;
        }
    }

    SegmentTree st_left(mx), st_right(mx);
    vector<int> gr(n, 0), le(n, 0);

    for (int j = 0; j < n; j++) {
        int ranked_index = rank[a[j]];
        gr[j] = st_right.query(ranked_index + 1, mx - 1);
        st_right.update(ranked_index, 1);
    }

    for (int j = n - 1; j >= 0; j--) {
        int ranked_index = rank[a[j]];
        le[j] = st_left.query(0, ranked_index - 1);
        st_left.update(ranked_index, 1);
    }

    long long result = 0;
    for (int j = 0; j < n; j++) {
        result += (long long)gr[j] * le[j];
    }

    cout << result;
    return 0;
}

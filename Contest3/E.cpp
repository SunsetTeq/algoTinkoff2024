#include <iostream>
#include <vector>

using namespace std;


struct Tree {
    vector<long long> tree{ 0 };

    void sift_down(long long v, long long n) {
        while (2 * v <= n) {
            long long lSon = 2 * v;
            long long rSon = 2 * v + 1;

            long long u = rSon <= n && tree[rSon] > tree[lSon] ? rSon : lSon;

            if (tree[v] > tree[u])
                break;

            swap(tree[v], tree[u]);
            v = u;
        }
    }

    void build_heap(long long n) {
        for (long long i = n / 2; i >= 1; --i) {
            sift_down(i, n);
        }
    }

    void heap_sort(long long n) {
        build_heap(n);
        for (long long i = n; i > 1; --i) {
            swap(tree[1], tree[i]);
            sift_down(1, i - 1);
        }
    }

    void print() {
        for (long long i = 1; i < tree.size(); ++i)
            cout << tree[i] << " ";
    }

    void push(long long x) {
        tree.push_back(x);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    Tree tree;

    for (long long i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        tree.push(x);
    }

    tree.heap_sort(n);
    tree.print();

    return 0;
}
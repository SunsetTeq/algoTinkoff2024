# include <iostream>
# include <vector>
# include <algorithm>


using namespace std;

struct Node {
    int sumBlackSegments;
    int cntBlackSegments;
    int set;
    int l;
    int r;
    bool up;

    Node()
        : sumBlackSegments(1), cntBlackSegments(1), set(0), l(0), r(0), up(false)
    {}

    Node(int n, int seg, int s, int left, int right, bool u)
        : sumBlackSegments(n), cntBlackSegments(seg), set(s), l(left), r(right), up(u)
    {}
};

vector<Node>tree;

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = Node(0, 0, 0, l, r, false);
    }
    else {
        int mid = l + (r - l) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        tree[v] = Node(0, 0, 0, l, r, false);
    }
}

void push(int v) {
    if (!tree[v].up)
        return;

    tree[v].sumBlackSegments = tree[v].set * (tree[v].r - tree[v].l + 1);
    tree[v].cntBlackSegments = 1 * tree[v].set;
    tree[v].up = false;

    if (tree[v].l == tree[v].r)
        return;

    tree[v * 2].set = tree[v].set;
    tree[v * 2 + 1].set = tree[v].set;

    tree[v * 2].up = true;
    tree[v * 2 + 1].up = true;
}

bool rightisblack(int v) {
    push(v);

    if (tree[v].l == tree[v].r)
        return tree[v].sumBlackSegments == 1;

    return rightisblack(v * 2 + 1);
}

bool leftisblack(int v) {
    push(v);

    if (tree[v].l == tree[v].r)
        return tree[v].sumBlackSegments == 1;

    return leftisblack(v * 2);
}


void update(int v, int value, int l, int r) {
    if (tree[v].r < l || tree[v].l > r)
        return;

    if (tree[v].r <= r && tree[v].l >= l) {
        push(v);
        tree[v].set = value;
        tree[v].up = true;
        return;
    }

    push(v);
    update(v * 2, value, l, r);
    update(v * 2 + 1, value, l, r);

    bool left = rightisblack(v * 2);
    bool right = leftisblack(v * 2 + 1);

    tree[v].sumBlackSegments = tree[v * 2].sumBlackSegments + tree[v * 2 + 1].sumBlackSegments;
    tree[v].cntBlackSegments = tree[v * 2 + 1].cntBlackSegments + tree[v * 2].cntBlackSegments;

    if (left && right) {    
        tree[v].cntBlackSegments--;
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int minIndx = 500001, maxIndx = -500001;
    vector<int>color(n);
    vector<int>cords(n);
    vector<int>dif(n);

    for (int i = 0; i < n; ++i) {
        char op; cin >> op;
        int x, l; cin >> x >> l;  
        color[i] = op;
        cords[i] = x;


        if (l > 0) l--;
        else l++;

        dif[i] = l;

        int r = x + l;  

        if (r > maxIndx)
            maxIndx = r;

        if (minIndx > x) minIndx = x;

    }

    int length;
    if (minIndx < 0)
        length = maxIndx - minIndx + 1;
    else
        length = maxIndx + 1;

    tree.resize(4 * length + 5);

    build(1, 0, length);
    for (int i = 0; i < n; i++) {
        if (color[i] == 'W') {
            update(1, 0, cords[i] - minIndx, cords[i] + dif[i] - minIndx);
            cout << tree[1].cntBlackSegments << " " << tree[1].sumBlackSegments << "\n";
        }

        else if (color[i] == 'B') {
            update(1, 1, cords[i] - minIndx, cords[i] + dif[i] - minIndx);
            cout << tree[1].cntBlackSegments << " " << tree[1].sumBlackSegments << "\n";
        }
    }

    return 0;
}
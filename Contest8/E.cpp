# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_map>

using namespace std;

const long long MOD = 1e9 + 7;
vector<pair<long long, long long>> tree; // MxLength,ways

int compress(vector<long long>& nums) {   
    int n = nums.size();

    vector<long long> temp = nums;
    sort(temp.begin(), temp.end());

    unordered_map<long long, int> rank;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        if (rank.find(temp[i]) == rank.end()) {
            rank[temp[i]] = mx++;
        }
    }

    for (int i = 0; i < n; i++) {
        nums[i] = rank[nums[i]];
    }

    return mx;
}

pair<int, int> relax(pair<long long, long long>& left, pair<long long, long long>& right) {
    pair<int, int> res;

    if (left.first > right.first) {
        res = { left.first, left.second };
    }
    else if (left.first < right.first) {
        res = { right.first, right.second };
    }
    else {
        res.first = left.first;
        res.second = (left.second + right.second) % MOD;
    }
    return res;
}

void update(int tLeft, int tRight, int parent, int element, long long mxLength, long long ways) {   
    if (tLeft == tRight) {
        if (tree[parent].first == mxLength) {   
            tree[parent].second = (tree[parent].second + ways) % MOD;
        }
        else { 
            tree[parent] = { mxLength, ways };
        }
        return;
    }
    int mid = tLeft + (tRight - tLeft) / 2;

    if (element <= mid) {
        update(tLeft, mid, 2 * parent + 1, element, mxLength, ways);
    }
    else {
        update(mid + 1, tRight, 2 * parent + 2, element, mxLength, ways);
    }

    tree[parent] = relax(tree[2 * parent + 1], tree[2 * parent + 2]);
}

pair<long long, long long> maxLen(int tLeft, int tRight, int reqLeft, int reqRight, int vertex) {
    if (tLeft > reqRight || tRight < reqLeft) {
        return { 0, 0 };
    }
    if (tLeft >= reqLeft && tRight <= reqRight) {
        return tree[vertex];
    }
    int mid = (tLeft + tRight) / 2;
    pair<long long, long long> left = maxLen(tLeft, mid, reqLeft, reqRight, 2 * vertex + 1);
    pair<long long, long long> right = maxLen(mid + 1, tRight, reqLeft, reqRight, 2 * vertex + 2);
    return relax(left, right);
}

int query(vector<long long>& arr) {
    int n = arr.size();

    int mx = compress(arr);

    tree.resize(4 * mx + 5);

    for (int i = 0; i < n; i++) {


        long long mxLen = 1;
        long long ways = 1;

        if (arr[i] > 0) {
            pair<long long, long long> info = maxLen(0, mx, 0, arr[i] - 1, 0);
            if (info.first + 1 > mxLen) {
                mxLen = info.first + 1;
                ways = info.second;
            }
        }

        update(0, mx, 0, arr[i], mxLen, ways);
    }
    return tree[0].second;
}

int main()
{

    int n; cin >> n;
    vector<long long>arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << query(arr) % MOD;
}
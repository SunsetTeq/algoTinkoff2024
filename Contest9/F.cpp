#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <math.h>


using namespace std;

struct Cord {
    long long x, y, id;
};

vector<long long>fenv;


void helper(long long i, long long updVal) {
    while (i < fenv.size()) {
        fenv[i] += updVal;
        i = i | (i + 1);
    }
}

void updAdd(long long l, long long r, long long updVal) {
    helper(l, updVal);
    helper(r, -updVal);
}

long long query(long long i) {
    long long sum = 0;
    while (i >= 0) {
        sum += fenv[i];
        i = (i & (i + 1)) - 1;
    }
    return sum;
}

int main() {
    long long w, h, n; cin >> w >> h >> n;
    vector<Cord>centers(n);
    for (long long i = 0; i < n; ++i) {
        long double x, y;
        cin >> x >> y;
        centers[i] = Cord({ (long long)round(x * 2), (long long)round(y * 2), i });
    }

    vector<long long>yCords(n);
    for (int i = 0; i < n; ++i) {
        yCords[i] = centers[i].y;
    }
    sort(yCords.begin(), yCords.end());
    yCords.erase(unique(yCords.begin(), yCords.end()), yCords.end());

    fenv.resize(yCords.size() * 2);

    sort(centers.begin(), centers.end(), [](const Cord& left, const Cord& right) {
        return left.x < right.x;
        });

    vector<long long>result(n, 0);

    for (const auto& center : centers) {
        auto it = lower_bound(yCords.begin(), yCords.end(), center.y);
        if (it == yCords.end() || *it != center.y) {
            break;
        }
        long long index = it - yCords.begin();
        long long dist = center.x - query(index);
        if (dist <= 0) {
            break;
        }
        if (result[center.id] != 0) {
            break;
        }

        result[center.id] = dist;

        it = upper_bound(yCords.begin(), yCords.end(), center.y - dist);
        long long leftIndx = it - yCords.begin();

        it = upper_bound(yCords.begin(), yCords.end(), center.y + dist);
        long long riIndex = it - yCords.begin();

        updAdd(leftIndx, riIndex, dist * 2);
    }

    for (auto x : result) {
        cout << x << " ";
    }


    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void check(long long n, long long bord) {
    vector<pair<long long, int>> res;

    for (long long i = 2; i <= bord; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                ++count;
            }
            res.emplace_back(i, count);
        }
    }

    if (n != 1) res.emplace_back(n, 1);

    for (size_t i = 0; i < res.size(); ++i) {
        if (res[i].second == 1) cout << res[i].first;
        else cout << res[i].first << "^" << res[i].second;

        if (i != res.size() - 1) cout << "*";
    }
}


int main() {
    long long n; cin >> n;
    long long bord = static_cast<long long>(sqrt(n)) + 1;
    check(n, bord);
    return 0;
}
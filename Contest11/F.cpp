#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long n; int  m;
    cin >> n >> m;

    vector<unsigned long long> a;
    for (int i = 0; i < m; ++i) {
        unsigned long long x;
        cin >> x;
        a.push_back(x);
        a.push_back(x);
    }

    vector<unsigned long long>realres;
    int check = -1;
    unsigned long long min_cnt = 1e18 + 5;
    bool found = false;

    for (unsigned long long mask = 0; mask < (1 << (2 * m)); ++mask) {
        unsigned long long sum = 0;
        unsigned long long cnt = 0;
        vector<unsigned long long>res;
        for (unsigned long long i = 0; i < 2 * m; ++i) {
            if ((mask >> i) & 1) {
                sum += a[i];
                cnt += 1;
                res.push_back(a[i]);
            }
        }
        if (sum == n && cnt < min_cnt) {
            min_cnt = cnt;
            realres.clear();
            realres = res;
            res.clear();
            found = true;
        }
        else if (sum > n) {
            check = 0;
        }
        cnt = 0;
    }

    if (!found) {
        cout << check;
    }
    else {
        cout << min_cnt << "\n";
        for (auto& x : realres) cout << x << " ";
    }

    return 0;
}

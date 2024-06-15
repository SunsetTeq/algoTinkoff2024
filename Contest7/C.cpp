#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    a[1] = 0;

    for (int i = 2; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n + 1);
    vector<int> p(n + 1);
    deque<int> window;

    dp[1] = 0;
    window.push_back(1);

    for (int i = 2; i <= n; ++i) {
        while (!window.empty() && window.front() < i - k) {
            window.pop_front();
        }

        if (!window.empty()) {
            int best = window.front();
            dp[i] = dp[best] + a[i];
            p[i] = best;
        }

        while (!window.empty() && dp[window.back()] <= dp[i]) {
            window.pop_back();
        }
        window.push_back(i);
    }

    cout << dp[n] << "\n";

    vector<int> res;
    int i = n;
    while (i != 0) {
        res.push_back(i);
        i = p[i];
    }

    cout << res.size() - 1 << "\n";
    for (int j = res.size() - 1; j >= 0; --j) {
        cout << res[j] << (j > 0 ? " " : "");
    }

    return 0;
}
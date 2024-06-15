#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int l, n;
    cin >> l >> n;

    vector<int> cuts(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> cuts[i];
    }

    cuts[0] = 0;
    cuts[n + 1] = l;
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 2; len <= n + 1; ++len) {
        for (int i = 0; i <= n + 1 - len; ++i) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
        }
    }

    cout << dp[0][n + 1];
    return 0;
}
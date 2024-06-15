#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    n += 2; m += 2;
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    dp[2][2] = 1;

    int i = 2, j = 2;

    while (i != n - 1 || j != m - 1) {
        int x = i, y = j;
        while (x >= 2 && y < m) {
            dp[x][y] += dp[x - 2][y - 1] + dp[x - 2][y + 1] + dp[x - 1][y - 2] + dp[x + 1][y - 2];
            x--;
            y++;
        }
        i == n - 1 ? j++ : i++;
    }

    dp[n - 1][m - 1] += dp[n - 3][m - 2] + dp[n - 3][m] + dp[n - 2][m - 3] + dp[n][m - 3];

    cout << dp[n - 1][m - 1];
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s, reverse_s;
    cin >> s;
    reverse_s = s;
    reverse(reverse_s.begin(), reverse_s.end());

    int n = s.size();
    vector<vector<string>> dp(n + 1, vector<string>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == reverse_s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + s[i - 1];
            }
            else {
                dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    cout << dp[n][n].length() << "\n";
    cout << dp[n][n];
    return 0;
}
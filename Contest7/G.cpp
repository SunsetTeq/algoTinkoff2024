#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

bool isPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

void rec(int l, int r, const vector<vector<int>>& dp, const vector<vector<int>>& pos, const string& s) {
    int temp = r - l + 1;
    if (dp[l][r] == temp) {
        return;
    }
    if (dp[l][r] == 0) {
        cout << s.substr(l, r - l + 1);
        return;
    }
    if (pos[l][r] == -1) {
        cout << s[l];
        rec(l + 1, r - 1, dp, pos, s);
        cout << s[r];
        return;
    }
    rec(l, pos[l][r], dp, pos, s);
    rec(pos[l][r] + 1, r, dp, pos, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> pos(n, vector<int>(n, -1));

    for (int right = 0; right < n; ++right) {
        for (int left = right; left >= 0; --left) {
            if (left == right) {
                dp[left][right] = 1;
            }
            else {
                int min_val = numeric_limits<int>::max();
                int min_k = -1;
                bool b1 = s[left] == '(' && s[right] == ')';
                bool b2 = s[left] == '[' && s[right] == ']';
                bool b3 = s[left] == '{' && s[right] == '}';
                if (b1 || b2 || b3) {
                    min_val = dp[left + 1][right - 1];
                }
                for (int k = left; k < right; ++k) {
                    if (min_val > dp[left][k] + dp[k + 1][right]) {
                        min_val = dp[left][k] + dp[k + 1][right];
                        min_k = k;
                    }
                }
                dp[left][right] = min_val;
                pos[left][right] = min_k;
            }
        }
    }

    rec(0, n - 1, dp, pos, s);
    return 0;
}
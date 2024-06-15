#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string compress(const string& s, int start, int end, vector<vector<string>>& dp);

string result(const string& s) {
    int n = s.length();
    vector<vector<string>> dp(n, vector<string>(n, ""));
    return compress(s, 0, n - 1, dp);
}

int main() {
    string s; cin >> s;
    cout << result(s);

    return 0;
}

string compress(const string& s, int start, int end, vector<vector<string>>& dp) {
    if (!dp[start][end].empty()) return dp[start][end];

    string segment = s.substr(start, end - start + 1);
    dp[start][end] = segment;

    for (int k = start; k < end; ++k) {
        string left = compress(s, start, k, dp);
        string right = compress(s, k + 1, end, dp);
        if (left.length() + right.length() < dp[start][end].length()) {
            dp[start][end] = left + right;
        }
    }

    for (int len = 1; len <= (end - start + 1); ++len) {
        if ((end - start + 1) % len == 0) {
            string smallSeg = s.substr(start, len);
            int numRepeats = (end - start + 1) / len;
            string pattern = smallSeg;
            for (int i = 1; i < numRepeats; ++i)
                pattern += smallSeg;
            if (pattern == segment) {
                string opt = to_string(numRepeats) + "(" + compress(s, start, start + len - 1, dp) + ")";
                if (opt.length() < dp[start][end].length()) {
                    dp[start][end] = opt;
                }
            }
        }
    }

    return dp[start][end];
}

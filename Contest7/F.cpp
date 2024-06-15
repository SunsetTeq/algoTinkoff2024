# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int maxLeft = 0, maxRight = 0, maxSize = 0;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>>arr(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>>dp(n + 1, vector<int>(m + 1));
	dp[1][1] = arr[1][1]; 

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (arr[i][j] == 1) {
				dp[i][j] = min({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
				if (dp[i][j] >= maxSize) {
					maxSize = dp[i][j];
					maxLeft = i;
					maxRight = j;
				}
			}

		}
	}


	maxLeft = maxLeft - maxSize + 1;
	maxRight = maxRight - maxSize + 1;
	cout << maxSize << "\n" << maxLeft << " " << maxRight;

}
# include <iostream>
# include <vector>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int>a(n + 1);
	vector<int>dp(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	if (n == 1) {
		cout << a[1];
		return 0;
	}

	dp[0] = 0; dp[1] = a[1]; dp[2] = min(dp[1], 0) + a[2];
	for (int i = 3; i <= n; ++i) {
		dp[i] = a[i] + min(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n];
	return 0;
}
# include <iostream>
# include <vector>

using namespace std;

int main()
{
	long long n, m, k; cin >> n >> m >> k;

	vector<vector<long long>>nums(n + 1, vector<long long>(m + 1));
	vector<vector<long long>>pSum(n + 1, vector<long long>(m + 1));

	for (long long i = 1; i <= n; ++i)
	{
		for (long long j = 1; j <= m; ++j)
		{
			cin >> nums[i][j];
			pSum[i][j] = nums[i][j] + pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
		}
	}

	while (k--)
	{
		long long x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << pSum[x2][y2] - pSum[x2][y1 - 1] - pSum[x1 - 1][y2] + pSum[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}
# include <iostream>
# include <vector>

using namespace std;

int main()
{
	long long n; cin >> n;

	vector<long long>nums(n + 1);
	vector<pair<long long, long long>>pSor(n + 1);

	for (long long i = 1; i <= n; ++i)
	{
		cin >> nums[i];
		pSor[i].first = pSor[i - 1].first + nums[i];
		pSor[i].second = pSor[i - 1].second ^ nums[i];
	}

	long long m; cin >> m;
	while (m--)
	{
		long long x; cin >> x;
		if (x == 1)
		{
			long long x1, x2;
			cin >> x1 >> x2;
			cout << pSor[x2].first - pSor[x1 - 1].first << "\n";
		}
		else
		{
			long long x1, x2;
			cin >> x1 >> x2;
			cout << (pSor[x2].second ^ pSor[x1 - 1].second) << "\n";
		}
	}

	/*for (int i = 1; i <= n; ++i)
	{
		cout << pSor[i].first << " " << pSor[i].second << "\n";
	}*/
	return 0;
}
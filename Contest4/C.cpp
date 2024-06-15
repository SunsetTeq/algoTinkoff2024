# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

long long n, k;

bool choice(vector<long long>& a, long long x);


int main()
{
	cin >> n >> k;
	vector<long long>a(n);
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	long long l = 0, r = a[a.size() - 1] - a[0] + 1;
	while (r - l > 1)
	{
		long long mid = (r + l) / 2;
		if (choice(a, mid))
			l = mid;
		else
			r = mid;
	}
	cout << l;
	return 0;
}

bool choice(vector<long long>& a, long long x)
{
	long long cows = 1;
	long long predCow = a[0];
	for (long long i = 0; i < n; ++i)
	{
		if (a[i] - predCow >= x)
		{
			cows++;
			predCow = a[i];
		}
	}
	return cows >= k;
}
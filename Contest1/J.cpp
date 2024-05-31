# include <iostream>

using namespace std;
long long n, m;

long long s_vert(long long n, long long m);
long long s_hor(long long n, long long m);

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;

		long long x_h = s_hor(n, m) - 1;
		long long s_h = abs((((x_h * m + 1 + n * m) * (n * m - x_h * m)) / 2) - (((1 + x_h * m) * x_h * m) / 2));

		long long x_v = s_vert(n, m) - 1;
		long long s_v = abs(((((n - 1) * m * n + (x_v + 1 + m) * n) * (m - x_v)) / 2) - ((((n - 1) * m * n + (x_v + 1) * n) * x_v) / 2));

		if (s_v <= s_h)
			cout << "V" << " " << x_v + 1 << "\n";
		else
			cout << "H" << " " << x_h + 1 << "\n";
	}

	return 0;

}

long long s_vert(long long n, long long m)
{
	long long left = 0, right = m - 1;
	long long best_dif = 1e18, x = 0;

	while (right >= left)
	{
		long long mid = left + (right - left) / 2;
		long long L = (((n - 1) * m * n + (mid + 1) * n) * mid) / 2;
		long long R = (((n - 1) * m * n + (mid + 1 + m) * n) * (m - mid)) / 2;
		long long dif = abs(R - L);
		if (dif < best_dif)
		{
			best_dif = dif;
			x = mid;
		}

		if (L < R)
			left = mid + 1;
		else
			right = mid - 1;

	}

	if (abs(((((n - 1) * m * n + (x + 1 + m) * n) * (m - x)) / 2) - ((((n - 1) * m * n + (x + 1) * n) * x) / 2)) < abs(((((n - 1) * m * n + ((x - 1) + 1 + m) * n) * (m - (x - 1))) / 2) - ((((n - 1) * m * n + ((x - 1) + 1) * n) * (x - 1)) / 2)))
		return x + 1;
	else
		return x;

}



long long s_hor(long long n, long long m)
{
	long long x = 0, left = 0, right = n - 1;
	long long best_dif = 1e18;

	while (right >= left)
	{
		long long mid = left + (right - left) / 2;
		long long U = ((1 + mid * m) * mid * m) / 2;
		long long D = ((mid * m + 1 + n * m) * (n * m - mid * m)) / 2;

		long long dif = abs(D - U);
		if (dif < best_dif)
		{
			best_dif = dif;
			x = mid;
		}

		if (U < D)
			left = mid + 1;
		else
			right = mid - 1;
	}


	if (abs((((x * m + 1 + n * m) * (n * m - x * m)) / 2) - (((1 + x * m) * x * m) / 2)) < abs(((((x - 1) * m + 1 + n * m) * (n * m - (x - 1) * m)) / 2) - (((1 + (x - 1) * m) * (x - 1) * m) / 2)))
		return x + 1;
	else
		return x;
}
# include <iostream>
# include <cmath>
#include <iomanip>

using namespace std;

double c;

double binSearch(double c);

int main()
{
	cin >> c;
	cout << setprecision(7) << binSearch(c);
}

double check(double c)
{
	return pow(c, 2) + pow(c + 1, 0.5);
}

double binSearch(double c)
{
	double l = 0, r = c;
	while (r - l > 1e-6)
	{
		double mid = l + (r - l) / 2;
		if (check(mid) < c)
		{
			l = mid;
		}
		else if (check(mid) > c)
		{
			r = mid;
		}
	}
	return (r + l) / 2;
}
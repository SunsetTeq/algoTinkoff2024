# include <iostream>
# include <cmath>
#include <iomanip>

using namespace std;

double a, b, c, d;

double binSearch();

int main()
{
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(4) << binSearch();	
}

double check(double x)
{
	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double binSearch()
{
	double l = -1000000, r = 1000000;
	while (r - l > 1e-9)
	{
		double mid = l + (r - l) / 2;
		if (check(mid) * check(l) <= 0)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	return l + (r - l) / 2;	
}
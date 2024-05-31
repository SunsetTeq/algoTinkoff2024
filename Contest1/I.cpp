# include <iostream>
# include <vector>

using namespace std;

int n;

int last, coin = 1, debaf = 0;

void checkNul(vector<int>& a, int& last);

int main()
{
	cin >> n;
	vector<int>a(n, 0);
	vector<int>res;
	res.push_back(1);

	last = n - 1;
	for (int i = 0; i < n - 1; ++i)
	{
		int x;
		cin >> x;
		a[x - 1] = 1;
		if (x - 1 != last)
		{
			res.push_back(i + 1 + coin - debaf);
		}
		else
		{
			last--;
			debaf++;
			checkNul(a, last);
			res.push_back(i + 1 + coin - debaf);
		}
	}
	for (auto x : res)
		cout << x << " ";
	cout << 1;

}

void checkNul(vector<int>& a, int& last)
{
	for (int i = last; i >= 0; --i)
	{
		if (a[i] == 0)
		{
			last = i;
			return;
		}
		else
		{
			debaf++;
		}
	}
}
# include <iostream>
# include <vector>

using namespace std;

int n;

void antiQsort(vector<int>& a)
{
	for (int i = 0; i < n; ++i)
	{
		swap(a[i], a[i / 2]);
	}
}

int main()
{
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;

	antiQsort(a);

	for (auto x : a)
		cout << x << " ";
}
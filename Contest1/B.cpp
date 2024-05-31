# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;


vector<int>a;

int binSearch(int k);

int main()
{
	int n, k;
	cin >> n >> k;
	a.resize(n);
	vector<int>kList(k);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < k; ++i)
		cin >> kList[i];
	for (int i = 0; i < k; ++i)
	{
		cout << binSearch(kList[i]) << "\n";
	}
}


int binSearch(int k)
{
	int l = 0, r = a.size() - 1;
	if (k < a[l]) return a[l];
	if (k > a[r]) return a[r];
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] < k)
		{
			l = mid + 1;
		}
		else if (a[mid] > k)
		{
			r = mid - 1;
		}
		else
			return a[mid];
	}

	if (l >= a.size()) return a[a.size() - 1];
	if (r < 0) return a[0];
	if (abs(a[l] - k) < abs(a[r] - k))
		return a[l];
	else if (abs(a[l] - k) == abs(a[r] - k))
		return min(a[l], a[r]);
	else
		return a[r];
}
# include <iostream>
# include <vector>

using namespace std;

vector<int>a;

bool binSearch(int k);

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
		if (!binSearch(kList[i])) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
}


bool binSearch(int k)
{
	int l = 0, r = a.size() - 1;
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
			return true;
	}

	return false;
}
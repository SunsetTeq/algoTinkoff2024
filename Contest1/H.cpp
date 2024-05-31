# include <iostream>
# include <cmath>
# include <vector>

using namespace std;

string cSortPalindrome(vector<char>& a);

int main()
{
	int n;
	cin >> n;
	vector<char>a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cout << cSortPalindrome(a);

}

string cSortPalindrome(vector<char>& a)
{
	char mid = 0;
	string pre_pal = "";
	vector<int>c(26);
	for (int i = 0; i < size(a); ++i)
	{
		c[a[i] - 'A']++;
	}

	for (int i = 0; i < size(c); ++i)
	{
		if (c[i] % 2 != 0)
		{
			if (!mid)
				mid = i + 'A';
		}
		pre_pal += string(c[i] / 2, i + 'A');
	}

	string pal = pre_pal;
	if (mid != 0) pal += mid;
	for (int i = pre_pal.size() - 1; i >= 0; --i) {
		pal += pre_pal[i];
	}

	return pal;
}
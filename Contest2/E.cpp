# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <vector>


using namespace std;


int main()
{
	stack<int> dead;

	int n;
	cin >> n;


	vector<int> a(n);
	vector<pair<int, int>>res;

	int next = 0, expected = 1;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	while (next != n || (!dead.empty() && dead.top() == expected))
	{
		if (!dead.empty() && dead.top() == expected)
		{
			res.push_back({ 2, 1 });
			expected++;
			dead.pop();
		}
		else
		{
			res.push_back({ 1, 1 });
			dead.push(a[next]);
			next++;
		}
	}
	if (expected == n + 1)
	{
		cout << res.size() << "\n";
		for (auto x : res)
			cout << x.first << " " << x.second << "\n";

	}
	else
		cout << 0;
}
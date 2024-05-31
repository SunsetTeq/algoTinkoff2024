# include <iostream>
# include <stack>
# include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	stack<pair<int, int>>a;

	while (t--)
	{
		int x;
		cin >> x;
		if (x == 1 && a.empty())
		{
			cin >> x;
			pair<int, int>x2;
			x2.first = x;
			x2.second = x;
			a.push(x2);
		}
		else if (x == 1 && !a.empty())
		{
			cin >> x;
			pair<int, int>x2;
			x2.first = x;
			x2.second = min(x, a.top().second);
			a.push(x2);
		}
		else if (x == 2)
		{
			a.pop();
		}
		else
		{
			cout << a.top().second << "\n";
		}
	}
	return 0;
}
# include <iostream>
# include <deque>
# include <vector>
# include <algorithm>

using namespace std;

struct myDeq
{
	deque<pair<int, int>> q;
	int c_push = 0, c_back = 0;

	void push_back(int x)
	{
		while (!q.empty() && q.back().first >= x)
			q.pop_back();
		q.push_back({ x, c_push });
		++c_push;
	}

	void pop_front()
	{
		if (q.front().second == c_back)
			q.pop_front();
		++c_back;
	}

	int min()
	{
		if (q.empty())
			return 1e9;

		return q.front().first;
	}

};

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	myDeq q;
	for (int i = 0; i < k; ++i)
	{
		q.push_back(a[i]);
	}

	for (int i = k; i <= n; ++i)
	{
		cout << q.min() << " ";
		q.pop_front();
		if (i < n)
			q.push_back(a[i]);
	}

	return 0;
}
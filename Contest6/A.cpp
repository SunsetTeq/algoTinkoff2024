# include <iostream>
# include <vector>
# include<algorithm>
# include <stack>

using namespace std;

int n, m;
int used[100001];
vector<vector<int>> g;
stack<int>peak;
vector<vector<int>>peaks;

void dfs(int v);

int main()
{
	cin >> n >> m;
	g.resize(n);

	for (int i = 0, x, y; i < m; ++i)
	{
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	for (int i = 0; i < n; ++i)
	{
		if (used[i] == 0)
			dfs(i);
		vector<int>aaa;
		while (!peak.empty())
		{
			aaa.push_back(peak.top());
			peak.pop();
		}
		if (!aaa.empty()) peaks.push_back(aaa);
	}

	cout << peaks.size() << "\n";
	for (int i = 0; i < peaks.size(); ++i) {
		cout << peaks[i].size() << "\n";
		sort(peaks[i].begin(), peaks[i].end());
		for (int j = 0; j < peaks[i].size(); ++j)
		{
			cout << peaks[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}

void dfs(int v) {

	if (used[v])
	{
		return;
	}

	used[v] = 1;
	peak.push(v + 1);


	for (auto u : g[v])
		if (used[u] == 0)
			dfs(u);
}
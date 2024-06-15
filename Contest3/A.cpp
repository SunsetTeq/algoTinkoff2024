# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>

using namespace std;

int max_dep = 0, last_node = 0;
vector<vector<int>>tree;

void dfs(int node, int parent, int dep, vector<int>& depths)
{
	depths[node] = dep;
	if (dep > max_dep)
	{
		max_dep = dep;
		last_node = node;
	}

	for (int u : tree[node])
	{
		if (u != parent)
			dfs(u, node, dep + 1, depths);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	tree.resize(n);
	vector<int>depths1(n);
	vector<int>depths2(n);
	for (int i = 1; i < n; ++i)
	{
		int x;
		cin >> x;
		tree[x].push_back(i);
		tree[i].push_back(x);
	}

	dfs(0, -1, 0, depths1);
	cout << max_dep << " ";
	max_dep = 0;

	dfs(last_node, -1, 0, depths2);
	cout << max_dep << "\n";

	for (int i = 0; i < n; ++i)
	{
		cout << depths1[i] << " ";
	}

	return 0;
}
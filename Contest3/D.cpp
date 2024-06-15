#include <iostream>
#include <vector>

using namespace std;

struct Tree
{
	vector<long long>tree{ 0 };

	void sift_up(long long v)
	{
		while (v > 1 && tree[v] > tree[v / 2])
		{
			swap(tree[v], tree[v / 2]);
			v /= 2;
		}
	}

	void sift_down(long long v)
	{
		while (2 * v < tree.size())
		{
			long long lSon = 2 * v;
			long long rSon = 2 * v + 1;

			long long u = (rSon < tree.size() && tree[rSon] > tree[lSon] ? rSon : lSon);

			if (tree[v] >= tree[u])
				break;
			swap(tree[v], tree[u]);
			v = u;

		}
	}

	void cout_max()
	{
		cout << tree[1] << "\n";
		swap(tree[1], tree[tree.size() - 1]);
		tree.pop_back();
		sift_down(1);
	}

	void push(long long x)
	{
		tree.push_back(x);
		sift_up(tree.size() - 1);
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n; cin >> n;
	Tree tree;

	while (n--)
	{
		int x; cin >> x;
		if (x == 0)
		{
			long long y; cin >> y;
			tree.push(y);
		}
		else
		{
			tree.cout_max();
		}
	}
	return 0;
}
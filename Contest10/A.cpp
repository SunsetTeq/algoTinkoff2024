#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>arr;
vector<int> p;
vector<int> siz;
vector<int>mx;
vector<int>mn;

int get(int v) {
	return (p[v] == v) ? v : p[v] = get(p[v]);
}

void unite(int v, int u) {

	v = get(v); u = get(u);

	if (v == u) return;

	if (siz[v] > siz[u]) {
		swap(v, u);
	}
	mx[u] = max(mx[u], mx[v]);
	mn[u] = min(mn[u], mn[v]);
	siz[u] += siz[v];
	p[v] = u;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	arr.resize(n + 1, 0);
	p.resize(n + 1, 0);
	siz.resize(n + 1, 0);
	mx.resize(n + 1, 0);
	mn.resize(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		arr[i] = i;
		siz[i] = 1;
		p[i] = i;
		mx[i] = i;
		mn[i] = i;
	}

	//for (auto& x : arr) {
	//	cout << x << " ";
	//}

	while (m--) {
		string command; cin >> command;
		if (command == "union") {
			int v, u; cin >> v >> u;
			unite(v, u);
		}
		else {
			int x; cin >> x;
			int vertex = get(x);
			cout << mn[vertex] << " " << mx[vertex] << " " << siz[vertex] << "\n";
		}
	}
	return 0;
}
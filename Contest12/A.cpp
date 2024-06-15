#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int lca(long long a, long long b) {
	return (a * b) / gcd(a, b);
}

int main() {
	long long n, k; cin >> n >> k;
	cout << lca(n, k);
}
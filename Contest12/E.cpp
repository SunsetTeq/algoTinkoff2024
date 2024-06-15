#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const unsigned long long P = 1e9 + 7;

unsigned long long fact(unsigned long long n) {
	unsigned long long res = 1;
	for (unsigned long long i = 2; i <= n; ++i) {
		res = (res * i) % P;
	}
	return res;
}

unsigned long long modExp(unsigned long long base, unsigned long long exp) {
	unsigned long long result = 1;
	while (exp > 0) {
		if (exp % 2 == 1)   
			result = (result * base) % P;
		base = (base * base) % P; 
		exp >>= 1;  
	}
	return result;
}

unsigned long long binom(int n, int k) {
	unsigned long long fN = fact(n);
	unsigned long long fK = fact(k);
	unsigned long long fNmK = fact(n - k);

	unsigned long long rFK = modExp(fK, P - 2);
	unsigned long long rFNmK = modExp(fNmK, P - 2);

	return fN * (rFK * rFNmK % P) % P;
}

int main() {
	unsigned long long n, k; cin >> n >> k;
	cout << binom(n, k);
	return 0;
}

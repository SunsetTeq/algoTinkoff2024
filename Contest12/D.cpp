#include <iostream>
#include <vector>

using namespace std;

int check(int n) {
	int cnt2 = 0;
	int lastDigit = 1;
	for (int i = 2; i <= n; ++i) {
		int num = i;
		while (num % 2 == 0) {
			num /= 2;
			cnt2++;
		}
		while (num % 5 == 0) {
			num /= 5;
			cnt2--;
		}
		lastDigit = (lastDigit * num) % 10;
	}

	for (int i = 0; i < cnt2; ++i) {
		lastDigit = (lastDigit * 2) % 10;
	}

	return lastDigit;
}

int main() {
	int n; cin >> n;
	cout << check(n);
	return 0;
}
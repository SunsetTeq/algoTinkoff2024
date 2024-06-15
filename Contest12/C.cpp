#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    return is_prime;
}

int main() {
    int n; cin >> n;

    vector<bool> is_prime = sieve(n);
    unordered_set<int> primes;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.insert(i);
        }
    }

    int p_min = n, q_min = n;

    for (int p : primes) {
        int q = n - p;
        if (q >= p && primes.count(q)) {
            if (p < p_min || (p == p_min && q < q_min)) {
                p_min = p; q_min = q;
            }
        }
    }

    cout << p_min << " " << q_min;

    return 0;
}
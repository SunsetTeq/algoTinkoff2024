#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long D = 379, mod = 1e9 + 7;

long long hash_substring(long long l, long long r, const vector<long long>& hash, const vector<long long>& d)
{
    long long result = hash[r] - (hash[l] * d[r - l] % mod);
    if (result < 0) result += mod;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long answer = 0;

    string s, p;
    cin >> p; s = p;    // s — исходная, p — реверсированная
    reverse(p.begin(), p.end());

    long long n = s.size();
    vector<long long> hash_p(n + 1, 0), hash_s(n + 1, 0), d(n + 1, 1);

    for (int i = 0; i < n; i++) {
        hash_p[i + 1] = (hash_p[i] * D + p[i]) % mod;
        hash_s[i + 1] = (hash_s[i] * D + s[i]) % mod;
        d[i + 1] = (d[i] * D) % mod;
    }

    for (long long i = 0, j = n - 1; i < n; ++i, --j)
    {
        long long l = 0, r = min(n - i, n - j);
        while (l < r)
        {
            long long mid = l + (r - l + 1) / 2;
            if (hash_substring(i, i + mid, hash_s, d) == hash_substring(j, j + mid, hash_p, d))
                l = mid;
            else
                r = mid - 1;
        }
        answer += l;
        l = 0, r = min(n - i - 1, n - j);
        while (l < r)
        {
            long long mid = l + (r - l + 1) / 2;
            if (hash_substring(i + 1, i + 1 + mid, hash_s, d) == hash_substring(j, j + mid, hash_p, d))
                l = mid;
            else
                r = mid - 1;
        }
        answer += l;
    }
    cout << answer;

    return 0;
}
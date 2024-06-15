#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long D = 379, mod = 1e9 + 7;

long long hash_substring(long long l, long long r, const vector<long long>& hash, const vector<long long>& d)
{
    long long result = hash[r + 1] - (hash[l] * d[r - l + 1] % mod);
    if (result < 0) result += mod;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    long long n = s.size();
    s += s;

    vector<long long> hash(2 * n + 1, 0), d(2 * n + 1, 1);

    for (long long i = 0; i < 2 * n; ++i) {
        hash[i + 1] = (hash[i] * D + (s[i] - 'a' + 1)) % mod;
        if (i > 0) d[i] = (d[i - 1] * D) % mod;
    }

    int p = 0; 

    for (int i = 1; i < n; ++i)
    {
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (hash_substring(p, p + mid, hash, d) == hash_substring(i, i + mid, hash, d))
            {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        if (l < n && s[p + l] > s[i + l]) p = i;
    }

    cout << s.substr(p, n);

    return 0;
}

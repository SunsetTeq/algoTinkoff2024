#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long D = 379, mod = 1e9 + 7;

long long cnt = 0;

long long hash_substring(const vector<long long>& hash, const vector<long long>& d, const long long& n, const long long& n2, const vector<long long>& hab)
{
    for (long long i = 0; i <= n - n2; ++i)
    {
        long long current_hash = (hash[i + n2] + mod - (hash[i] * d[n2] % mod)) % mod;

        long long l = 0, r = hab.size();
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (current_hash == hab[mid])
            {
                cnt++;
                break;
            }
            else if (current_hash > hab[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;

    long long n = s.size();
    vector<long long> hash(n + 1, 0), d(n + 1, 0);
    d[0] = 1;

    for (long long i = 0; i < n; ++i)
    {
        hash[i + 1] = (hash[i] * D + (s[i] - 'a' + 1)) % mod;
        d[i + 1] = (d[i] * D) % mod;
    }


    string b; cin >> b;
    long long n2 = b.size();
    b += b;

    vector<long long> hash_b(n2 * 2 + 1, 0);
    for (long long i = 0; i < b.size(); ++i)
        hash_b[i + 1] = (hash_b[i] * D + (b[i] - 'a' + 1)) % mod;

    vector<long long>hab;
    for (long long i = 0; i <= b.size() - n2; ++i)
        hab.push_back((hash_b[i + n2] + mod - (hash_b[i] * d[n2] % mod)) % mod);

    sort(hab.begin(), hab.end());

    cout << hash_substring(hash, d, n, n2, hab);

    return 0;
}
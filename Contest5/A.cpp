#include <iostream>
#include <vector>

using namespace std;

const long long D = 379, mod = 1e9 + 7;

long long hash_substring(long long l, long long r, const vector<long long>& hash, const vector<long long>& d)
{
    long long result = hash[r] - (hash[l - 1] * d[r - l + 1] % mod);
    if (result < 0) result += mod;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s; long long m;
    cin >> s; cin >> m;

    long long n = s.size();
    vector<long long> hash(n + 1, 0), d(n + 1, 0);
    d[0] = 1;

    for (long long i = 0; i < n; ++i)
    {
        hash[i + 1] = (hash[i] * D + (s[i] - 'a' + 1)) % mod;
        d[i + 1] = (d[i] * D) % mod;
    }


    for (long long i = 0; i < m; ++i)
    {
        long long l1, l2, r1, r2;
        cin >> l1 >> l2 >> r1 >> r2;
        if (hash_substring(l1, l2, hash, d) == hash_substring(r1, r2, hash, d))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
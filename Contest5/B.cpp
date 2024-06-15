#include <iostream>
#include <vector>

using namespace std;

const long long D = 379, mod = 1e9 + 7;

struct res
{
    long long cnt = 0;
    vector<long long>index;
};

res hash_substring(const vector<long long>& hash, const vector<long long>& d, const long long& n, const long long& n2, const long long& b_hash)
{
    res result;
    for (long long i = 0; i <= n - n2; ++i)
    {
        long long current_hash = (hash[i + n2] + mod - (hash[i] * d[n2] % mod)) % mod;
        if (current_hash == b_hash)
        {
            result.cnt++;
            result.index.push_back(i);
        }
    }
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
        string b; cin >> b;
        long long n2 = b.size();
        long long b_hash = 0;

        for (char c : b) {
            long long x = (long long)(c - 'a' + 1);
            b_hash = (b_hash * D + x) % mod;
        }

        res res = hash_substring(hash, d, n, n2, b_hash);
        cout << res.cnt << " ";
        for (long long x : res.index)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
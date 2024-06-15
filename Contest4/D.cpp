#include <iostream>
#include <algorithm>

using namespace std;

long long check(long long x, long long n)
{
    long long res = 0;
    x--;
    for (int i = 1; i <= n; ++i)
        res += min(n, x / i);
    return res;
}

int main()
{
    long long n, k; cin >> n >> k;
    long long l = 1, r = n * n + 1;

    while (l < r)
    {
        long long x = (l + r) >> 1;

        if (check(x, n) < k)
            l = x + 1;

        else r = x;
    }

    cout << l - 1;

    return 0;
}

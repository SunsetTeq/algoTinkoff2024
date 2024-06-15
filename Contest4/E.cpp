#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    vector<long long>nums(n); long long l = 0, r = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        r += nums[i];
        l = max(l, nums[i]);
    }

    while (l < r)
    {
        long long mid = (r + l) / 2;

        int count = 1; long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (sum > mid)
            {
                count++;
                sum = nums[i];
            }
        }

        if (count > k)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l;

    return 0;
}
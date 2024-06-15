#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
# include <random>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(1, 1e9);

long long n, m;
long long idMin = 0, idMax = 0;

long long check(const vector<long long>& prefMin, const vector<long long>& prefMax, long long mid) {
    while (mid >= 0) {
        unordered_map<long long, long long> freq;


        for (long long i = 0; i <= idMax - mid; ++i) {
            long long hash_value = prefMax[i + mid] - prefMax[i];
            ++freq[hash_value];
        }


        for (long long i = 0; i <= idMin - mid; ++i) {
            long long hash_value = prefMin[i + mid] - prefMin[i];
            if (freq.find(hash_value) != freq.end()) {
                return mid;
            }
        }

        mid--;
    }
    return 0;
}

int main()
{
    vector<long long> nums(1000000);
    for (long long i = 0; i < 1000000; ++i)
        nums[i] = distrib(gen);

    cin >> n;

    vector<long long> a(n);
    vector<long long>prefA(n + 1, 0);
    for (long long i = 0; i < n; ++i) {
        long long x;  cin >> x;
        a[i] = nums[x];
        prefA[i + 1] = prefA[i] + a[i];
    }

    cin >> m;

    vector<long long> b(m);
    vector<long long>prefB(m + 1, 0);

    for (long long i = 0; i < m; ++i) {
        long long x;  cin >> x;
        b[i] = nums[x];
        prefB[i + 1] = prefB[i] + b[i];
    }


    vector<long long>prefMin;
    vector<long long>prefMax;
    if (n >= m)
    {
        idMax = n; idMin = m;
        prefMax = prefA; prefMin = prefB;
        prefA.resize(0); prefB.resize(0);
    }
    else
    {
        idMax = m; idMin = n;
        prefMax = prefB; prefMin = prefA;
        prefA.resize(0); prefB.resize(0);
    }



    long long result = check(prefMin, prefMax, idMin);
    cout << result;
    return 0;
}

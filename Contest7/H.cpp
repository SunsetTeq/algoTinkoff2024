#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n;

vector<long long> search(vector<long long> a) {
    vector<long long> d(n, 1), prev(n, -1);

    for (long long i = 1; i < n; ++i) {
        for (long long j = 0; j < i; ++j) {
            if (a[j] < a[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }

    long long pos = 0;
    long long length = d[0];

    for (long long i = 1; i < n; ++i) {
        if (d[i] > length) {
            pos = i;
            length = d[i];
        }
    }

    vector<long long> answer;
    while (pos != -1) {
        answer.push_back(a[pos]);
        pos = prev[pos];
    }

    reverse(answer.begin(), answer.end());
    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<long long> a(n);

    for (auto& x : a) {
        cin >> x;
    }

    vector<long long> answer = search(a);

    cout << answer.size() << "\n";
    for (auto x : answer) {
        cout << x << " ";
    }

    return 0;
}
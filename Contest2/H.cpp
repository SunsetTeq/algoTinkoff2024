#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void search_rMin(vector<long long>& a, vector<pair<long long, long long>>& pMin, long long n);
void search_lMin(vector<long long>& a, vector<pair<long long, long long>>& pMin, long long n);

int main() {
    long long n; cin >> n;

    vector<long long> pSum(n + 1, 0);
    long long sum = 0;
    vector<pair<long long, long long>> pMin(n + 1);
    vector<long long> a(n + 1, 0);

    for (long long i = 1; i < n + 1; ++i) {
        cin >> a[i];
        sum += a[i];
        pSum[i] = sum;
    }

    search_rMin(a, pMin, n);
    search_lMin(a, pMin, n);

    long long res = 0;

    for (long long i = 1; i <= n; ++i) {
        long long left, right;

        if (pMin[i].first == -1) {
            right = n;
        }
        else {
            right = pMin[i].first - 1;
        }

        if (pMin[i].second == -1) {
            left = 1;
        }
        else {
            left = pMin[i].second + 1;
        }

        long long current = (long long)(pSum[right] - pSum[left - 1]) * a[i];
        if (current > res) {
            res = current;
        }
    }

    cout << res;

    return 0;
}

void search_rMin(vector<long long>& a, vector<pair<long long, long long>>& pMin, long long n) {
    stack<long long> st;

    for (long long i = n; i >= 1; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }

        if (!st.empty())
            pMin[i].first = st.top();
        else
            pMin[i].first = -1;

        st.push(i);
    }
}

void search_lMin(vector<long long>& a, vector<pair<long long, long long>>& pMin, long long n) {
    stack<long long> st;

    for (long long i = 1; i <= n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }

        if (!st.empty())
            pMin[i].second = st.top();
        else
            pMin[i].second = -1;

        st.push(i);
    }
}
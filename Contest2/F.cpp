#include <iostream>
#include <vector>

using namespace std;

long long st[1000001];
long long id[1000001];

long long head = 0;
long long tail = 0;

void push(long long x)
{
    id[x] = head;
    st[head++] = x;
}

long long pop_back()
{
    return st[tail++];
}

long long pop_top()
{
    return st[--head];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    for (long long i = 0; i < n; ++i) {

        long long j; cin >> j;

        if (j == 1) {
            long long x; cin >> x;
            push(x);
        }
        else if (j == 2) {
            pop_back();
        }
        else if (j == 3) {
            pop_top();
        }
        else if (j == 4) {
            long long q; cin >> q;
            cout << id[q] - tail << "\n";
        }
        else {
            cout << st[tail] << "\n";
        }
    }
    return 0;
}
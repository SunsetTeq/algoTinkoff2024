#include <iostream>
#include <set>
#include<vector>
#include<algorithm>

using namespace std;

void check(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    check(n);

    return 0;
}


void check(int n) {
    vector<int> arr(n + 2);
    vector<int> damage(n + 2, 1e9 + 5);

    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    for (int i = 1; i <= n; ++i)
        cin >> damage[i];

    set<int> alive;
    set<int>current;
    for (int i = 0; i < n + 2; ++i) {
        alive.insert(i);
        current.insert(i);
    }
    for (int z = 0; z < n; ++z) {
        set<int> dead;
        set<int> surv;
        for (auto i : current) {
            if (i == 0 || i == n + 1)
                continue;

            auto it = alive.find(i);
            if (it == alive.end())
                continue;

            auto left = *prev(it);
            auto right = *next(it);
            if (arr[left] + arr[right] > damage[i]) {
                dead.insert(i);
                surv.insert(left);
                surv.insert(right);
            }
        }
        cout << dead.size() << " ";
        for (auto it : dead)
            alive.erase(it);
        current = surv;
    }
}
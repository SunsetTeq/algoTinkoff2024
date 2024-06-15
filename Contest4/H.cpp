#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    long long start;
    long long end;
    long long reward;
    int index;
};

int binCheck(const vector<Task>& tasks, int i) {
    int lo = 0, hi = i - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (tasks[mid].end <= tasks[i].start) {
            if (tasks[mid + 1].end <= tasks[i].start) {
                lo = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long c;
    cin >> n >> c;
    vector<Task> tasks(n);

    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].start >> tasks[i].end;
        tasks[i].end += tasks[i].start;
        tasks[i].index = i + 1;
        tasks[i].reward = c;
    }

    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) -> bool {
        return a.end < b.end;
        });

    vector<long long> dp(n);
    dp[0] = c;

    for (int i = 1; i < n; ++i) {
        long long profit_including_current = tasks[i].reward;
        int lastNonConflict = binCheck(tasks, i);
        if (lastNonConflict != -1) {
            profit_including_current += dp[lastNonConflict];
        }

        dp[i] = max(dp[i - 1], profit_including_current);
    }

    cout << dp[n - 1] << endl;

    int idx = n - 1;
    vector<int> selected_tasks;
    while (idx >= 0) {
        if (idx == 0 || dp[idx] != dp[idx - 1]) {
            selected_tasks.push_back(tasks[idx].index);
            idx = binCheck(tasks, idx);
        }
        else {
            idx--;
        }
    }

    reverse(selected_tasks.begin(), selected_tasks.end());
    cout << selected_tasks.size() << "\n";
    for (int task_index : selected_tasks) {
        cout << task_index << " ";
    }

    return 0;
}
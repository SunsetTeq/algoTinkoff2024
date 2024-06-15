#include <iostream>
#include <vector>
#include <climits> 
#include <algorithm>

using namespace std;

struct event
{
    long long x, type;
};

long long scanline(vector<pair<long long, long long>> segments) {
    vector<event> events;

    for (int i = 0; i < segments.size(); ++i)
    {
        long long l = segments[i].first, r = segments[i].second;
        events.push_back({ l, 1 });
        events.push_back({ r, -1 });
    }

    sort(events.begin(), events.end(), [](event a, event b)
        {
            if (a.x != b.x)
                return a.x < b.x;
            return a.type > b.type;
        });

    long long cnt = 0, res = 0, prev = LLONG_MIN;

    for (event e : events) {
        if (prev != LLONG_MIN && cnt > 0)
            res += e.x - prev;
        cnt += e.type;
        prev = e.x;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector < pair < long long, long long >> segments(n);

    for (int i = 0; i < n; ++i)
    {
        long long l, r; cin >> l >> r;
        segments[i] = { l, r };
    }

    cout << scanline(segments);

    return 0;
}
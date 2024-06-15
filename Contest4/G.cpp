#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct event
{
    long long x; int type;
};

long long scanline(vector<event>& events, int n)
{
    sort(events.begin(), events.end(), [](const event& a, const event& b)
        {
            if (a.x != b.x) return a.x < b.x;
            return a.type > b.type;
        });

    long long cnt = 0, time = 0, prev = 0;

    for (auto& e : events)
    {
        if (cnt == n)
        {
            time += e.x - prev;
        }
        cnt += e.type;
        prev = e.x;
    }

    return time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<event> events;

    for (int i = 0; i < n; ++i)
    {
        long long x1, x2, x3, y1, y2, y3;
        cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
        long long l = x1 * 3600 + x2 * 60 + x3;
        long long r = y1 * 3600 + y2 * 60 + y3;

        if (r <= l)
        {
            events.push_back({ l, 1 });
            events.push_back({ 86400, -1 });
            events.push_back({ 0, 1 });
            events.push_back({ r, -1 });
        }
        else
        {
            events.push_back({ l, 1 });
            events.push_back({ r, -1 });
        }
    }

    cout << scanline(events, n);

    return 0;
}
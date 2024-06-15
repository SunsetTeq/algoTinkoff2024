#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
# include <algorithm>

using namespace std;
long long min_max_el = INT_MAX;
long long result = 0;

void Dijkstra(int n, int st, const vector<vector<pair<int, int>>>& graph)
{
    vector<int> D(n, INT_MAX);
    D[st] = 0;

    set<pair<int, int>> s;
    s.insert({ 0, st });

    while (!s.empty())
    {
        int curr = s.begin()->second;
        int curr_dist = s.begin()->first;
        s.erase(s.begin());

        if (curr_dist > D[curr])
            continue;

        for (auto edge : graph[curr])
        {
            int next = edge.first;
            int weight = edge.second;
            if (D[curr] + weight < D[next])
            {
                D[next] = D[curr] + weight;
                s.insert({ D[next], next });
            }
        }
    }

    //for (int i = 0; i < n; i++)
    //{
    //    if (D[i] != INT_MAX)
    //    {
    //        cout << st + 1 << " -> " << i + 1 << " = " << D[i] << endl;
    //    }
    //    else
    //        cout << st + 1 << " -> " << i + 1 << " = " << "EMPTY" << endl;
    //}

    int max_el = *max_element(D.begin(), D.end());
    if (max_el < min_max_el || ((max_el == min_max_el) && (st < result)))
    {
        min_max_el = max_el;
        result = st;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int from, to, len;
        cin >> from >> to >> len;
        from--; to--;
        graph[from].push_back({ to, len });
        graph[to].push_back({ from, len });
    }

    for (int i = 0; i < n; i++) {
        Dijkstra(n, i, graph);
    }

    cout << result + 1;

    return 0;
}


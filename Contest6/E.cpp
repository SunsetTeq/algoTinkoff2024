# include <iostream>
# include <vector>
# include <queue>
# include <set>


using namespace std;

const int Maxx = 1000005;
int k;
vector<pair<int, int> > graph[Maxx];

void Dijkstra(int source)
{
    vector<int> dist(k + 2, 1e9);
    dist[source] = 0;

    set<pair<int, int>> s;
    s.insert({ 0, source });

    while (!s.empty())
    {
        int curr = s.begin()->second;
        int curr_dist = s.begin()->first;
        s.erase(s.begin());

        if (curr_dist > dist[curr])
            continue;

        for (auto edge : graph[curr])
        {
            int next = edge.first;
            int weight = edge.second;
            if (dist[curr] + weight < dist[next])
            {
                s.erase({ dist[next], next });
                dist[next] = dist[curr] + weight;
                s.insert({ dist[next], next });
            }
        }
    }

    cout << dist[0] + 1;
}

void minSumDigits(int k)
{
    for (int i = 1; i <= k; ++i) {
        int from = (i) % k;
        int to = (i + 1) % k;
        int weight = 1;
        graph[from].push_back(make_pair(to, weight));
    }

    for (int i = 1; i <= k; ++i) {
        int from = (i) % k;
        int to = (10 * i) % k;
        int weight = 0;
        graph[from].push_back(make_pair(to, weight));
    }

    Dijkstra(1);
    return;
}

int main()
{
    cin >> k;
    minSumDigits(k);

    return 0;
}

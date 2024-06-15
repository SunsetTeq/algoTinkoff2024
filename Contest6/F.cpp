#include <iostream>
#include <map>
#include <vector>
#include <string>
# include <queue>

using namespace std;

class Graph {
private:
    map<string, vector<string>> graph;

public:
    void addVertex(const string& vertex) {
        if (graph.find(vertex) == graph.end())
        {
            graph[vertex] = vector<string>();
        }
    }

    vector<string> emptyVector;
    vector<string>& vertChild(const string& v)
    {
        auto it = graph.find(v);
        if (it != graph.end())
        {
            return it->second;
        }
        else
        {
            return emptyVector;
        }
    }

    void addEdge(const string& from, const string& to)
    {
        addVertex(from);
        addVertex(to);
        graph[from].push_back(to);
    }
};

int bfs(Graph& g, const string& from, const string& to)
{
    map<string, bool> used;
    map<string, int> dist;
    queue<string> q;

    q.push(from);
    used[from] = true;
    dist[from] = 0;

    while (!q.empty())
    {
        string v = q.front();
        q.pop();

        vector<string>& children = g.vertChild(v);
        for (const string& u : children)
        {
            if (!used[u])
            {
                q.push(u);
                used[u] = true;
                dist[u] = dist[v] + 1;
            }
        }
    }

    if (used.find(to) == used.end()) return -1;
    return dist[to];
}

int main() {
    Graph g;

    int m; cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string v1, c, v2;
        cin >> v1 >> c >> v2;
        g.addEdge(v1, v2);

    }

    string from, to;
    cin >> from >> to;

    cout << bfs(g, from, to);


    return 0;
}
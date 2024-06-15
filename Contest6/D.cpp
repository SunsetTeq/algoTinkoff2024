#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

struct Position {
    int x, y, dist;
};

bool isValid(int x, int y, int N) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

void printPath(const vector<vector<Position>>& parent, Position end) {
    if (end.x == -1 || end.y == -1) {
        return;
    }
    printPath(parent, parent[end.x][end.y]);
    cout << end.x + 1 << " " << end.y + 1 << '\n';
}

int bfs(int n, pair<int, int> start, pair<int, int> end) {
    vector<vector<bool>> used(n, vector<bool>(n, false));
    vector<vector<Position>> parent(n, vector<Position>(n, { -1, -1, -1 }));
    queue<Position> q;
    Position start_pos = { start.first, start.second, 0 };

    q.push(start_pos);
    used[start_pos.x][start_pos.y] = true;
    parent[start_pos.x][start_pos.y] = { -1, -1, 0 };

    while (!q.empty()) {
        Position cur = q.front();
        q.pop();

        if (cur.x == end.first && cur.y == end.second) {
            cout << cur.dist << "\n";
            printPath(parent, cur);
            return cur.dist;
        }

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (isValid(nx, ny, n) && !used[nx][ny]) {
                used[nx][ny] = true;
                parent[nx][ny] = cur;
                q.push({ nx, ny, cur.dist + 1 });
            }
        }
    }
    return -1;
}

int main() {
    int N, x1, y1, x2, y2;
    cin >> N >> x1 >> y1 >> x2 >> y2;

    bfs(N, { x1 - 1, y1 - 1 }, { x2 - 1, y2 - 1 });

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;

int n, m;

int get(int v) {
    return (p[v] < 0) ? v : (p[v] = get(p[v]));
}

bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (p[a] < p[b])
        swap(a, b);
    p[a] += p[b];
    p[b] = a;
    return true;
}

int convLine(int i, int j) {  
    return i * (m + 1) + j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    p.resize(1 + convLine(n + 1, m + 1), -1);

    vector<int>resI;
    vector<int>resJ;
    vector<int>resD;
    int cntRes = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            int op; cin >> op;
            if (op == 1) {
                unite(convLine(i, j), convLine(i + 1, j));
            }
            if (op == 2) {
                unite(convLine(i, j), convLine(i, j + 1));
            }
            if (op == 3) {
                unite(convLine(i, j), convLine(i + 1, j));
                unite(convLine(i, j), convLine(i, j + 1));
            }
        }
    }


    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; ++j) {
            if (unite(convLine(i, j), convLine(i + 1, j))) {
                resI.push_back(i);
                resJ.push_back(j);
                resD.push_back(1);
                cntRes += 1;
            }

        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; ++j) {
            if (unite(convLine(i, j), convLine(i, j + 1))) {
                resI.push_back(i);
                resJ.push_back(j);
                resD.push_back(2);
                cntRes += 2;
            }
        }
    }

    cout << resI.size() << " " << cntRes << "\n";
    for (int i = 0; i < resJ.size(); ++i) {
        cout << resI[i] << " " << resJ[i] << " " << resD[i] << "\n";
    }


    return 0;
}
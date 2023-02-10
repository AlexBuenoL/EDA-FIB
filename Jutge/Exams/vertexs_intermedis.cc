#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graf;

int num_vertex(const Graf& G, int u, int v, vector<bool>& vis) {
    int tot = 0;
    vis[u] = true;
    if (u == v) ++tot;
    else {
        for (int w : G[u]) 
            if (not vis[w]) tot += num_vertex(G, w, v, vis);
    }
    return tot;
}

int main() {
    int n, u, v, m;
    while (cin >> n >> u >> v >> m) {
        Graf G(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
        }
        vector<bool> vis(n, false);
        cout << num_vertex(G, u, v, vis) << endl;
    }
}

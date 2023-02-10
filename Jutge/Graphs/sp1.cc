#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> ArcP; // pes, vertex
typedef vector<vector<ArcP>> GrafP;
const int infinit = INT_MAX;

int dijkstra(const GrafP& G, int x, int y, int n) {
    
    vector<bool> vis(n, false);
    vector<int> dist(n, infinit);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> PQ;
    
    dist[x] = 0;
    PQ.push({0,x});
    
    while (not PQ.empty()) {
        int v = PQ.top().second;
        if (v == y) return PQ.top().first;
        PQ.pop();
        if (not vis[v]) {
            vis[v] = true;
            for (ArcP a : G[v]) {
                int w = a.second;
                int c = a.first;
                if (dist[w] > dist[v] + c) {
                    dist[w] = dist[v] + c;
                    PQ.push({dist[w],w});
                }
            }
        }
    }
    return infinit;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        GrafP G(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back({c,v});
        }
        
        int x, y; // minim cost per anar del vertex x al y
        cin >> x >> y;
        
        int res = dijkstra(G, x, y, n);
        
        if (res != infinit) cout << res << endl;
        else cout << "no path from " << x << " to " << y << endl;
    }
}

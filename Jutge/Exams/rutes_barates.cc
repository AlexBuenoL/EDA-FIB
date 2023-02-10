#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> CostVert;
typedef vector<vector<CostVert>> Graf;
const int inf = INT_MAX;

int cost_minim(const Graf& G, const vector<int>& costos, int n, int a, int b) {
    if (a == b) return 0;
    
    vector<int> dist(n, inf);
    vector<bool> vis(n, false);
    priority_queue<CostVert, vector<CostVert>, greater<CostVert>> PQ;
    
    dist[a] = 0;
    PQ.push({0,a});
    
    while (not PQ.empty()) {
        int u = PQ.top().second;
        PQ.pop();
        if (not vis[u]) {
            vis[u] = true;
            if (u == b) return dist[u];
            for (CostVert a : G[u]) {
                int v = a.second;
                int c = a.first;
                int dv = dist[u] + c;
                
                if (v != b) dv += costos[v];
                if (dv < dist[v]) {
                    dist[v] = dv;
                    PQ.push({dv,v});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    Graf G(n);
    vector<int> costos(n);
    for (int i = 0; i < n; ++i) cin >> costos[i];
    
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        G[x].push_back({c,y});
        G[y].push_back({c,x});
    }
    
    int a, b;
    while (cin >> a >> b) {
        cout << "c(" << a << ',' << b << ") = ";
        int res = cost_minim(G, costos, n, a, b);
        if (res != -1) cout << res << endl;
        else cout << "+oo" << endl;
    }
}
    

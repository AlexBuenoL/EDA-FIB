#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ArcP;
typedef vector<vector<ArcP>> GrafP;

int retallades(const GrafP& G, int n) {
    vector<bool> vis(n, false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> PQ;
    
    int cont = 1;
    int sum = 0;
    
    for (ArcP a : G[0]) PQ.push(a);
    vis[0] = true;
    
    while (cont != n) {
        
        int cost = PQ.top().first;
        int v = PQ.top().second;
        PQ.pop();
        
        if (not vis[v]) {
            vis[v] = true;
            
            for (ArcP uv : G[v]) PQ.push(uv);
        
            ++cont;
            sum += cost;
        }
    }
    
    return sum;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        GrafP G(n);
        int tot = 0;
        for (int i = 0; i < m; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            G[x].push_back({c,y});
            G[y].push_back({c,x});
            tot += c;
        }
        
        cout << tot - retallades(G, n) << endl;
    }
}

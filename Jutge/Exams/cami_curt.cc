#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graf;

string cami_curt(const Graf& G, int n) {
    vector<int> dist(n, -1);
    queue<int> Q;
    Q.push(0);
    vector<bool> vis(n, false);
    string sol = "0";
    
    while (not Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = true;
        
        if (u == n-1) {
            char c = u; 
            sol.push_back(c); 
            return sol;
        }
        
        for (int v : G[u]) {
            if (not vis[v]) {
                Q.push(v);
                sol.push_back(char(v));
            }
        }
    }
    return sol;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Graf G(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
        }
        cout << cami_curt(G, n) << endl;
    }
}

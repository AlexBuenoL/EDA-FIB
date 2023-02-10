#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

typedef vector< vector<int> > Graph;

list<int> top_sort(Graph& G, priority_queue<int, vector<int>, greater<int>>& pq, vector<int>& grades) {
    
    list<int> res;
    while (not pq.empty()) {
        int u = pq.top();
        pq.pop();
        res.push_back(u);
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            --grades[v];
            if (grades[v] == 0) pq.push(v);
        }
    }
    return res;
}

int main() {
    
    int n, m;
    while (cin >> n >> m) {
        
        Graph G(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> grades(n, 0);
        
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            G[x].push_back(y);
            ++grades[y];
        }
        
        for (int i = 0; i < n; ++i) 
            if (grades[i] == 0) pq.push(i);
        
        list<int> res = top_sort(G, pq, grades);
        auto it = res.begin();
        cout << *it; ++it;
        for (it; it != res.end(); ++it) cout << ' ' << *it;
        cout << endl;
    }
}

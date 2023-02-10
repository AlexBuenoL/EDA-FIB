#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef char vertex;
typedef vector< vector<vertex> > Graf;

void readGraf(Graf& G, int n, int m) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> G[i][j];
    }
}

bool dfs_tresor(Graf& G, vector< vector<bool> >& vis, int n, int m,
                stack< pair<int,int> >& p) {
    
    while (not p.empty()) {
        
        int f = p.top().first;
        int c = p.top().second;
        if (G[f][c] == 't') return true;
        vis[f][c] = true;
        
        for (int i = 0; i < 4; ++i) { // 0->der, 1->izq, 2->arr, 3->abj

            if (i == 0 and c+1 < m and not vis[f][c+1]) {
                if (G[f][c+1] != 'X') {
                    p.push(make_pair(f,c+1));
                    return dfs_tresor(G, vis, n, m, p);
                }
                else vis[f][c+1] = true;
            }
            else if (i == 1 and c-1 >= 0 and not vis[f][c-1]) {
                if (G[f][c-1] != 'X') {
                    p.push(make_pair(f,c-1));
                    return dfs_tresor(G, vis, n, m, p);
                }
                else vis[f][c-1] = true;
            }
            else if (i == 2 and f-1 >= 0 and not vis[f-1][c]) {
                if (G[f-1][c] != 'X') {
                    p.push(make_pair(f-1,c));
                    return dfs_tresor(G, vis, n, m, p);
                }
                else vis[f-1][c] = true;
            }
            else if (i == 3 and f+1 < n and not vis[f+1][c]) {
                if (G[f+1][c] != 'X') {
                    p.push(make_pair(f+1,c));
                    return dfs_tresor(G, vis, n, m, p);
                }
                else vis[f+1][c] = true;
            }
        }
        p.pop();
        
    }
    return false;
}

int main() {

    int n, m;
    cin >> n >> m;

    Graf G(n, vector<vertex>(m));
    readGraf(G, n, m);

    int f, c;
    cin >> f >> c;
    --f; --c;
    vector< vector<bool> > vis(n, vector<bool>(m, false));
    stack< pair<int,int> > p;
    p.push(make_pair(f,c));

    if (dfs_tresor(G, vis, n, m, p)) cout << "yes\n";
    else cout << "no\n";
}

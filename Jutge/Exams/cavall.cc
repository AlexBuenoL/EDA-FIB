#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> Pos;

const int X[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int infinit = INT_MAX;

bool pos_ok(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int bfs_posicio(int n, int m, int w, int l, Pos& ini, Pos& fin) {
    
    if (ini == fin) return w;
    
    vector<vector<int>> dist(n, vector<int>(m, infinit));
    dist[ini.first][ini.second] = 0;
    
    queue<Pos> Q;
    Q.push(ini);
    
    while (not Q.empty()) {
        Pos act = Q.front();
        if (act == fin) return w - dist[act.first][act.second]*l;
        Q.pop();
        for (int i = 0; i < 8; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            if (pos_ok(x,y,n,m) and dist[x][y] == infinit) {
                dist[x][y] = dist[act.first][act.second] + 1;
                Q.push({x,y});
            }
        }
    }
    return -1;
}

int main() {
    int n, m, w, l;
    while (cin >> n >> m >> w >> l) {
        int k;
        cin >> k;
        vector<Pos> objectius(k);
        for (int i = 0; i < k; ++i) 
            cin >> objectius[i].first >> objectius[i].second;
        
        Pos pos_ini = {0,0};
        int punts_tot = 0;
        for (int i = 0; i < k; ++i) {
            int puntos = bfs_posicio(n, m, w, l, pos_ini, objectius[i]);
            if (puntos != -1) punts_tot += puntos;
            else {punts_tot = 0; break;}
            
            pos_ini = objectius[i];
        }
        
        cout << punts_tot << endl;
    }
}
        
        
        
        

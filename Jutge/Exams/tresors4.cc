#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef pair<int,int> Pos;

const int X[4] = {1,0,-1,0};
const int Y[4] = {0,1,0,-1};

bool pos_ok(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int distancia_tresor(Tauler& T, Pos& ini, int n, int m) { 
    
    queue<Pos> Q;
    Q.push(ini);
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[ini.first][ini.second] = 0;
    int distMax = -1;
    
    while (not Q.empty()) {
        Pos act = Q.front();
        Q.pop();
        
        if (T[act.first][act.second] == 't') distMax = dist[act.first][act.second];
        T[act.first][act.second] = 'X';
        
        for (int i = 0; i < 4; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            
            if (pos_ok(x,y,n,m) and T[x][y] != 'X' and dist[x][y] == -1) {
                Q.push({x,y});
                dist[x][y] = dist[act.first][act.second] + 1;
            }
        }
    }
    return distMax;
}

int main() {
    int n, m;
    cin >> n >> m;
    Tauler T(n, vector<char>(m));
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) cin >> T[i][j];
         
    
    Pos ini;
    cin >> ini.first >> ini.second;
    --ini.first; --ini.second;
    
    int distMax = distancia_tresor(T, ini, n, m);
    if (distMax != -1) cout << "distancia maxima: " << distMax << endl;
    else cout << "no es pot arribar a cap tresor\n";
}
    

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<vector<char>> Mapa;

const int X[4] = {0,1,0,-1};
const int Y[4] = {1,0,-1,0};

bool pos_ok(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int min_dist(Mapa& map, Pos& ini, int n, int m) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[ini.first][ini.second] = 0;
    
    queue<Pos> Q;
    Q.push(ini);
    
    while (not Q.empty()) {
        Pos act = Q.front();
        if (map[act.first][act.second] == 't') return dist[act.first][act.second];
        map[act.first][act.second] = 'X';
        Q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            if (pos_ok(x,y,n,m) and map[x][y] != 'X') {
                dist[x][y] = dist[act.first][act.second] + 1;
                Q.push({x,y});
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    Mapa map(n, vector<char>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> map[i][j];
    }
    int ini_i, ini_j;
    cin >> ini_i >> ini_j;
    Pos ini = {ini_i-1,ini_j-1};
    
    int x = min_dist(map,ini,n,m);
    if (x == -1) cout << "no es pot arribar a cap tresor\n";
    else cout << "distancia minima: " << x << endl;
}
    
    

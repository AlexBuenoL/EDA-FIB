#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> Pos;
typedef vector<vector<char>> Tauler;
typedef vector<vector<int>> Dist;

const int X[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int inf = INT_MAX;

bool pos_ok(int i, int j, int f, int c) {
    return i >= 0 and i < f and j >= 0 and j < c;
}

int min_dist(Tauler& T, int f, int c, Pos& ini) {
    Dist dist(f, vector<int>(c, inf));
    dist[ini.first][ini.second] = 0;
    
    queue<Pos> Q;
    Q.push(ini);
    
    while (not Q.empty()) {
        Pos act = Q.front();
        Q.pop();
        
        if (T[act.first][act.second] == 'p') 
            return dist[act.first][act.second];
        
        T[act.first][act.second] = 'X';
        
        for (int i = 0; i < 8; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            if (pos_ok(x,y,f,c) and T[x][y] != 'X' and dist[x][y] == inf) {
                int nd = dist[act.first][act.second] + 1;
                if (nd < dist[x][y]) dist[x][y] = nd;
                Q.push({x,y});
            }
        }
    }
    return inf;
}

int main() {
    int f, c;
    while (cin >> f >> c) {
        Tauler T(f, vector<char>(c));
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j) cin >> T[i][j];
            
        Pos ini;
        cin >> ini.first >> ini.second;
        --ini.first; --ini.second;
        
        int d = min_dist(T, f, c, ini);
        if (d != inf) cout << d << endl;
        else cout << "no" << endl;
    }
}

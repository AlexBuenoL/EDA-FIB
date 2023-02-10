#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef vector<vector<int>> Matriz;
typedef pair<int,int> ParInt;

const int X[4] = {1,0,-1,0};
const int Y[4] = {0,1,0,-1};
const int inf = INT_MAX;


bool pos_ok(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

// minim dist - max. persones
ParInt BFS(Tauler& T) {
    if (T[0][0] == 'T') return {0,0};
    int n = T.size();
    int m = T[0].size();
    
    queue<ParInt> Q; // cua de posicions
    Q.push({0,0});
    
    // se necesita matriz de distancias y de personas
    Matriz dist(n, vector<int>(m, inf));
    Matriz pers(n, vector<int>(m, -1));
    
    dist[0][0] = 0;
    pers[0][0] = 0;
    
    if (T[0][0] == 'P') ++pers[0][0];
    
    while (not Q.empty()) {
        ParInt act = Q.front();
        Q.pop();
        
        if (T[act.first][act.second] == 'T')
            return {dist[act.first][act.second], pers[act.first][act.second]};
        
        T[act.first][act.second] = '#';
        
        for (int i = 0; i < 4; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            
            if (pos_ok(x,y,n,m) and T[x][y] != '#') {
                int d = dist[act.first][act.second] + 1;
                int np = pers[act.first][act.second];
                if (T[x][y] == 'P') ++np;
                
                if (dist[x][y] == inf) {
                    dist[x][y] = d;
                    pers[x][y] = np;
                    Q.push({x,y});
                }
                else if (dist[x][y] == d and pers[x][y] < np)
                    pers[x][y] = np;
            }
        }
    }
    return {-1,-1};
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Tauler T(n, vector<char>(m));
        bool trobat = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> T[i][j];
                if (T[i][j] == 'T') trobat = true;
            }
        }
        
        if (not trobat) cout << "El telecos ha fugit." << endl;
        else {
            ParInt par_res = BFS(T);
            if (par_res.first == -1) cout << "El telecos esta amagat." << endl;
            else cout << par_res.first << ' ' << par_res.second << endl;
        }
    }
}
                
    

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef pair<int,int> Pos;

int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};

bool pos_ok(int i, int j, int n, int m) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

void bt_tortuga(Tauler& T, Pos& act, Pos& fin, string& sol, int n, int m, vector<vector<bool>>& vis) {
    
    if (act == fin) cout << sol << endl;
    else {
        
        for (int i = 0; i < 4; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            
            if (pos_ok(x,y,n,m) and not vis[x][y]) {
                sol.push_back(T[x][y]);
                Pos p = {x,y};
                vis[x][y] = true;
                bt_tortuga(T, p, fin, sol, n, m, vis);
                sol.pop_back();
                vis[x][y] = false;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Tauler T(n, vector<char>(m));
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) cin >> T[i][j];
        
    Pos ini, fin;
    cin >> ini.first >> ini.second >> fin.first >> fin.second;
    
    string sol = "";
    sol.push_back(T[ini.first][ini.second]);
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vis[ini.first][ini.second] = true;
    
    bt_tortuga(T, ini, fin, sol, n, m, vis);
}
    

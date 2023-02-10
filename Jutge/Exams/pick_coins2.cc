#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef pair<int,int> Pos;

const int alfilsX[4] = {-1, 1, 1, -1};
const int alfilsY[4] = {1, 1, -1, -1};
const int cavallsX[8] = {-2, -1, 1, 2,  2,  1, -1, -2};
const int cavallsY[8] = {1,   2, 2, 1, -1, -2, -2, -1};

bool pos_ok(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int dfs_monedes(Tauler& T, int n, int m, Pos& act, const string& pers, vector<vector<bool>>& vis) {
   
    int monedes = 0;
    
    vis[act.first][act.second] = true;
    
    if (pers == "alfils") {
        for (int i = 0; i < 4; ++i) {
            int x = act.first + alfilsX[i];
            int y = act.second + alfilsY[i];
            Pos p = {x,y};
            if (pos_ok(x,y,n,m) and not vis[x][y] and T[x][y] != 'T') monedes += dfs_monedes(T, n, m, p, pers, vis);
        }
    }
    else {
        for (int i = 0; i < 8; ++i) {
            int x = act.first + cavallsX[i];
            int y = act.second + cavallsY[i];
            Pos p = {x,y};
            if (pos_ok(x,y,n,m) and not vis[x][y] and T[x][y] != 'T') monedes += dfs_monedes(T, n, m, p, pers, vis);
        }
    }
    
    char c = T[act.first][act.second];
    if (c >= '1' and c <= '9') {
        monedes += c - 48;
        T[act.first][act.second] = '.';
    }
    
    
    return monedes;
}

int num_monedes(Tauler& T, int n, int m, vector<Pos>& alfils, vector<Pos>& cavalls) {
    int tot = 0;
    
    vector<vector<bool>> alfils_vis(n, vector<bool>(m, false));
    for (int i = 0; i < alfils.size(); ++i) 
        if (not alfils_vis[alfils[i].first][alfils[i].second]) tot += dfs_monedes(T, n, m, alfils[i], "alfils", alfils_vis);
        
    vector<vector<bool>> cavalls_vis(n, vector<bool>(m, false));
    for (int i = 0; i < cavalls.size(); ++i) 
        if (not cavalls_vis[cavalls[i].first][cavalls[i].second]) tot += dfs_monedes(T, n, m, cavalls[i], "cavalls", cavalls_vis);
        
    return tot;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Tauler T(n, vector<char>(m));
        vector<Pos> alfils;
        vector<Pos> cavalls;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> T[i][j];
                if (T[i][j] == 'B') alfils.push_back({i,j});
                else if (T[i][j] == 'K') cavalls.push_back({i,j});
            }
        }
        cout << num_monedes(T, n, m, alfils, cavalls) << endl;   
    }
}

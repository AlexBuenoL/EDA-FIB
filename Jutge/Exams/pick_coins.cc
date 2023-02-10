#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef pair<int,int> Pos;

const int alfilsX[4] = {-1, 1, 1, -1};
const int alfilsY[4] = {1, 1, -1, -1};
const int cavallsX[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int cavallsY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int nMonedes = 0;

bool pos_ok(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int bfs_monedes(Tauler& T, int n, int m, Pos& ini, const string& pers, vector<vector<bool>>& marked) {
    queue<Pos> Q;
    Q.push(ini);
    int monedes = 0;
    
    while (not Q.empty() and nMonedes != 0) {
        Pos act = Q.front();
        Q.pop();
           
        char c = T[act.first][act.second];
        if (c >= '1' and c <= '9') {
            monedes += c - 48;
            T[act.first][act.second] = '.';
            --nMonedes;
        }
        
        marked[act.first][act.second] = true;
        
        if (pers == "alfils") {
            for (int i = 0; i < 4; ++i) {
                int x = act.first + alfilsX[i];
                int y = act.second + alfilsY[i];
                if (pos_ok(x,y,n,m) and not marked[x][y] and T[x][y] != 'T') Q.push({x,y});
            }
        }
        else {
            for (int i = 0; i < 8; ++i) {
                int x = act.first + cavallsX[i];
                int y = act.second + cavallsY[i];
                if (pos_ok(x,y,n,m) and not marked[x][y] and T[x][y] != 'T') Q.push({x,y});
            }
        }
    }
    
    return monedes;
}

int num_monedes(Tauler& T, int n, int m, vector<Pos>& alfils, vector<Pos>& cavalls) {
    int tot = 0;
    vector<vector<bool>> marked_alfils(n, vector<bool>(m, false));
    for (int i = 0; i < alfils.size() and nMonedes != 0; ++i) 
        if (not marked_alfils[alfils[i].first][alfils[i].second]) tot += bfs_monedes(T, n, m, alfils[i], "alfils", marked_alfils);
    vector<vector<bool>> marked_cavalls(n, vector<bool>(m, false));
    for (int i = 0; i < cavalls.size() and nMonedes != 0; ++i) 
        if (not marked_cavalls[cavalls[i].first][cavalls[i].second]) tot += bfs_monedes(T, n, m, cavalls[i], "cavalls", marked_cavalls);
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
                else if (T[i][j] >= '1' and T[i][j] <= '9') ++nMonedes;
            }
        }
        if (nMonedes != 0) cout << num_monedes(T, n, m, alfils, cavalls) << endl;       
        else cout << 0 << endl;
    }
}

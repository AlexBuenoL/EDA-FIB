#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef pair<int,int> Pos;

const int X[4] = {1,0,-1,0};
const int Y[4] = {0,1,0,-1};

bool pos_ok(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int tresors(Tauler& T, Pos& act, int n, int m, vector<vector<bool>>& vis) {
    int res = 0;
    vis[act.first][act.second] = true;
    
    for (int i = 0; i < 4; ++i) {
        int x = act.first + X[i];
        int y = act.second + Y[i];
        if (pos_ok(x,y,n,m) and T[x][y] != 'X' and not vis[x][y]) {
            Pos p = {x,y};
            res += tresors(T, p, n, m, vis);
        }
    }
    
    if (T[act.first][act.second] == 't') ++res;
    
    return res;
}
    

int main() {
    int n, m;
    cin >> n >> m;
    Tauler T(n, vector<char>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> T[i][j];
        }
    }
    
    int pi,pj;
    cin >> pi >> pj;
    --pi;
    --pj;
    Pos ini = {pi,pj};
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    cout << tresors(T, ini, n, m, vis) << endl;
    
}

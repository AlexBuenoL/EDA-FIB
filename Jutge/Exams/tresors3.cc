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

int tresors(Tauler& T, Pos& ini, int n, int m, int numT) {
    queue<Pos> Q;
    Q.push(ini);
    int res = 0;
    
    while (not Q.empty() and numT > 0) {
        Pos act = Q.front();
        Q.pop();
        
        if (T[act.first][act.second] == 't') {
            ++res;
            --numT;
        }
        
        T[act.first][act.second] = 'X';
        
        for (int i = 0; i < 4; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            if (pos_ok(x,y,n,m) and T[x][y] != 'X') Q.push({x,y});
        }
    }
    
    return res;
}
    

int main() {
    int n, m;
    cin >> n >> m;
    Tauler T(n, vector<char>(m));
    
    int numT = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> T[i][j];
            if (T[i][j] == 't') ++numT;
        }
    }
    
    Pos ini;
    cin >> ini.first >> ini.second;
    --ini.first; --ini.second;
    
    if (numT == 0) cout << 0 << endl;
    else cout << tresors(T, ini, n, m, numT) << endl;
}

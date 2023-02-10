#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<char>> Matriu;
typedef pair<int,int> Pos;

const int X[4] = {-1, 0, 1, 0};
const int Y[4] = {0, 1, 0, -1};

bool pos_ok(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

bool bfs(Matriu& mat, int n, int m, Pos& ini) {
    queue<Pos> Q;
    Q.push(ini);
    mat[ini.first][ini.second] = 'X';
    
    while (not Q.empty()) {
        Pos act = Q.front();
        if (mat[act.first][act.second] == 'F') return true;
        Q.pop();
        mat[act.first][act.second] = 'X';
        
        for (int i = 0; i < 4; ++i) {
            int x = act.first + X[i];
            int y = act.second + Y[i];
            Pos p = {x,y};
            
            if (pos_ok(x,y,n,m) and mat[x][y] != 'X') {
                Q.push(p);
            }
        }
    }
    return false;
}
    
void rodear_monstruos(Matriu& mat, const vector<Pos>& mon, int n, int m) {
    for (int i = 0; i < int(mon.size()); ++i) {
			Pos p = mon[i];
			for (int j = 0; j < 4; ++j) {
				int x = p.first + X[j];
				int y = p.second + Y[j];
				if (pos_ok(x, y, n, m)) mat[x][y] = 'X';
			}
		}
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Matriu mat(n, vector<char>(m));
        Pos ini;
        vector<Pos> mon;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mat[i][j];
                if (mat[i][j] == 'I') ini = {i,j};
                else if (mat[i][j] == 'M') mon.push_back({i,j});
            }
        }
        
        rodear_monstruos(mat, mon, n, m);
        
        if (bfs(mat, n, m, ini)) cout << "SI\n";
        else cout << "NO\n";
    }
}

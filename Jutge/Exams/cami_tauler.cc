#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef vector<vector<int>> Matriu;
typedef pair<int,int> Pos;
typedef pair<int,Pos> DistPos;

const int X[4] = {1,0,-1,0};
const int Y[4] = {0,1,0,-1};
const int inf = INT_MAX;

int cost_min(const Matriu& mat, int n) {
    Pos c = {n/2, n/2};
    
    Matriu dist(n, vector<int>(n, inf));
    Matriu vis(n, vector<int>(n, 0));
    
    dist[c.first][c.second] = mat[c.first][c.second];
    vis[c.first][c.second] = 1;
    
    priority_queue<DistPos, vector<DistPos>, greater<DistPos>> PQ;
    PQ.push({dist[c.first][c.second], c});
    
    while (not Q.empty()) {
        Pos = PQ.top().second
        PQ.pop();
        
        if (vis[act.first][act.second] == 0) {
            vis[act.first][act.second] = 1;
            
            if (es_periferia(act, n)) return dist[act.first][act.second];
            
            for (int i = 0; i < 4; ++i) {
                int x = act.first + dirs[i].first;
                int y = act.second + dirs[i].second;
                
                if (dist[x][y] > dist[act.first][act.second] + mat[x][y]) {
                    dist[x][y] = dist[act.first][act.second] + mat[x][y];
                    PQ.push({dist[x][y], {x,y}});
                }
            }
        }
    }
    return 0;
    
}

int main() {
    
    
    
}

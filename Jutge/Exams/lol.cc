#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Matriu;

bool pos_ok(int i, int j, int n, int m) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

int back_lol(Matriu& mat, int i, int j, int n, int m, int sol) {
    if (i == n) return sol;
    else {
        
        int x, y;
        
        mat[i][j] = 'O';
        if (j < m-1) x = back_lol(mat,i,j+1,n,m,sol);
        else x = back_lol(mat,i+1,0,n,m,sol);
        
        mat[i][j] = 'L';
        if (pos_ok(i,j-1,n,m) and pos_ok(i,j-2,n,m) and mat[i][j-1] == 'O' and mat[i][j-2] == 'L') ++sol;
        if (pos_ok(i-1,j,n,m) and pos_ok(i-2,j,n,m) and mat[i-1][j] == 'O' and mat[i-2][j] == 'L') ++sol;
        if (pos_ok(i-1,j+1,n,m) and pos_ok(i-2,j+2,n,m) and mat[i-1][j+1] == 'O' and mat[i-2][j+2] == 'L') ++sol;
        if (pos_ok(i-1,j-1,n,m) and pos_ok(i-2,j-2,n,m) and mat[i-1][j-1] == 'O' and mat[i-2][j-2] == 'L') ++sol;
        
        if (j < m-1) y = back_lol(mat,i,j+1,n,m,sol);
        else y = back_lol(mat,i+1,0,n,m,sol);
        
        return max(x,y);
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Matriu mat(n, vector<char>(m));
        cout << back_lol(mat, 0, 0, n, m, 0) << endl;
    }
}

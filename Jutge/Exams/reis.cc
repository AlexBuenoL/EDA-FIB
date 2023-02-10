#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tauler;

void escriu_tauler(const Tauler& T, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << T[i][j];
        cout << endl;
    }
    cout << "----------\n";
}

bool pos_ok(int i, int j, int n) {
    return i >= 0 and i < n and j >= 0 and j < n;
}

bool amenacat(const Tauler& T, int i, int j, int n) {
    if (pos_ok(i-1,j,n) and T[i-1][j] == 'K') return true;
    if (pos_ok(i,j-1,n) and T[i][j-1] == 'K') return true;
    if (pos_ok(i-1,j+1,n) and T[i-1][j+1] == 'K') return true;
    if (pos_ok(i-1,j-1,n) and T[i-1][j-1] == 'K') return true;
    return false;
}

void bt_reis(Tauler& T, int i, int j, int escrits, int n, int r) {
    if (escrits == r) escriu_tauler(T, n);
    else {
        if (pos_ok(i,j,n) and not amenacat(T,i,j,n)) {
            T[i][j] = 'K';
            if (j <= n-2) bt_reis(T, i, j+1, escrits+1, n, r);
            else bt_reis(T, i+1, 0, escrits+1, n, r);
            T[i][j] = '.';
        }
        if (pos_ok(i,j,n)) {
            if (j <= n-2) bt_reis(T, i, j+1, escrits, n, r);
            else bt_reis(T, i+1, 0, escrits, n, r);
        }
    }
    
}

int main() {
    int n, r;
    cin >> n >> r;
    Tauler T(n, vector<char>(n, '.'));
    bt_reis(T, 0, 0, 0, n, r);
}

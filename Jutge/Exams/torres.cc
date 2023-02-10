#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Tauler;
typedef pair<int,int> Pos;

void escriure_tauler(const Tauler& T, int f, int c) {
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) cout << T[i][j];
        cout << endl;
    }
    cout << endl;
}

void bt_torres(Tauler& T, int i, int f, int c, vector<bool>& col_ocupades) {
    if (i == f) escriure_tauler(T, f, c);
    else {
        for (int j = 0; j < c; ++j) {
            if (not col_ocupades[j]) {
                T[i][j] = 'R';
                col_ocupades[j] = true;
                bt_torres(T,i+1, f, c, col_ocupades);
                
                T[i][j] = '.';
                col_ocupades[j] = false;
            }
        }
    }
}

int main() {
    int f, c;
    cin >> f >> c;
    
    Tauler T(f, vector<char>(c, '.'));
    vector<bool> col_ocupades(c);
    bt_torres(T, 0, f, c, col_ocupades);
}
    

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool es_prohibit(int n, const vector<int>& prohibits) {
    for (int i = 0; i < prohibits.size(); ++i) { 
        if (n%prohibits[i] == 0) 
            return true;
    }
    return false;
}

void bt_prefixos(int& sol, int n, const vector<int>& prohibits, int i) {
    if (i == n) cout << sol << endl;
    else {
        for (int j = 0; j <= 9; ++j) {
            int newNum = sol*10 + j;
            if (not es_prohibit(newNum, prohibits)) {
                bt_prefixos(newNum, n, prohibits, i+1);
            }
        }
    }
}
    

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> prohibits(m);
        for (int i = 0; i < m; ++i) cin >> prohibits[i];
        
        int sol = 0;
        bt_prefixos(sol, n, prohibits, 0);
        cout << string(10,'-') << endl;
    }
}

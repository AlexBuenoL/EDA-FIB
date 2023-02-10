#include <iostream>
#include <string>
using namespace std;

void accions(string& sol, int n, int c, int acc) {
    if (sol.length() == n) cout << sol << endl;
    else {
        if (c > 0) {
            sol.push_back('b');
            accions(sol, n, c-1, acc+1);
            sol.pop_back();
        } 
        if (acc > 0) {
            sol.push_back('s');
            accions(sol, n, c+1, acc-1);
            sol.pop_back();
        }
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    string sol = "";
    accions(sol,n,c,0);
}

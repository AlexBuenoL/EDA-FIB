#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bt_concatenar(string& sol, const vector<string>& v, 
                   int n, int ind, vector<bool>& used) {
    if (ind == n) cout << sol << endl;
    else {
        if (sol.length() == 0) {
            for (int i = 0; i < n; ++i) {
                sol = v[i]; //sol.push_back(v[i]);
                used[i] = true;
                bt_concatenar(sol, v, n, ind+1, used);
                
                sol = "";
                used[i] = false;
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (not used[i] and v[i][0] != sol[sol.length()-1]) {
                    string aux = sol;
                    sol = sol + v[i];  //sol.push_back(v[i]);
                    used[i] = true;
                    bt_concatenar(sol, v, n, ind+1, used);
                    
                    sol = aux;
                    used[i] = false;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    string sol = "";
    vector<bool> used(n, false);
    bt_concatenar(sol, v, n, 0, used);
    
}

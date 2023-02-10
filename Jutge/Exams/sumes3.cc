#include <iostream>
#include <vector>
#include <string>
using namespace std;

void escriure_vector(const vector<int>& sol) {
    cout << '{';
    for (int i = 0; i < sol.size()-1; ++i) cout << sol[i] << ',';
    cout << sol[sol.size()-1] << '}' << endl;
}

void bt_suma(vector<int>& sol, int n, int s, int suma,
             vector<int>& valors, vector<bool>& usats) {
    if (suma == s) escriure_vector(sol);
    else {
        for (int i = 0; i < n; ++i) {
            if (not usats[i]) {
                sol.push_back(valors[i]);
                usats[i] = true;
                bt_suma(sol, n, s, suma+valors[i], valors, usats);
                
                sol.pop_back();
                usats[i] = false;
            }
        }
    }
}
    

int main() {
    int s, n;
    cin >> s >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    vector<int> sol;
    vector<bool> usats(n, false);
    bt_suma(sol, n, s, 0, v, usats);
}

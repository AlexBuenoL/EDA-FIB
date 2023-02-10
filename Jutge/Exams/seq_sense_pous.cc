#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

void escriure_sol(const vector<int>& sol, int n) {
    cout << '(';
    for (int i = 0; i < n-1; ++i) cout << sol[i] << ',';
    cout << sol[n-1] << ")\n";
}

bool es_pou(const vector<int>& v) {
    int n = v.size();
    if (n < 3) return false;
    
    for (int i = 1; i < n-1; ++i) {
        if (v[i-1] + v[i+1] > 2*v[i]) return true;
    }
    
    return false;
}

bool duplicados(const vector<int>& v) {
    set<int> s;

    for (int n : v) {
        s.insert(n);
    }
    
    return s.size() < v.size();
}

void bt(vector<int>& sol, int n) {
    if (sol.size() == n) escriure_sol(sol, n);
    else {
        for (int i = 1; i <= n; ++i) {
            sol.push_back(i);
            if (not es_pou(sol) and not duplicados(sol)) bt(sol, n);
            sol.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> sol;
    bt(sol, n);
}

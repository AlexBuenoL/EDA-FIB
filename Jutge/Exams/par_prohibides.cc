#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bt_prohibides(string& sol, int n, const string& abc, vector<bool>& usats) {
    if (sol.length() == n) cout << sol << endl;
    else {
        for (int i = 0; i < n; ++i) {
            if (not usats[i]) {
                char y = abc[i];
                char x = sol[sol.length()-1];
                if (y != x+1) {
                    sol.push_back(y);
                    usats[i] = true;
                    bt_prohibides(sol,n,abc,usats);
                    
                    sol.pop_back();
                    usats[i] = false;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    string sol = "";
    string abc = "abcdefghi";
    if (n < 9) abc = abc.substr(0,n);
    vector<bool> usats(n);
    bt_prohibides(sol, n, abc, usats);
}

#include <iostream>
#include <string>
using namespace std;

const string ADN = "ACGT";

void back(string& sol, int n) {
    if (sol.length() == n) cout << sol << endl;
    else {
        for (char x : ADN) {
            sol.push_back(x);
            back(sol, n);
            sol.pop_back();
        }
    }
}
        

int main() {
    int n;
    cin >> n;
    string sol = "";
    back(sol, n);
}

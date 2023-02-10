#include <iostream>
#include <string>
using namespace std;

bool compensada(const string& word) {
    int n = word.length();
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (word[i] == 'a') ++a;
        else ++b;
    }
    return (abs(a-b) <= 2);
}

void back(string& sol, int n) {
    if (sol.length() == n and compensada(sol)) cout << sol << endl;
    else {
        if (sol.length() <= 2 or compensada(sol)) {
            sol.push_back('a');
            back(sol, n);
            sol.pop_back();
            
            sol.push_back('b');
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

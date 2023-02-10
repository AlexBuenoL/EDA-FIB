#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool es_vocal(char l) {
    return (l == 'a' or l == 'e' or l == 'i' or l == 'o' or l == 'u');
}

bool es_consonant(char l) {
    return (l >= 'a' and l <= 'z' and not es_vocal(l));
}

void bt_ruines(string& sol, int n, const string& letters, 
               priority_queue<string, vector<string>, greater<string>>& PQ) {
    if (sol.size() == n) PQ.push(sol);
    else {
        for (char l : letters) {
            bool afegir = false;
            if (es_consonant(l) or sol.length() == 0) afegir = true;
            else if (not es_vocal(sol[sol.length()-1])) afegir = true;
            
            if (afegir) {
                sol.push_back(l);
                bt_ruines(sol, n, letters, PQ);
                sol.pop_back();
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        string letters;
        cin >> letters;
        
        string sol = "";
        priority_queue<string, vector<string>, greater<string>> PQ;
        bt_ruines(sol, n, letters, PQ);
        while (not PQ.empty()) {
            cout << PQ.top() << endl;
            PQ.pop();
        }
        cout << "----------" << endl;
    }
}

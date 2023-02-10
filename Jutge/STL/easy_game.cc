#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string w;
    int cont = 1;
    map<string,bool> joc;
    while (cin >> w && w != "QUIT") {

        if (w != "END") {
            if (joc.find(w) == joc.end()) joc.insert(make_pair(w,1));
            else {
                if (joc[w]) joc[w] = 0;
                else joc[w] = 1;
            }
        } else {
            cout << "GAME #" << cont << "\nHAS:\n";
            for (auto it = joc.begin(); it != joc.end(); ++it) 
                if (it->second) cout << it->first << endl;
            cout << "\nHAD:\n";
            for (auto it = joc.begin(); it != joc.end(); ++it) 
                if (!it->second) cout << it->first << endl;
            ++cont;
            joc.clear();
        }
    }
    cout << "GAME #" << cont << "\nHAS:\n";
    for (auto it = joc.begin(); it != joc.end(); ++it) 
        if (it->second) cout << it->first << endl;
    cout << "\nHAD:\n";
    for (auto it = joc.begin(); it != joc.end(); ++it) 
        if (!it->second) cout << it->first << endl;
}

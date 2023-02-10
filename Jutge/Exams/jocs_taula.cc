#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        map<string,int> jocs;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            ++jocs[s];
        }
        int j;
        cin >> j;
        string s2;
        for (int i = 0; i < j; ++i) {
            cin >> s2;
            auto it = jocs.find(s2);
            if (it == jocs.end()) {
                ++jocs[s2];
                ++n;
            }
            else {
                if (jocs[s2]+1 <= n-jocs[s2]) {
                    ++jocs[s2];
                    ++n;
                }
            }
        }
        
        auto it = jocs.begin();
        for (it; it != jocs.end(); ++it) 
            cout << it->first << ' ' << it->second << endl;
        cout << string(20, '-') << endl;
    }
}
                
        

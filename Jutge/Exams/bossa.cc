#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<long int> Sel;
    set<long int> Resta;
    long int suma_actual = 0;
    
    string a;
    long int x;
    
    while (cin >> a >> x) {
        
        if (a == "deixar") {
            if (Sel.size() < n) {
                Sel.insert(x);
                suma_actual += x;
            }
            else {
                long int min = *(Sel.begin());
                if (x > min) {
                    Sel.insert(x);
                    Sel.erase(Sel.begin());
                    suma_actual += x - min;
                    Resta.insert(min);
                }
                else Resta.insert(x);
            }
        }
        else {
            if (*(Sel.begin()) <= x) {
                Sel.erase(x);
                suma_actual -= x;
                if (Resta.size() > 0) {
                    auto it = Resta.end();
                    --it;
                    Sel.insert(*it);
                    suma_actual += *it;
                    Resta.erase(*it);
                }
            }
            else Resta.erase(x);
        }
        
        cout << suma_actual << endl;
    }
}

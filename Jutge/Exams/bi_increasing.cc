#include <vector>
#include <iostream>
using namespace std;

bool dic_search(int x, const vector<int>& v, int esq, int der) {
    if (esq > der) return false;
    int m = (esq+der)/2;
    if (v[m] == x) return true;
    if (v[m] >= x) return dic_search(x, v, esq, m-1);
    return dic_search(x, v, m+1, der);
}

bool i_search(int x, const vector<int>& v, int esq, int dre) {
    if (esq > dre) return false;
    int m = (esq+dre)/2;
    if (v[m] == x) return true;
    else if (v[m] < v[esq]) { // el pico esta en la izq, y la der esta ordenada 
        if (v[m] < x and x <= v[dre]) return dic_search(x, v, m+1, dre);
        return i_search(x, v, esq, m-1);
    } else { // el pico esta en la der y la izq esta ordenada
        if (v[esq] <= x and x < v[m]) return dic_search(x, v, esq, m-1);
        return i_search(x, v, m+1, dre);
    }
}

bool search(int x, const vector<int>& v) {
    return i_search(x, v, 0, v.size()-1);
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}

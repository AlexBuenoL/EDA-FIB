#include <vector>
using namespace std;

int i_mes_a_la_dreta(double x, const vector<double>& v, int l, int r) {
    if (l == r) return l;
    int med = (r+l)/2;
    
    if (x < v[med]) return i_mes_a_la_dreta(x,v,l,med);
    else return i_mes_a_la_dreta(x,v,med+1,r);
}

int mes_a_la_dreta(double x, const vector<double>& v) {
    return i_mes_a_la_dreta(x, v, 0, v.size());
}

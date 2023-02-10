#include <iostream>
#include <vector>
using namespace std;

int first_occurrence_i(double x, const vector<double>& v, int beg, int end) {

    if (beg > end) return -1;
    
    int m = (beg+end)/2;
    if (v[m] == x) {
        if (v[m-1] == x && m-1 >= beg)
            return first_occurrence_i(x,v,beg,m-1);
        else 
            return m;
    }
    else if (x > v[m])
        return first_occurrence_i(x,v,m+1,end);
    else 
        return first_occurrence_i(x,v,beg,m-1);
}

int first_occurrence(double x, const vector<double>& v) {
    return first_occurrence_i(x,v,0,v.size()-1);
}

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int x;
    cin >> x;
    cout << "First occurrence: " << first_occurrence(x,v) << endl;
}
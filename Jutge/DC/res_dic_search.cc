#include <iostream>
#include <vector>
using namespace std;

bool resistant_search_i(double x, const vector<double>& v, int beg, int end) {
	if (beg > end) return false;
	int m = (beg+end)/2;
	if (v[m] == x || (v[m-1] == x && m-1 >= beg) || (v[m+1] == x && m+1 <= end))
		return true;
	if (x < v[m]) return resistant_search_i(x,v,beg,m-1);
	else return resistant_search_i(x,v,m+1,end);
}

bool resistant_search(double x, const vector<double>& v) {
	return resistant_search_i(x,v,0,v.size()-1);
}


int main() {

	int n;
	cin >> n;
	vector<double> vec(n);
	for (int i = 0; i < n; ++i) cin >> vec[i];

	double x;
    cin >> x;

    cout << resistant_search(x, vec) << endl;

}
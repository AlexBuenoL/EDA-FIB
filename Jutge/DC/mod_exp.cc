#include <iostream>
#include <cmath>
using namespace std;

int mod(int n, int k, int m) {

	if (k == 0) return 1;
	else if (k <= 1) return n%m;
	else {
		int x = mod(n, k/2, m)%m;
		if (k%2 == 0) return (x*x)%m;
		else return (((x*x)%m)*n)%m;
	}
}

int main() {
	int n, k, m;
	while (cin >> n >> k >> m) cout << mod(n,k,m) << endl;
}
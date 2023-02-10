#include <iostream>
#include <map>
using namespace std;

#define LIMIT 100000000

int main() {

	int x, y, n;
	map<int,int> map;

	while (cin >> x >> y >> n) {
		bool repeated = false;
		int res = 0;

		while (not repeated and n <= LIMIT) {

			if (map.find(n) != map.end()) {
				res -= map[n];
				repeated = true;
			}
			++res;
			map[n] = res;
			if (n % 2 == 0) n = n/2 + x;
			else n = 3*n + y;
		}

		map.clear();
		cout << (repeated ? res : n) << endl;
	}
}


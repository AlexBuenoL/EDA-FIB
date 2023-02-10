#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

bool cmp(int x, int y) {
    return x < y;
}

int k_esim(int k, const VVE& V) {

	int n = V.size();
	int count = 1;

	vector<int> vec;

	for (int i = 0; i < n; ++i) {

		int m = V[i].size();

		for (int j = 0; j < m; ++j) {

			vec.push_back(V[i][j]);
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	return vec[k-1];
}


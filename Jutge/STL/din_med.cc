#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string x, string y) {
	return x < y;
}

int main() {

	vector<string> v{"hola", "bye", "adeu", "hi", "hello"};

	sort(v.begin(),v.end(), cmp);

	for (auto x : v)
		cout << x << "\n";

    
}
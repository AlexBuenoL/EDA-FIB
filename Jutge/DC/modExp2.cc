#include <iostream>
using namespace std;

int modExp(int n, int k, int m) {

    if (n == 1 || k == 0) return 1;
    if (k <= 1) return n%m;

    int x = modExp(n, k/2, m)%m;
    if (k%2 == 0) return (x*x)%m;
    else return (((x*x)%m)*n)%m;
}

int main() {

    int n, k, m;
    while (cin >> n >> k >> m) {
        cout << modExp(n, k, m) << endl;
    }
}
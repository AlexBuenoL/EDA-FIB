#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

Matrix multi(const Matrix& a, const Matrix& b, int m) {
    Matrix res(2, vector<int>(2));
    res[0][0] = ((a[0][0]*b[0][0])%m + (a[0][1]*b[1][0])%m)%m;
    res[0][1] = ((a[0][0]*b[0][1])%m + (a[0][1]*b[1][1])%m)%m;
    res[1][0] = ((a[1][0]*b[0][0])%m + (a[1][1]*b[1][0])%m)%m;
    res[1][1] = ((a[1][0]*b[0][1])%m + (a[1][1]*b[1][1])%m)%m;
    return res;
}

void pow_matrix(Matrix& res, Matrix& M, int n, int m) {
    if (n == 0) {
        res[0][0] = res[1][1] = 1;
        res[0][1] = res[1][0] = 0;
    } else if (n == 1) {
        res[0][0] = M[0][0]%m;
        res[0][1] = M[0][1]%m;
        res[1][0] = M[1][0]%m;
        res[1][1] = M[1][1]%m;
    } else if (n%2 == 0) {
        Matrix aux(2, vector<int>(2));
        pow_matrix(aux, M, n/2, m); 
        res = multi(aux, aux, m); 
    } else {
        Matrix aux(2, vector<int>(2));
        pow_matrix(aux, M, n-1, m); 
        res = multi(M, aux, m); 
    }
}

int main() {
    int x;
    while (cin >> x) {
        Matrix M(2, vector<int>(2));
        M[0][0] = x; cin >> M[0][1]; cin >> M[1][0]; cin >> M[1][1];
        int n, m;
        cin >> n >> m;
        Matrix res(2, vector<int>(2));
        pow_matrix(res, M, n, m);
        cout << res[0][0] << ' ' << res[0][1] << endl << res[1][0] << ' ' << res[1][1] << endl;
        cout << string(10, '-') << endl;
    }
}

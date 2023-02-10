#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

const Matrix F = {{1,1},{1,0}};
                  
Matrix mult(const Matrix& A, const Matrix& B, int m) {
    Matrix Res(2, vector<int>(2));
    Res[0][0] = ((A[0][0]*B[0][0])%m + (A[0][1]*B[1][0])%m)%m;
    Res[0][1] = ((A[0][0]*B[0][1])%m + (A[0][1]*B[1][1])%m)%m;
    Res[1][0] = ((A[1][0]*B[0][0])%m + (A[1][1]*B[1][0])%m)%m;
    Res[1][1] = ((A[1][0]*B[0][1])%m + (A[1][1]*B[1][1])%m)%m;
    return Res;
}

// Exp.rapida
Matrix exp(const Matrix& M, int n, int m) {
    if (n == 1) return F;
    Matrix Aux = exp(M, n/2, m);
    Matrix Res = mult(Aux, Aux, m);
    if (n%2 != 0) Res = mult(Res, M, m);
    return Res;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0) cout << 0 << endl;
        else {
            Matrix Res = exp(F, n, m);
            cout << Res[0][1] << endl;
        }
    }
}

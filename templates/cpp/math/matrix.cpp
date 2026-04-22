#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll  MOD = 1e9 + 7;

struct Matrix {
    vector<vector<ll>> mat;

    Matrix(int rows = 0, int cols = 0, int defaultVal = 0) {
        if (rows > 0) mat.assign(rows, vector<ll>(cols, defaultVal));
    }

    static Matrix identity(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; i++) res.mat[i][i] = 1;
        return res;
    }

    Matrix operator *(const Matrix& other) const {
        int m = mat.size();
        int n = mat[0].size();
        int p = other.mat[0].size();

        Matrix product(m, p);

        for (int y = 0; y < m; y++) {
            for (int k = 0; k < n; k++) {
                if (mat[y][k] == 0) continue;
                for (int x = 0; x < p; x++) {
                    ll res = mat[y][k] * other.mat[k][x];
                    product.mat[y][x] = (product.mat[y][x] + res) % MOD;
                }
            }
        }
        return product;
    }
};

Matrix fastPow(const Matrix& A, int pow) {
    if (pow == 1) {
        auto ans = A;
        return ans;
    }
    else if (pow % 2 == 0) return fastPow(A * A, pow / 2);
    return A * fastPow(A * A, pow / 2);
}
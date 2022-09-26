#pragma once

const int MOD = (int)(1e9+7);

struct Matrix{
	int n,m;
	vector <vector <int>> a;
	Matrix(int n, int m) {
		this->n = n;
		this->m = m;
		a.resize(n,vector <int>(m));
	}
 
	Matrix operator*(const Matrix& other) {
		assert(m == other.n);
		Matrix product(n,other.m);
		for(int i=0;i<product.n;i++) {
			for(int j=0;j<product.m;j++) {
				for(int k=0;k<m;k++) {
					product.a[i][j] += (a[i][k]%MOD*other.a[k][j]%MOD)%MOD;
					product.a[i][j]%=MOD;
				}
			}
		}
		return product;
	}

    vector <int> & operator[] (int i) {
        return a[i];
    }
};

Matrix getIdentity(int n) {
	Matrix ans(n,n);
	for(int i=0;i<n;i++) {
		ans.a[i][i] = 1;
	}
	return ans;
}

Matrix power_mat(Matrix mat, int n) {
	assert(mat.n==mat.m);
	Matrix res = getIdentity(mat.n);
	while (n) {
		if (n&1) res = res * mat;
		mat = mat * mat;
		n >>= 1;
	}
	return res;
}
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
};

Matrix getIdentity(int n) {
	Matrix ans(n,n);
	for(int i=0;i<n;i++) {
		ans.a[i][i] = 1;
	}
	return ans;
}

Matrix pow(Matrix A, int n) {
	assert(A.n == A.m);
	Matrix ans = getIdentity(A.n);
	while(n) {
		if(n&1) ans = ans * A, n--;
		A = A*A, n /= 2;
	}
	return ans;
}

// fft template from kactl library
#pragma once

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
 
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = SZ(a), L = 31 - __builtin_clz(n);
	static vector<complex<double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vector<int> rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(SZ(a) + SZ(b) - 1);
	int L = 32 - __builtin_clz(SZ(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(ALL(a), begin(in));
	rep(i,0,SZ(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,SZ(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}
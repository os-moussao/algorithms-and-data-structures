#pragma once

struct segTree {
	typedef int T;
	static const T identity = 0;
	T fn(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	segTree(int n = 0, T def = identity) : s(4*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = fn(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = identity, rb = identity;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = fn(ra, s[b++]);
			if (e % 2) rb = fn(s[--e], rb);
		}
		return fn(ra, rb);
	}
};

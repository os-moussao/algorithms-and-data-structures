#pragma once

// from kactl library: https://github.com/kth-competitive-programming/kactl/
template<class T>
struct RMQ {
	T fn(T a, T b) {return max(a, b); }
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
			jmp.emplace_back(SZ(V) - pw * 2 + 1);
			rep(j,0,SZ(jmp[k]))
				jmp[k][j] = fn(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) { b++; // [a,b]
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return fn(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

// updated RMQ with template function
template<class T, const T& (*fn)(const T&, const T&)>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
			jmp.emplace_back(SZ(V) - pw * 2 + 1);
			rep(j,0,SZ(jmp[k]))
				jmp[k][j] = fn(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) { b++; // [a,b]
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return fn(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
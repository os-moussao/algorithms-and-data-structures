// task: https://cses.fi/problemset/task/1643
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define endl '\n'

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vb;

#define MP(x, y) make_pair(x, y)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define YESORNO(x) cout << (x? "YES\n": "NO\n")
#define MAXVEC(vec) *max_element(ALL(vec))
#define MINVEC(vec) *min_element(ALL(vec))
#define getunique(vec) {sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());}

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vi arr(n);
	int past = 0, mx = -1e18;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] + past > arr[i]) arr[i] += past;
		past = arr[i];
		ckmax(mx, arr[i]);
	}
	cout << mx << endl;
}
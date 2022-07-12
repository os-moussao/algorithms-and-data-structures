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
#define popcount(x) __builtin_popcountll(x);

template<class T> bool ckmin(T& a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T b) { return a < b ? a = b, 1 : 0; }
template<class T> bool ft_swap(T &mn, T &mx) {return mn > mx? (swap(mn, mx), 1): 0;}

// Fenwick Tree geeksforgeeks
struct node {
    int pos;
    int l;
    int r;
    int val;
};

bool comp(node a, node b)
{
    if (a.val == b.val)
        return a.l > b.l;
    return a.val > b.val;
}

void update(int* BIT, int n, int idx)
{
    while (idx <= n) {
        BIT[idx]++;
        idx += idx & (-idx);
    }
}

int query(int* BIT, int idx)
{
    int ans = 0;
    while (idx) {
        ans += BIT[idx];
 
        idx -= idx & (-idx);
    }
    return ans;
}

int answer = 0;

void solveQuery(int arr[], int n, int QueryL[],
                int QueryR[], int QueryK[], int q)
{
    node a[n + q + 1];

    for (int i = 1; i <= n; ++i) {
        a[i].val = arr[i - 1];
        a[i].pos = 0;
        a[i].l = 0;
        a[i].r = i;
    }

    for (int i = n + 1; i <= n + q; ++i) {
        a[i].pos = i - n;
        a[i].val = QueryK[i - n - 1];
        a[i].l = QueryL[i - n - 1];
        a[i].r = QueryR[i - n - 1];
    }

    sort(a + 1, a + n + q + 1, comp);
    
	int BIT[n + 1];
    memset(BIT, 0, sizeof(BIT));
    int ans[q + 1];
    
	for (int i = 1; i <= n + q; ++i) {
        if (a[i].pos != 0) {
            int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);
            ans[a[i].pos] = cnt;
        }
        else {
            update(BIT, n, a[i].r);
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << endl;
		answer += ans[i];
    }
}


void solve()
{
	int n; cin >> n;
	vi a(n);
	vpi aa;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > a[i]) aa.push_back({a[i], i});
	}
	n = aa.size();
	if (!n) {
		cout << 0 << endl;
	}
	int arr[n];
	int q[n];
	int l[n];
	int r[n];
	for (int i = 0; i < n; i++) {
		arr[i] = aa[i].first;
		l[i] = i+2;
		r[i] = n;
		q[i] = arr[i];
	}
	answer = 0;
	solveQuery(arr, n, l, r, q, n-1);
	cout << answer << endl;
}

void preprocessing() {}

bool MULTY_TEST_CASES = 1;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(20);
	cout << fixed;

	preprocessing();

	int t = 1;
	if (MULTY_TEST_CASES) cin >> t;

	while (t--) {
		solve();
	}
}
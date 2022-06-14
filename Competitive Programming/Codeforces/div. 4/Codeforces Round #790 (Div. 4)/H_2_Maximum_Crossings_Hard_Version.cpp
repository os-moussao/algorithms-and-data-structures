#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

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

vector<int> merge(vector<int>& v1, vector<int>& v2)
{
    int i = 0, j = 0;
    vector<int> v;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] <= v2[j]) {
            v.push_back(v1[i]);
            i++;
        }
        else {
            v.push_back(v2[j]);
            j++;
        }
    }
    for (int k = i; k < v1.size(); k++)
        v.push_back(v1[k]);
    for (int k = j; k < v2.size(); k++)
        v.push_back(v2[k]);
    return v;
}

void buildTree(vector<int>* tree, int* arr,
               int index, int s, int e)
{
    if (s == e) {
        tree[index].push_back(arr[s]);
        return;
    }
    int mid = (s + e) / 2;
    buildTree(tree, arr, 2 * index, s, mid);
    buildTree(tree, arr, 2 * index + 1, mid + 1, e);
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}
int query(vector<int>* tree, int index, int s,
          int e, int l, int r, int k)
{
    if (r < s || l > e)
        return 0;
    if (s >= l && e <= r) {
        return (tree[index].size()
                - (lower_bound(tree[index].begin(),
                               tree[index].end(), k)
                   - tree[index].begin()));
    }
    int mid = (s + e) / 2;
    return (query(tree, 2 * index, s,
                  mid, l, r, k)
            + query(tree, 2 * index + 1, mid + 1,
                    e, l, r, k));
}

void solve()
{
	int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector <int>segtree[4*n + 1];
    buildTree(segtree, arr, 1, 0, n-1);
    int ans=  0;
    for (int i = 1; i < n; i++) {
        ans += query(segtree, 1, 0, n-1, 0, i-1, arr[i]);
    }
    cout << ans << endl;
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int mergeSort(vector<int>::iterator b, vector<int>::iterator e) {
	if (e-b==1) return 0;
	int mid = (e-b)/2;
	int inv = mergeSort(b, b+mid) + mergeSort(b+mid, e);
	vector<int> tmp(e-b);
	int i,j,k;
	for (i=0,j=mid,k=0; i < mid && j < e-b; k++) {
		if (b[i] <= b[j]) {
			tmp[k]=b[i++];
		} else {
			tmp[k]=b[j++];
			inv += mid-i;
		}
	}
	while (i < mid) tmp[k++]=b[i++];
	while (b+j != e) tmp[k++]=b[j++];
	for (i=0;b+i != e; i++) {
		b[i]=tmp[i];
	}
	return inv;
}

int inv(vector<int> a) {
	return mergeSort(a.begin(), a.end());
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int &i: a) cin >> i;
	cout << inv(a) << endl;
}
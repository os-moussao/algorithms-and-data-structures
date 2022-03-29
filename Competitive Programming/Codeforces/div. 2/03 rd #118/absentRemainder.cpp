#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define int long long
#define double long double

#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

#define vi vector<int>

vector<int> dividors(int n)
{
    vector<int> v;
	int sq = sqrt(n);
 
    for (int i = 1; i <= sq; i++)
	{
        if (n % i == 0)
		{
            if (n / i == i)
                v.push_back(i);
            else
			{
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    return v;
}

void solve()
{
	int n;
	cin >> n;

	int arr[n];
	REP(i, n) cin >> arr[i];
	sort(arr, arr + n);

	int y = arr[0];
	int i = 1;
	int count = 0;
	while (i < n && count < n / 2){
		cout << arr[i] << ss << arr[0] << nn;
		count++;
		i++;
	}
}

int32_t main()
{
	int t;

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

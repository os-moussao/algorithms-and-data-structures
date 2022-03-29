#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define int long long
#define double long double

#define REP(i, n) for(int i = 0; i < n; i++)
#define nn '\n'
#define ss ' '

const int MOD = 1e9 + 7;

void solve()
{
	int n, m;
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

// src: geeksforgeeks
void printSubArrays(vector<int> arr, int start, int end)
{
    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;

    // Increment the end point and start from 0
    else if (start > end)
        printSubArrays(arr, 0, end + 1);

    // Print the subarray and increment the starting point
    else
    {
        cout << "[";
        for (int i = start; i < end; i++){
            cout << arr[i] << ", ";
        }

        cout << arr[end] << "]" << endl;
        printSubArrays(arr, start + 1, end);
    }

    return;
}

// generating all sub sequences
int32_t main()
{
	int a[4] = {1, 2, 3, 4};

	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			for (int k = i; k <= j; k++)
			{
				cout << a[k] << ss;
			}
			cout << nn;
		}
	}

	/*
	vector<int> arr = {1, 2, 3, 4};
	printSubArrays(arr, 0, 0);
	*/
}


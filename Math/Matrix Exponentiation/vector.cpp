
//
// learning vectors in c++
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> nums;

	nums.push_back(10);

	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << '\n';


	/*
	for (int n : nums)
		cout << n << '\n';
		*/
}

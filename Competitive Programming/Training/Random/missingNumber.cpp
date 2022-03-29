// https://leetcode.com/problems/missing-number/
class Solution {
public:
    int xorN(int n) {
         if (n % 4 == 0)
            return n;
 
          if (n % 4 == 1)
            return 1;
 
          if (n % 4 == 2)
            return n + 1;
 
           return 0;
    }
    
    int missingNumber(vector<int>& nums) {
        int res, cmp = xorN(nums.size());
        res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return (cmp ^ res);
    }
};

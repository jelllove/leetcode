class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Method 1: using the total amount to find out the missed number
        /*
        int total = int(double(nums.size() + 1) * (double(nums.size()) / 2.0));
        
        int sum = 0;
        for (int &n : nums)
        {
            sum += n;
        }
        
        return total - sum;
        */

       //Method 2: Using the xor method to find out the missed number
       int ans = 0;
        
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            ans ^= nums[i];
            ans ^= idx++;
        }
        
        ans ^= idx;
        
        return ans;
    }
};
class Solution {
public:

    int rob(vector<int>& nums) {
        //Method 1: Brute force
        //这样不能成功，因为像  2, 1, 1, 2这样的输入的话，输出是3，但是最优解是4
        /*
        int dp1 = 0;
        int dp2 = 0;
        
        for (int i  = 0; i < nums.size(); ++i)
        {
            if ((i & 0x1) == 0x1)
            {
                dp1 += nums[i];
            }
            else
            {
                dp2 += nums[i];
            }
        }
        
        return max(dp1, dp2);
        */
        
        
        //Method 2: Dynamic programming
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);
        
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); ++i)
        {
            //动态方程  dp[i] = max(这次不抢使用上一个的，  这次抢了+上上次抢的);
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
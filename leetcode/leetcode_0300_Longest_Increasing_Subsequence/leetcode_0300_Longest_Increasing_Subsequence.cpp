class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //Method 1: DP 动态规划，从0开始计算
        //动态方程  dp[i] = max(dp[i], dp[j = (nums[0..i-1] < nums[i])] + 1);
        //简单来说，就是每一个i，都要找前面从0到i-1之间的所有数，看看它是不是小于nums[i]，
        //如果是的话，那看一个这个数对应的dp值是多少，然后利用当前的dp[i]与它dp[] + 1比较
        //默认所有的dp都是1，因为每一个数，最少有自己
        /*
        int n = nums.size();
        if (n <= 1)
            return 1;
        
        vector<int> dp(n, 1);
        
        int ans = 1;
        
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                //如果小于，相当于是增长了，那就可以算一下了
                if (nums[j] < nums[i])
                {
                    //为什么要用max，因为在0 到j的过程中，可能有多个增长的，所以不能只用一个值
                    dp[i] = max(dp[i], dp[j] + 1);
                    
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
        */
        
        //Method 2: DP，动态规划，从后向前去统计
        int n = nums.size();
        if (n <= 1)
            return 1;
        
        vector<int> dp(n, 1);
        
        int ans = 1;
        
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                //如果大于，相当于是增长了，那就可以算一下了
                if (nums[j] > nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
        
        
        
    }
};
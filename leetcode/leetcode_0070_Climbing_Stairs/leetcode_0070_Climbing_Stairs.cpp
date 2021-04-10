class Solution {
public:
    
    //Method 1:利用递归一个个的加上去，最后找到解
    //如果数目少的话，可行，但是如果数目大的话，那就不行了
    /*
    int count(int n)
    {
        int res[3] = {0, 1, 2};
        if (n <= 2)
            return res[n];
        else
            return count(n - 1) + count(n - 2);
    }
    */
    
    
    
    int climbStairs(int n) {
        //Method 1
        //return count(n);
        
        //Method 2: 使用动态规划，好理解，因为这个题目就是一个斐波那契数列
        //所以 dp[i] = dp[i - 1] + dp[i - 2];
        //而已知 dp[0] = 1, dp[1] = 1; dp[2] = 2;
        /*if (n < 2)
            return 1;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        //因为是N个台阶，所以要<=n
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
        */
        
        //Method 3: 与上面的相同，但是只要用三个元素的数组
        if (n < 2)
            return 1;
        
        vector<int> dp(3, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 0;
        
        //因为是N个台阶，所以要<=n
        for (int i = 2; i <= n; ++i)
        {
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        
        return dp[2];
        
        
    }
};
class Solution {
    
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        //定义一个和总和一样大的数组，一开始默认都是-1，就是没办法找钱的
        vector<int> dp(amount + 1, -1);
        
        //0元的时候，找回的方法肯定是0
        dp[0] = 0;
        
        //然后从1元开始，分析有没有找钱方案
        for (int i = 1; i <= amount; ++i)
        {
            //把所有可以用来换的钱的单位遍历一遍
            for (auto &c : coins)
            {
                //如果当前的钱的面值是大于总的金额的
                //那肯定没有办法换
                if (c > i)
                    continue;
                
                //如果conin的面值小于或等于总的金额
                //那可以看一下总金额减掉了面值后，剩下的钱是不是已经方案了
                if (dp[i - c] != -1)
                {
                    //如果dp[i]还没有被定义过，直接更新
                    if (dp[i] == -1 || dp[i] > dp[i - c] + 1)
                        dp[i] = dp[i - c] + 1;
                }
            }
        }
        
        return dp[amount];
    }
};
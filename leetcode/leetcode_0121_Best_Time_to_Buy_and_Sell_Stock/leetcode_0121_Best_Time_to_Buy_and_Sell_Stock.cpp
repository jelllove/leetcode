class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        
        //Method 1: 最简单的方式，就一个个去找，如果找到了一个比之前的值大的，那就当成是卖出价，然后算一下
        if (prices.size() <= 1)
            return 0;
        int profit = 0;
        int minValue = prices[0];
        
        for (int i = 1; i < prices.size(); ++i)
        {
            if (minValue > prices[i])
            {
                minValue = prices[i];
                continue;
            }
            else if (profit < (prices[i] - minValue))
            {
                profit = (prices[i] - minValue);
            }
            
            //使用这个的话，有一个continue就不能用了
            //profit = max(profit, prices[i] - minValue);
            //minValue = min(minValue, prices[i]);
        }
        return profit;
      
    }
    
};
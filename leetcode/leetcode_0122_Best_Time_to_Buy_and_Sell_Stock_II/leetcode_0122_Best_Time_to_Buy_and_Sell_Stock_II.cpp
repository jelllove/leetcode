class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int start = std::numeric_limits<int>::max();
        int profit = 0;
        
        //其实只要低的时候买入，高的时候卖出，然后如果卖出的时候，也当成是买入的话，就可以了
        for (auto &p : prices)
        {
            if (p > start)
                profit += (p - start);
            start = p;
        }
        
        return profit;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
                maxProfit += (prices[i] - prices[i - 1]);
        }
        
        return maxProfit;
    }
};
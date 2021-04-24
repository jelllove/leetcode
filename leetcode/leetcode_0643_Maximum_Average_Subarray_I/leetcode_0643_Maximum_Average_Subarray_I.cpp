class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0.0;
        
        double curSum = 0.0;
        //C++ 11后一种新的取最大最小数的方式
        double maxAvg = std::numeric_limits<double>::min();
        
        int index = 0;
        
        while (index < nums.size())
        {
            if (index < k)
            {
                //相当于把前K个数先加起来
                curSum += nums[index];
                ++index;
                if (index >= k)
                {
                    maxAvg = curSum / double(k);
                }
                continue;
                    
            }
            
            
            //加一个新的数，把最老的那个数减掉
            curSum -= nums[index - k];
            curSum += nums[index];
            //比较一下新的AVG
            maxAvg = max(maxAvg, curSum / double(k));
            
            ++index;
        }
        
        return maxAvg;
    }
};
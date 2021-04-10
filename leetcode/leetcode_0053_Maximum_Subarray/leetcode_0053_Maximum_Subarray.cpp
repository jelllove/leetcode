class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Method 1:
        /*
        int cur = 0;
        int maxValue = INT_MIN;
        
        int i = 0;
        
        while (i < nums.size())
        {
            if (cur >= 0)
            {
                cur += nums[i];
            }
            else
            {
                cur = nums[i];
            }
            
            maxValue = max(maxValue, cur);
            
            ++i;
        }
        
        return maxValue;
        */
        
        
        
        //Method 2, and more easy to understaning:
        //https://www.cnblogs.com/xiehongfeng100/p/4570082.html
        /*
        if (nums.size() <= 0)
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> globalVal(nums.size(), 0);
        vector<int> localVal(nums.size(), 0);
        
        globalVal[0] = nums[0];
        localVal[0] = nums[0];
        
        
        for (int i = 1; i < nums.size(); i++)
        {
            localVal[i] = max(localVal[i - 1] + nums[i], nums[i]);
            globalVal[i] = max(localVal[i], globalVal[i - 1]);
        }
        
        return globalVal[nums.size() - 1];
        */
        
        //Method 3, the best solution
    
        if (nums.size() <= 0)
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
        
        int globalMax = nums[0];
        int curVal = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            curVal = max(curVal + nums[i], nums[i]);
            globalMax = max(curVal, globalMax);
        }
        
        return globalMax;
        //https://www.cnblogs.com/grandyang/p/4377150.html
        
    }
};